#ifndef BASEPARSER_H
#define BASEPARSER_H

/**
 * @file    BaseParser.h
 * @date    2018-06-21
 * @author  sauber
 * @brief   The BaseParser class header file
 */

#include <QObject>
#include "Parcel.h"

class BaseParser: public QObject
{
    Q_OBJECT
public:
    BaseParser(QObject *parent = nullptr);
private:
    /**
     * @brief parseBytes - parses received bytes and build from that an object of parcel which contains only data to handle
     * @param bytes
     */
    virtual void parseBytes(const QByteArray& bytes) = 0;
signals:
    /**
     * @brief onParcelBuilt - signal which will be emited if a parcel was built from received bytes
     * @param parcel
     */
    void onParcelBuilt(Parcel& parcel);
public slots:
    /**
     * @brief onDataReceived - slot which handles received data from communication interface
     * @param bytes - received bytes
     */
    void onDataReceived(const QByteArray& bytes);

};

#endif // BASEPARSER_H
