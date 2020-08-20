/*
 *HologramPublisher.h
 *This file is part of the EnviroDIY modular sensors library for Arduino
 *
 *Initial library developement done by Sara Damiano (sdamiano@stroudcenter.org).
 *
 *This file is for the EnviroDIY logging functions - ie, sending JSON data to
 * http://data.enviroDIY.org
*/

// Header Guards
#ifndef HologramPublisher_h
#define HologramPublisher_h

// Debugging Statement
// #define MS_HOLOGRAMPUBLISHER_DEBUG

#ifdef MS_HOLOGRAMPUBLISHER_DEBUG
#define MS_DEBUGGING_STD "HologramPublisher"
#endif

// Included Dependencies
#include "ModSensorDebugger.h"
#undef MS_DEBUGGING_STD
#include "dataPublisherBase.h"


// ============================================================================
//  Functions for the EnviroDIY data portal receivers.
// ============================================================================
class HologramPublisher : public dataPublisher
{
public:
    // Constructors
    HologramPublisher();
    HologramPublisher(Logger& baseLogger,
                    uint8_t sendEveryX = 1, uint8_t sendOffset = 0);
    HologramPublisher(Logger& baseLogger, Client *inClient,
                    uint8_t sendEveryX = 1, uint8_t sendOffset = 0);
    HologramPublisher(Logger& baseLogger,
                    const char *registrationToken,
                    const char *samplingFeatureUUID,
                    uint8_t sendEveryX = 1, uint8_t sendOffset = 0);
    HologramPublisher(Logger& baseLogger, Client *inClient,
                    const char *registrationToken,
                    const char *samplingFeatureUUID,
                    uint8_t sendEveryX = 1, uint8_t sendOffset = 0);
    // Destructor
    virtual ~HologramPublisher();

    // Returns the data destination
    virtual String getEndpoint(void){return String(hologramHost);}

    // Adds the site registration token
    void setToken(const char *registrationToken);

    // Calculates how long the JSON will be
    uint16_t calculateJsonSize();
    // Calculates how long the full post request will be, including headers
    // uint16_t calculatePostSize();

    // This generates a properly formatted JSON for EnviroDIY
    void printSensorDataJSON(Stream *stream);

    // This prints a fully structured post request for WikiWatershed/EnviroDIY
    // to the specified stream.
    void printEnviroDIYRequest(Stream *stream);

    // A way to begin with everything already set
    void begin(Logger& baseLogger, Client *inClient,
               const char *registrationToken,
               const char *samplingFeatureUUID);
    void begin(Logger& baseLogger,
              const char *registrationToken,
              const char *samplingFeatureUUID);

    // This utilizes an attached modem to make a TCP connection to the
    // EnviroDIY/ODM2DataSharingPortal and then streams out a post request
    // over that connection.
    // The return is the http status code of the response.
    // int16_t postDataEnviroDIY(void);
    virtual int16_t publishData(Client *_outClient);

protected:

    // portions of the POST request
    static const char *postEndpoint;
    static const char *hologramHost;
    static const int hologramPort;
    static const char *authHeader;
    // static const char *cacheHeader;
    // static const char *connectionHeader;
    static const char *contentLengthHeader;
    static const char *contentTypeHeader;

    // portions of the JSON
    static const char *deviceIdTag;
    static const char *bodyTag;
    static const char *deviceId;

private:
    // Tokens and UUID's for EnviroDIY
    const char *_registrationToken;
};

#endif  // Header Guard