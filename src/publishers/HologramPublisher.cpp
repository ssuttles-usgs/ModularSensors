/*
 *HologramPublisher.cpp
 *This file is part of the EnviroDIY modular sensors library for Arduino
 *
 *Initial library developement done by Sara Damiano (sdamiano@stroudcenter.org).
 *
 *This file is for the EnviroDIY logging functions - ie, sending JSON data to
 * http://data.enviroDIY.org
*/

#include "HologramPublisher.h"


// ============================================================================
//  Functions for the EnviroDIY data portal receivers.
// ============================================================================

// Constant values for post requests
// I want to refer to these more than once while ensuring there is only one copy in memory
const char *HologramPublisher::postEndpoint = "/api/1/csr/data/";
const char *HologramPublisher::hologramHost = "cloudsocket.hologram.io";
const int HologramPublisher::hologramPort = 9999;
const char *HologramPublisher::authHeader = "\r\nAuthorization: Basic ";
// const unsigned char *HologramPublisher::cacheHeader = "\r\nCache-Control: no-cache";
// const unsigned char *HologramPublisher::connectionHeader = "\r\nConnection: close";
const char *HologramPublisher::contentLengthHeader = "\r\nContent-Length: ";
const char *HologramPublisher::contentTypeHeader = "\r\nContent-Type: application/json\r\n\r\n";

const char *HologramPublisher::deviceIdTag = "{\"deviceid\":";
const char *HologramPublisher::bodyTag = ",\"body\":\"";
// const char *HologramPublisher::deviceId = "511833"; // this is for the Grizzly Bay one (salmon-panda)
const char *HologramPublisher::deviceId = "541830"; // this is for the Bellingham one (tan-zebra)

// Constructors
HologramPublisher::HologramPublisher()
  : dataPublisher()
{
    // MS_DBG(F("dataPublisher object created"));
}
HologramPublisher::HologramPublisher(Logger& baseLogger,
                                 uint8_t sendEveryX, uint8_t sendOffset)
  : dataPublisher(baseLogger, sendEveryX, sendOffset)
{
    // MS_DBG(F("dataPublisher object created"));
}
HologramPublisher::HologramPublisher(Logger& baseLogger, Client *inClient,
                                 uint8_t sendEveryX, uint8_t sendOffset)
  : dataPublisher(baseLogger, inClient, sendEveryX, sendOffset)
{
    // MS_DBG(F("dataPublisher object created"));
}
HologramPublisher::HologramPublisher(Logger& baseLogger,
                                 const char *registrationToken,
                                 const char *samplingFeatureUUID,
                                 uint8_t sendEveryX, uint8_t sendOffset)
  : dataPublisher(baseLogger, sendEveryX, sendOffset)
{
    setToken(registrationToken);
    _baseLogger->setSamplingFeatureUUID(samplingFeatureUUID);
    // MS_DBG(F("dataPublisher object created"));
}
HologramPublisher::HologramPublisher(Logger& baseLogger, Client *inClient,
                                 const char *registrationToken,
                                 const char *samplingFeatureUUID,
                                 uint8_t sendEveryX, uint8_t sendOffset)
  : dataPublisher(baseLogger, inClient, sendEveryX, sendOffset)
{
    setToken(registrationToken);
    _baseLogger->setSamplingFeatureUUID(samplingFeatureUUID);
    // MS_DBG(F("dataPublisher object created"));
}
// Destructor
HologramPublisher::~HologramPublisher(){}


void HologramPublisher::setToken(const char *registrationToken)
{
    _registrationToken = registrationToken;
    // MS_DBG(F("Registration token set!"));
}


// Calculates how long the JSON will be
uint16_t HologramPublisher::calculateJsonSize()
{
    uint16_t jsonLength = 12;  // {"deviceid":
    jsonLength += 6;  // six-digit device ID
    jsonLength += 10;  // ","body":"
    jsonLength += 25;  // markedISO8601Time
    jsonLength += 2;  //  ",
    for (uint8_t i = 0; i < _baseLogger->getArrayVarCount(); i++)
    {
        jsonLength += 1;  //  "
        jsonLength += 36;  // variable UUID
        jsonLength += 2;  //  ":
        jsonLength += _baseLogger->getValueStringAtI(i).length();
        if (i + 1 != _baseLogger->getArrayVarCount())
        {
            jsonLength += 1;  // ,
        }
    }
    jsonLength += 1;  // }

    return jsonLength;
}


