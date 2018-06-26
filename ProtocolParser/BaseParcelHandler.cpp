#include "BaseParcelHandler.h"

BaseParcelHandler::BaseParcelHandler(QObject *parent) : QObject(parent)
{

}

void BaseParcelHandler::onParcelBuilt(const Parcel &parcel)
{
    handleParcel(parcel);
}
