#include "udpreceiver.h"
#include "vision_detection.pb.h"
#include "time_stamp.pb.h"
#include <thread>

UDPReceiver* UDPReceiver::_instance = 0;

namespace {
    std::thread* _thread = nullptr;
    const int VISION_PORT = 23333;
    QFile* file = nullptr;
    const QHostAddress TIME_ADDRESS = QHostAddress("233.233.233.233");
    const int TIME_PORT = 12345;
}

UDPReceiver::UDPReceiver()
{
    receiver = new QUdpSocket();
    sender = new QUdpSocket();
    if(receiver->bind(QHostAddress::AnyIPv4, VISION_PORT, QUdpSocket::ShareAddress)){
        qDebug() << "BIND SUCCESS";
        _thread = new std::thread([ = ] {readDatagrams();});
        _thread->detach();
    }
    else
        qDebug() << "BIND ERROR!!!";
}

UDPReceiver::~UDPReceiver(){
    receiver->abort();
    sender->abort();
    delete _thread;
    if(file->isOpen())
        file->close();
}

UDPReceiver* UDPReceiver::instance(){
    if(_instance == 0)
        _instance = new UDPReceiver();
    return _instance;
}

void UDPReceiver::readDatagrams(){
    // open file
    QDateTime time = QDateTime::currentDateTime();
    QString timeStr = time.toString("yyyy-MM-dd  hh-mm-ss");
    QString filename = QString("../Data/") + timeStr + QString(".txt");
    file = new QFile(filename);
    if(!file->open(QIODevice::ReadWrite)){
        qDebug() << "OPEN FILE ERROR!!!";
        return;
    }
    // record data
    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        // current time
        QDateTime UTC(QDateTime::currentDateTimeUtc());
        qint64 currentTime = UTC.toMSecsSinceEpoch();
//        QDateTime local(UTC.toLocalTime());
//        qDebug() << "UTC time is:" << UTC.toMSecsSinceEpoch();
//        qDebug() << "Local time is:" << local.toString();

        // send current time
        TimeStamp msg;
        msg.set_time(currentTime);
        int msg_size = msg.ByteSize();
        QByteArray msg_data(msg_size, 0);
        msg.SerializeToArray(msg_data.data(), msg_data.size());
        sender->writeDatagram(msg_data, msg_size, TIME_ADDRESS, TIME_PORT);

        while(receiver->hasPendingDatagrams()){
            QByteArray datagram;
            datagram.resize(receiver->pendingDatagramSize());
            receiver->readDatagram(datagram.data(), datagram.size());
            // Parse from datagram
            Vision_DetectionFrame vision;
            vision.ParseFromArray(datagram, datagram.size());

            // Read blue robot info
            int blue_size = vision.robots_blue_size();
            for (int i = 0; i < blue_size; i++){
                int robot_id = vision.robots_blue(i).robot_id();
                QString content = QString("%1 %2 %3 %4\n").arg(currentTime).arg(robot_id).arg(vision.robots_blue(i).x()/10).arg(vision.robots_blue(i).y()/10);
                qDebug() << file->write(content.toLatin1(), content.length());
            }
            // Read yellow robot info
//            int yellow_size = vision.robots_yellow_size();
//            for (int i = 0; i < yellow_size; i++){
//                int robot_id = vision.robots_yellow(i).robot_id();
//            }
        }
    }
}
