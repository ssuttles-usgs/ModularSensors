/*
 *VaisalaWXT536.h
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
#ifndef VaisalaWXT536R_h
#define VaisalaWXT536R_h

// Included Dependencies
#include "sensors/SDI12SensorsR.h"

// Sensor Specific Defines
#define WXT_NUM_VARIABLES 6
#define WXT_WARM_UP_TIME_MS 500
#define WXT_STABILIZATION_TIME_MS 0
// #define WXT_MEASUREMENT_TIME_MS 12500
#define WXT_MEASUREMENT_TIME_MS 3350 // instrument says it returns in 61 seconds, but give it a little extra

#define WXT_DM_RESOLUTION 0
#define WXT_DM_VAR_NUM 0

#define WXT_SM_RESOLUTION 1
#define WXT_SM_VAR_NUM 1

#define WXT_TA_RESOLUTION 1
#define WXT_TA_VAR_NUM 2

#define WXT_UA_RESOLUTION 1
#define WXT_UA_VAR_NUM 3

#define WXT_PA_RESOLUTION 1
#define WXT_PA_VAR_NUM 4

#define WXT_RC_RESOLUTION 2
#define WXT_RC_VAR_NUM 5

// The main class for the Vaisala WXT520
class VaisalaWXT536R : public SDI12SensorsR
{
public:
    // Constructors with overloads
    VaisalaWXT536R(char SDI12address, int8_t powerPin, int8_t dataPin, uint8_t measurementsToAverage = 1)
     : SDI12SensorsR(SDI12address, powerPin, dataPin, measurementsToAverage,
                    "VaisalaWXT536R", WXT_NUM_VARIABLES,
                    WXT_WARM_UP_TIME_MS, WXT_STABILIZATION_TIME_MS, WXT_MEASUREMENT_TIME_MS)
    {}
    VaisalaWXT536R(char *SDI12address, int8_t powerPin, int8_t dataPin, uint8_t measurementsToAverage = 1)
     : SDI12SensorsR(SDI12address, powerPin, dataPin, measurementsToAverage,
                    "VaisalaWXT536R", WXT_NUM_VARIABLES,
                    WXT_WARM_UP_TIME_MS, WXT_STABILIZATION_TIME_MS, WXT_MEASUREMENT_TIME_MS)
    {}
    VaisalaWXT536R(int SDI12address, int8_t powerPin, int8_t dataPin, uint8_t measurementsToAverage = 1)
     : SDI12SensorsR(SDI12address, powerPin, dataPin, measurementsToAverage,
                    "VaisalaWXT536R", WXT_NUM_VARIABLES,
                    WXT_WARM_UP_TIME_MS, WXT_STABILIZATION_TIME_MS, WXT_MEASUREMENT_TIME_MS)
    {}
    // Destructor
    ~VaisalaWXT536R(){}
};

// Defines the Dm Variable
class VaisalaWXT536R_Dm : public Variable
{
public:
    VaisalaWXT536R_Dm(Sensor *parentSense,
                    const char *uuid = "",
                    const char *varCode = "WXTDm")
      : Variable(parentSense,
                 (const uint8_t)WXT_DM_VAR_NUM,
                 (uint8_t)WXT_DM_RESOLUTION,
                 "direction", "degrees",
                 varCode, uuid)
    {}
    VaisalaWXT536R_Dm()
      : Variable((const uint8_t)WXT_DM_VAR_NUM,
                 (uint8_t)WXT_DM_RESOLUTION,
                 "direction", "degrees", "WXTDm")
    {}
    ~VaisalaWXT536R_Dm(){}
};

// Defines the Sm Variable
class VaisalaWXT536R_Sm : public Variable
{
public:
    VaisalaWXT536R_Sm(Sensor *parentSense,
                    const char *uuid = "",
                    const char *varCode = "WXTSm")
      : Variable(parentSense,
                 (const uint8_t)WXT_SM_VAR_NUM,
                 (uint8_t)WXT_SM_RESOLUTION,
                 "speed", "metersPerSecond",
                 varCode, uuid)
    {}
    VaisalaWXT536R_Sm()
      : Variable((const uint8_t)WXT_SM_VAR_NUM,
                 (uint8_t)WXT_SM_RESOLUTION,
                 "speed", "metersPerSecond", "WXTSm")
    {}
    ~VaisalaWXT536R_Sm(){}
};


// Defines the Pa Variable
class VaisalaWXT536R_Pa : public Variable
{
public:
    VaisalaWXT536R_Pa(Sensor *parentSense,
                     const char *uuid = "",
                     const char *varCode = "WXTPa")
      : Variable(parentSense,
                 (const uint8_t)WXT_PA_VAR_NUM,
                 (uint8_t)WXT_PA_RESOLUTION,
                 "airPressure", "hPa",
                 varCode, uuid)
    {}
    VaisalaWXT536R_Pa()
      : Variable((const uint8_t)WXT_PA_VAR_NUM,
                 (uint8_t)WXT_PA_RESOLUTION,
                 "airPressure", "hPa", "WXTPa")
    {}
    ~VaisalaWXT536R_Pa(){}
};

// Defines the Ta Variable
class VaisalaWXT536R_Ta : public Variable
{
public:
    VaisalaWXT536R_Ta(Sensor *parentSense,
                    const char *uuid = "",
                    const char *varCode = "WXTTa")
      : Variable(parentSense,
                 (const uint8_t)WXT_TA_VAR_NUM,
                 (uint8_t)WXT_TA_RESOLUTION,
                 "airTemperature", "degreeCelsius",
                 varCode, uuid)
    {}
    VaisalaWXT536R_Ta()
      : Variable((const uint8_t)WXT_TA_VAR_NUM,
                 (uint8_t)WXT_TA_RESOLUTION,
                 "airTemperature", "degreeCelsius", "WXTTa")
    {}
    ~VaisalaWXT536R_Ta(){}
};

// Defines the Ua Variable
class VaisalaWXT536R_Ua : public Variable
{
public:
    VaisalaWXT536R_Ua(Sensor *parentSense,
                     const char *uuid = "",
                     const char *varCode = "WXTUa")
      : Variable(parentSense,
                 (const uint8_t)WXT_UA_VAR_NUM,
                 (uint8_t)WXT_UA_RESOLUTION,
                 "relativeHumidity", "percent",
                 varCode, uuid)
    {}
    VaisalaWXT536R_Ua()
      : Variable((const uint8_t)WXT_UA_VAR_NUM,
                 (uint8_t)WXT_UA_RESOLUTION,
                 "relativeHumidity", "percent", "WXTUa")
    {}
    ~VaisalaWXT536R_Ua(){}
};


// Defines the Rc Variable
class VaisalaWXT536R_Rc : public Variable
{
public:
    VaisalaWXT536R_Rc(Sensor *parentSense,
                    const char *uuid = "",
                    const char *varCode = "WXTRc")
      : Variable(parentSense,
                 (const uint8_t)WXT_RC_VAR_NUM,
                 (uint8_t)WXT_RC_RESOLUTION,
                 "rainfall", "mm",
                 varCode, uuid)
    {}
    VaisalaWXT536R_Rc()
      : Variable((const uint8_t)WXT_RC_VAR_NUM,
                 (uint8_t)WXT_RC_RESOLUTION,
                 "rainfall", "mm", "WXTRc")
    {}
    ~VaisalaWXT536R_Rc(){}
};

#endif  // Header Guard
