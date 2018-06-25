#include "Parcel.h"

Parcel::Parcel()
{

}

Parcel::Parcel(const Parcel& p)
{
    mPayloadBytes = p.mPayloadBytes;
}

const QByteArray &Parcel::getBytes()
{
    return mPayloadBytes;
}

void Parcel::addByte(char dataByte)
{
    mPayloadBytes.append(dataByte);
}

void Parcel::operator<<(char dataByte)
{
    this->addByte(dataByte);
}

void Parcel::reset()
{
    mPayloadBytes.clear();
}
