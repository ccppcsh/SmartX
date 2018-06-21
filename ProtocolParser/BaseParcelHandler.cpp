#include "BaseParcelHandler.h"

BaseParcelHandler::BaseParcelHandler()
{

}

void BaseParcelHandler::onParcelBuilt(Parcel &parcel)
{
    handleParcel(parcel);
}