/*
// Calculates how long the full post request will be, including headers
uint16_t HologramPublisher::calculatePostSize()
{
    uint16_t postLength = 31;  // "POST /api/data-stream/ HTTP/1.1"
    postLength += 28;  // "\r\nHost: data.envirodiy.org"
    postLength += 11;  // "\r\nTOKEN: "
    postLength += 36;  // registrationToken
    // postLength += 27;  // "\r\nCache-Control: no-cache"
    // postLength += 21;  // "\r\nConnection: close"
    postLength += 20;  // "\r\nContent-Length: "
    postLength += String(calculateJsonSize()).length();
    postLength += 42;  // "\r\nContent-Type: application/json\r\n\r\n"
    postLength += calculateJsonSize();
    return postLength;
}
*/


// This prints a properly formatted JSON for EnviroDIY to an Arduino stream
void HologramPublisher::printSensorDataJSON(Stream *stream)
{
    stream->print(deviceIdTag);
    // stream->print(_baseLogger->getSamplingFeatureUUID()); // deviceId is in here now.
    stream->print(deviceId);
    stream->print(bodyTag);
    stream->print(_baseLogger->formatDateTime_ISO8601(Logger::markedEpochTime));
    stream->print(F("\","));

    for (uint8_t i = 0; i < _baseLogger->getArrayVarCount(); i++)
    {
        stream->print('"');
        stream->print(_baseLogger->getVarUUIDAtI(i));
        stream->print(F("\":"));
        stream->print(_baseLogger->getValueStringAtI(i));
        if (i + 1 != _baseLogger->getArrayVarCount())
        {
            stream->print(',');
        }
    }

    stream->print('}');
}


// This prints a fully structured post request for EnviroDIY to the
// specified stream.
void HologramPublisher::printEnviroDIYRequest(Stream *stream)
{
    // Stream the HTTP headers for the post request
    stream->print(postHeader);
    stream->print(postEndpoint);
    stream->print(HTTPtag);
    stream->print(hostHeader);
    stream->print(hologramHost);
    stream->print(authHeader);
    stream->print(_registrationToken);
    // stream->print(cacheHeader);
    // stream->print(connectionHeader);
    stream->print(contentLengthHeader);
    stream->print(calculateJsonSize());
    stream->print(contentTypeHeader);

    // Stream the JSON itself
    printSensorDataJSON(stream);
}


// A way to begin with everything already set
void HologramPublisher::begin(Logger& baseLogger, Client *inClient,
                               const char *registrationToken,
                               const char *samplingFeatureUUID)
{
    setToken(registrationToken);
    dataPublisher::begin(baseLogger, inClient);
    _baseLogger->setSamplingFeatureUUID(samplingFeatureUUID);
}
void HologramPublisher::begin(Logger& baseLogger,
                               const char *registrationToken,
                               const char *samplingFeatureUUID)
{
    setToken(registrationToken);
    dataPublisher::begin(baseLogger);
    _baseLogger->setSamplingFeatureUUID(samplingFeatureUUID);
}


