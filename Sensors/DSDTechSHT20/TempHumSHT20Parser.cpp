#include "TempHumSHT20Parser.h"

TempHumSHT20Parser::TempHumSHT20Parser(QObject *parent) : BaseParser(parent)
{

}

void TempHumSHT20Parser::parseBytes(const QByteArray &bytes)
{
    // Format of received messages should look like this
    // "\r\nPAYLOAD BYTES\r\nPAYLOAD BYTES\r\n"

    for (int i = 0; i < bytes.length(); i++)
    {
        switch(mParserState)
        {
            case (WAIT_CR_CHAR):
                if (bytes[i] == '\r')
                    mParserState = WAIT_LF_CHAR;
                break;
            case (WAIT_LF_CHAR):
                if (bytes[i] == '\n')
                {
                    mParserState = PROCESS_DATA;
                    mParcel.reset();
                }
                break;
            case (PROCESS_DATA):
                if (bytes[i] != '\r')
                    mParcel << bytes[i];
                else
                {
                    emit onParcelBuilt(mParcel);
                    mParserState = WAIT_LF_CHAR;
                }
                break;
        }
    }
}
