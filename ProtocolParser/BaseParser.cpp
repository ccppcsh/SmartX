#include "BaseParser.h"

/**
 * @file    BaseParser.cpp
 * @date    2018-06-21
 * @author  sauber
 * @brief   The BaseParser class implementation file
 */

BaseParser::BaseParser(QObject *parent) : QObject(parent)
{

}


void BaseParser::onDataReceived(const QByteArray& bytes)
{
    this->parseBytes(bytes);
}
