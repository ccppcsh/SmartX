#ifndef BASEDEVICE_H
#define BASEDEVICE_H

#include <QObject>

class BaseDevice : public QObject
{
    Q_OBJECT
public:
    explicit BaseDevice(QObject *parent = nullptr);

signals:

public slots:
};

#endif // BASEDEVICE_H