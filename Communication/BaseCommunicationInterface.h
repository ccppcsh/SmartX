#ifndef BASECOMMUNICATIONINTERFACE_H
#define BASECOMMUNICATIONINTERFACE_H

#include <QObject>

class BaseCommunicationInterface : public QObject
{
    Q_OBJECT
public:
    explicit BaseCommunicationInterface(QObject *parent = nullptr);
    virtual bool connect() = 0;
    virtual bool disconnect() = 0;
    virtual bool isConnected() = 0;
    virtual int send(const QList<uint8_t>& bytes) = 0;

signals:
    // TODO: Define callback on data receiveing
    void onDataReceived(QList<uint8_t>& data);
public slots:
};

#endif // BASECOMMUNICATIONINTERFACE_H
