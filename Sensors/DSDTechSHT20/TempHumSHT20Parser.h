#ifndef TEMPHUMSHT20PARSER_H
#define TEMPHUMSHT20PARSER_H

#include "ProtocolParser/BaseParser.h"

/**
 * @file    TempHumSHT20Parser.h
 * @date    2018-06-21
 * @author  sauber
 * @brief   The TempHumSHT20Parser class header file. This class will handle received bytes from sensor
 * DSDTech SHT20. The format of received messages should look like this: "\r\nPAYLOAD BYTES\r\nPAYLOAD BYTES\r\n"
 */

class TempHumSHT20Parser : public BaseParser
{
public:
    TempHumSHT20Parser(QObject *parent = nullptr);
private:
    enum ParserState
    {
        WAIT_CR_CHAR,
        WAIT_LF_CHAR,
        PROCESS_DATA
    };
    Parcel mParcel;
    ParserState mParserState = WAIT_CR_CHAR;
protected:
    /**
     * @brief parseBytes - parses received bytes and build from that an object of parcel which contains only data to handle
     * @param bytes
     */
    virtual void parseBytes(const QByteArray& bytes);
};

#endif // TEMPHUMSHT20PARSER_H
