#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H
#include <QtNetwork>

class UDPReceiver : public QObject
{
    Q_OBJECT
public:
    UDPReceiver(QObject *parent = nullptr);
    ~UDPReceiver();
    void readDatagrams();
    Q_INVOKABLE qint64 time(){ return currentTime; }
    Q_INVOKABLE bool isRecording() { return recording; }
private:
    QUdpSocket *receiver;
    QUdpSocket *sender;
    qint64 currentTime;
    bool recording;
};


#endif // UDPRECEIVER_H
