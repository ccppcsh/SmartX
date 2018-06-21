#ifndef BASEPARCELHANDLER_H
#define BASEPARCELHANDLER_H

#include <QObject>
/**
 * @file    BaseParcelHandler.h
 * @date    2018-06-21
 * @author  sauber
 * @brief   The BaseParcelHandler class header file
 */

class BaseParcelHandler : public QObject
{
    Q_OBJECT
public:
    BaseParcelHandler();
protected:
    /**
     * @brief handleParcel - this method handles received parcel and if this parcel was recognized, stores the received info and emits signal
     * @param parcel - received parcel to handle
     */
    virtual void handleParcel(Parcel& parcel) = 0;
signals:
    /**
     * @brief eventOccured - this signal will be emitted every time when received parcel was recognized and any information (sensors data,
     * states and etc.) was parsed and saved
     * @param eventType - type of event which occured
     */
    void eventOccured(int eventType);
public slots:
    /**
     * @brief onParcelBuilt - slot for handling of received parcel. Should be connected with signal of an object derived from BaseParser
     * @param parcel - received parcel to handle
     */
    void onParcelBuilt(Parcel& parcel);

};

#endif // BASEPARCELHANDLER_H
