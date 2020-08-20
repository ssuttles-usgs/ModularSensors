/*
 *GillGMX200.h
 *This file is part of the EnviroDIY modular sensors library for Arduino
 *
 *Initial library developement done by Sara Damiano (sdamiano@stroudcenter.org).
 *
 *This file is based on DecagonCTD.h
 *It is dependent on the EnviroDIY SDI-12 library and the SDI12Sensors super class.
 *
 * 
 * Dm Direction average, Sm Speed average, Ta Air temperature, Ua Air humidity, Pa Air pressure, Rc Rain amount, Th Heating temperature, Vh Heating voltage
*/

// Header Guards
#ifndef GillGMX200_h
#define GillGMX200_h

// Included Dependencies
#include "sensors/SDI12Sensors.h"

// Sensor Specific Defines
#define GMX_NUM_VARIABLES 9
#define GMX_WARM_UP_TIME_MS 500
#define GMX_STABILIZATION_TIME_MS 0
// #define GMX_MEASUREMENT_TIME_MS 12500
#define GMX_MEASUREMENT_TIME_MS 3350// instrument says it returns in 61 seconds, but give it a little extra

#define GMX_DW_RESOLUTION 0
#define GMX_DW_VAR_NUM 0

#define GMX_SW_RESOLUTION 1
#define GMX_SW_VAR_NUM 1

#define GMX_DC_RESOLUTION 0
#define GMX_DC_VAR_NUM 2

#define GMX_SC_RESOLUTION 1
#define GMX_SC_VAR_NUM 3

//#define WXT_PA_RESOLUTION 1
//#define WXT_PA_VAR_NUM 4

//#define WXT_RC_RESOLUTION 2
//#define WXT_RC_VAR_NUM 5

// The main class for the Vaisala WXT520
class GillGMX200 : public SDI12Sensors
{
public:
    // Constructors with overloads
    GillGMX200(char SDI12address, int8_t powerPin, int8_t dataPin, uint8_t measurementsToAverage = 1)
     : SDI12Sensors(SDI12address, powerPin, dataPin, measurementsToAverage,
                    "GillGMX200", GMX_NUM_VARIABLES,
                    GMX_WARM_UP_TIME_MS, GMX_STABILIZATION_TIME_MS, GMX_MEASUREMENT_TIME_MS)
    {}
    GillGMX200(char *SDI12address, int8_t powerPin, int8_t dataPin, uint8_t measurementsToAverage = 1)
     : SDI12Sensors(SDI12address, powerPin, dataPin, measurementsToAverage,
                    "GillGMX200", GMX_NUM_VARIABLES,
                    GMX_WARM_UP_TIME_MS, GMX_STABILIZATION_TIME_MS, GMX_MEASUREMENT_TIME_MS)
    {}
    GillGMX200(int SDI12address, int8_t powerPin, int8_t dataPin, uint8_t measurementsToAverage = 1)
     : SDI12Sensors(SDI12address, powerPin, dataPin, measurementsToAverage,
                    "GillGMX200", GMX_NUM_VARIABLES,
                    GMX_WARM_UP_TIME_MS, GMX_STABILIZATION_TIME_MS, GMX_MEASUREMENT_TIME_MS)
    {}
    // Destructor
    ~GillGMX200(){}
};

// Defines the Dm Variable
class GillGMX200_Dw : public Variable
{
public:
    GillGMX200_Dw(Sensor *parentSense,
                    const char *uuid = "",
                    const char *varCode = "GMXDw")
      : Variable(parentSense,
                 (const uint8_t)GMX_DW_VAR_NUM,
                 (uint8_t)GMX_DW_RESOLUTION,
                 "direction", "degrees",
                 varCode, uuid)
    {}
    GillGMX200_Dw()
      : Variable((const uint8_t)GMX_DW_VAR_NUM,
                 (uint8_t)GMX_DW_RESOLUTION,
                 "direction", "degrees", "GMXDw")
    {}
    ~GillGMX200_Dw(){}
};

// Defines the Sm Variable
class GillGMX200_Sw : public Variable
{
public:
    GillGMX200_Sw(Sensor *parentSense,
                    const char *uuid = "",
                    const char *varCode = "GMXSw")
      : Variable(parentSense,
                 (const uint8_t)GMX_SW_VAR_NUM,
                 (uint8_t)GMX_SW_RESOLUTION,
                 "speed", "metersPerSecond",
                 varCode, uuid)
    {}
    GillGMX200_Sw()
      : Variable((const uint8_t)GMX_SW_VAR_NUM,
                 (uint8_t)GMX_SW_RESOLUTION,
                 "speed", "metersPerSecond", "GMXSw")
    {}
    ~GillGMX200_Sw(){}
};


// Defines the Pa Variable
class GillGMX200_Dc : public Variable
{
public:
    GillGMX200_Dc(Sensor *parentSense,
                     const char *uuid = "",
                     const char *varCode = "GMXDc")
      : Variable(parentSense,
                 (const uint8_t)GMX_DC_VAR_NUM,
                 (uint8_t)GMX_DC_RESOLUTION,
                 "correctedDirection", "degrees",
                 varCode, uuid)
    {}
    GillGMX200_Dc()
      : Variable((const uint8_t)GMX_DC_VAR_NUM,
                 (uint8_t)GMX_DC_RESOLUTION,
                 "correctedDirection", "degrees", "GMXDc")
    {}
    ~GillGMX200_Dc(){}
};

// Defines the Ta Variable
class GillGMX200_Sc : public Variable
{
public:
    GillGMX200_Sc(Sensor *parentSense,
                    const char *uuid = "",
                    const char *varCode = "GMXSc")
      : Variable(parentSense,
                 (const uint8_t)GMX_SC_VAR_NUM,
                 (uint8_t)GMX_SC_RESOLUTION,
                 "correctedSpeed", "metersPerSecond",
                 varCode, uuid)
    {}
    GillGMX200_Sc()
      : Variable((const uint8_t)GMX_SC_VAR_NUM,
                 (uint8_t)GMX_SC_RESOLUTION,
                 "correctedSpeed", "metersPerSecond", "GMXSc")
    {}
    ~GillGMX200_Sc(){}
};

// Defines the Ua Variable
/* class GillGMX200_Ua : public Variable
{
public:
    GillGMX200_Ua(Sensor *parentSense,
                     const char *uuid = "",
                     const char *varCode = "WXTUa")
      : Variable(parentSense,
                 (const uint8_t)WXT_UA_VAR_NUM,
                 (uint8_t)WXT_UA_RESOLUTION,
                 "relativeHumidity", "percent",
                 varCode, uuid)
    {}
    GillGMX200_Ua()
      : Variable((const uint8_t)WXT_UA_VAR_NUM,
                 (uint8_t)WXT_UA_RESOLUTION,
                 "relativeHumidity", "percent", "WXTUa")
    {}
    ~GillGMX200_Ua(){}
}; */


// Defines the Rc Variable
/* class GillGMX200_Rc : public Variable
{
public:
    GillGMX200_Rc(Sensor *parentSense,
                    const char *uuid = "",
                    const char *varCode = "WXTRc")
      : Variable(parentSense,
                 (const uint8_t)WXT_RC_VAR_NUM,
                 (uint8_t)WXT_RC_RESOLUTION,
                 "rainfall", "mm",
                 varCode, uuid)
    {}
    GillGMX200_Rc()
      : Variable((const uint8_t)WXT_RC_VAR_NUM,
                 (uint8_t)WXT_RC_RESOLUTION,
                 "rainfall", "mm", "WXTRc")
    {}
    ~GillGMX200_Rc(){}
}; */

#endif  // Header Guard
