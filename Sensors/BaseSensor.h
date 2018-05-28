#ifndef BASESENSOR_H
#define BASESENSOR_H

#include <QObject>

class BaseSensor : public QObject
{
    Q_OBJECT
public:
    explicit BaseSensor(QObject *parent = nullptr);
    int getValue();

signals:

public slots:
};



#endif // BASESENSOR_H
