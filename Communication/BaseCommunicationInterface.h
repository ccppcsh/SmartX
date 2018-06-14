#ifndef BASECOMMUNICATIONINTERFACE_H
#define BASECOMMUNICATIONINTERFACE_H

#include <QObject>

class BaseCommunicationInterface : public QObject
{
    Q_OBJECT
public:
    enum ErrorCode{
        OK = 0,
        INTERFACE_NOT_AVAILABLE = 1,
        WRONG_INTERFACE_PARAMETERS = 2,
        ERROR_BY_OPEN_PORT = 3,
        INTERFACE_IS_NOT_CONNECTED = 4,
        ERROR_BY_SENDING_DATA = 5
    };
    explicit BaseCommunicationInterface(QObject *parent = nullptr);
    virtual ErrorCode connect() = 0;
    virtual ErrorCode disconnect() = 0;
    virtual bool isConnected() = 0;
    virtual ErrorCode send(const QByteArray& bytes) = 0;

signals:
    // TODO: Define callback on data receiveing
    void onDataReceived(const QByteArray& data);
public slots:
};

#endif // BASECOMMUNICATIONINTERFACE_H
