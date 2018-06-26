#ifndef PARCEL_H
#define PARCEL_H

#include <QObject>
/**
 * @file    Parcel.h
 * @date    2018-06-21
 * @author  sauber
 * @brief   The Parcel class header file
 */

class Parcel
{
public:
    Parcel();
    Parcel(const Parcel& p);
    /**
     * @brief getBytes - returns a reference on array with received payload bytes
     * @return reference on QByteArray with received bytes
     */
    const QByteArray& getBytes() const;
    /**
     * @brief addByte stores received byte of payload
     * @param dataByte - received byte
     */
    void addByte(char dataByte);
    /**
     * @brief operator << stores received byte of payload
     * @param dataByte - received byte
     */
    void operator<<(char dataByte);
    /**
     * @brief reset - resets stored payload bytes
     */
    void reset();
private:
    QByteArray mPayloadBytes;
};
Q_DECLARE_METATYPE(Parcel)
#endif // PARCEL_H
