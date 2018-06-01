#ifndef BASECOMMUNICATIONINTERFACE_H
#define BASECOMMUNICATIONINTERFACE_H

#include <QObject>

class BaseCommunicationInterface : public QObject
{
    Q_OBJECT
public:
    explicit BaseCommunicationInterface(QObject *parent = nullptr);
    virtual void connect() = 0;
    virtual void disconnect() = 0;
    virtual void isConnected() = 0;
    virtual void send(const QList<uint8_t>& bytes) = 0;

signals:
    // TODO: Define callback on data receiveing
    void onDataReceived(QList<uint8_t>& data);
public slots:
};

#endif // BASECOMMUNICATIONINTERFACE_H