// This utilizes an attached modem to make a TCP connection to the
// EnviroDIY/ODM2DataSharingPortal and then streams out a post request
// over that connection.
// The return is the http status code of the response.
// int16_t HologramPublisher::postDataEnviroDIY(void)
int16_t HologramPublisher::publishData(Client *_outClient)
{
    // Create a buffer for the portions of the request and response
    char tempBuffer[37] = "";
    uint16_t did_respond = 0;

    MS_DBG(F("RUNNING IN HOLOGRAM"));

    MS_DBG(F("Outgoing JSON size:"), calculateJsonSize());

    // Open a TCP/IP connection to the Enviro DIY Data Portal (WebSDL)
    MS_DBG(F("Connecting client"));
    MS_START_DEBUG_TIMER;
    if (_outClient->connect(hologramHost, hologramPort))
    {
        MS_DBG(F("Client connected after"), MS_PRINT_DEBUG_TIMER, F("ms\n"));

        strcpy(txBuffer, "{\"k\":\"");
        strcat(txBuffer, _registrationToken);
        strcat(txBuffer, "\",\"d\":\"");
        strcat(txBuffer, "time,");
        _baseLogger->formatDateTime_ISO8601(Logger::markedEpochTime).toCharArray(tempBuffer, 37);
        strcat(txBuffer, tempBuffer);
        strcat(txBuffer, ",");
        
        // copy the initial post header into the tx buffer
        // strcpy(txBuffer, postHeader);
        // strcat(txBuffer, postEndpoint);
        // strcat(txBuffer, HTTPtag);

        // // add the rest of the HTTP POST headers to the outgoing buffer
        // // before adding each line/chunk to the outgoing buffer, we make sure
        // // there is space for that line, sending out buffer if not
        // if (bufferFree() < 28) printTxBuffer(_outClient);
        // strcat(txBuffer, hostHeader);
        // strcat(txBuffer, hologramHost);

        // if (bufferFree() < 25) printTxBuffer(_outClient);
        // strcat(txBuffer, authHeader);
        // if (bufferFree() < 52) printTxBuffer(_outClient);
        // strcat(txBuffer, _registrationToken);

        // if (bufferFree() < 27) printTxBuffer(_outClient);
        // strcat(txBuffer, cacheHeader);

        // if (bufferFree() < 21) printTxBuffer(_outClient);
        // strcat(txBuffer, connectionHeader);

        // if (bufferFree() < 26) printTxBuffer(_outClient);
        // strcat(txBuffer, contentLengthHeader);
        // itoa(calculateJsonSize(), tempBuffer, 10);  // BASE 10
        // strcat(txBuffer, tempBuffer);

        // if (bufferFree() < 42) printTxBuffer(_outClient);
        // strcat(txBuffer, contentTypeHeader);

        // // put the start of the JSON into the outgoing response_buffer
        // if (bufferFree() < 21) printTxBuffer(_outClient);
        // strcat(txBuffer, deviceIdTag);

        // if (bufferFree() < 36) printTxBuffer(_outClient);
        // strcat(txBuffer, deviceId);

        // if (bufferFree() < 42) printTxBuffer(_outClient);
        // strcat(txBuffer, bodyTag);
        // _baseLogger->formatDateTime_ISO8601(Logger::markedEpochTime).toCharArray(tempBuffer, 37);
        // strcat(txBuffer, tempBuffer);
        // txBuffer[strlen(txBuffer)] = '"';
        // txBuffer[strlen(txBuffer)] = '}';

        for (uint8_t i = 0; i < _baseLogger->getArrayVarCount(); i++)
        {
            // Once the buffer fills, send it out
            if (bufferFree() < 47) printTxBuffer(_outClient);

            _baseLogger->getVarUUIDAtI(i).toCharArray(tempBuffer, 37);
            strcat(txBuffer, tempBuffer);
            strcat(txBuffer, ",");
            _baseLogger->getValueStringAtI(i).toCharArray(tempBuffer, 37);
            strcat(txBuffer, tempBuffer);
            if (i + 1 != _baseLogger->getArrayVarCount())
            {
                txBuffer[strlen(txBuffer)] = ',';
            }
        }

        strcat(txBuffer, "\"}");

        // Send out the finished request (or the last unsent section of it)
        printTxBuffer(_outClient, true);

        // Wait 10 seconds for a response from the server
        uint32_t start = millis();
        while ((millis() - start) < 10000L && _outClient->available() < 12)
        {delay(10);}

        // Read only the first 12 characters of the response
        // We're only reading as far as the http code, anything beyond that
        // we don't care about.
        did_respond = _outClient->readBytes(tempBuffer, 12);

        // Close the TCP/IP connection
        MS_DBG(F("Stopping client"));
        MS_RESET_DEBUG_TIMER;
        _outClient->stop();
        MS_DBG(F("Client stopped after"), MS_PRINT_DEBUG_TIMER, F("ms"));
    }
    else
    {
        PRINTOUT(F("\n -- Unable to Establish Connection to EnviroDIY Data Portal --"));
    }

    // Process the HTTP response
    int16_t responseCode = 0;
    if (did_respond > 0)
    {
        char responseCode_char[4];
        for (uint8_t i = 0; i < 3; i++)
        {
            responseCode_char[i] = tempBuffer[i+9];
        }
        responseCode = atoi(responseCode_char);
        PRINTOUT(F("RESPONSECHAR"));
        PRINTOUT(responseCode_char);
    }
    else
    {
        responseCode=504;
    }

    PRINTOUT(F("-- Response Code --"));
  
    PRINTOUT(responseCode);

    return responseCode;
}