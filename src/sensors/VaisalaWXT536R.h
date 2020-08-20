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
#define WXTR_NUM_VARIABLES 6
#define WXTR_WARM_UP_TIME_MS 500
#define WXTR_STABILIZATION_TIME_MS 0
// #define WXT_MEASUREMENT_TIME_MS 12500
#define WXTR_MEASUREMENT_TIME_MS 3350 // instrument says it returns in 61 seconds, but give it a little extra

#define WXTR_DM_RESOLUTION 0
#define WXTR_DM_VAR_NUM 0

#define WXTR_SM_RESOLUTION 1
#define WXTR_SM_VAR_NUM 1

#define WXTR_TA_RESOLUTION 1
#define WXTR_TA_VAR_NUM 2

#define WXTR_UA_RESOLUTION 1
#define WXTR_UA_VAR_NUM 3

#define WXTR_PA_RESOLUTION 1
#define WXTR_PA_VAR_NUM 4

#define WXTR_RC_RESOLUTION 2
#define WXTR_RC_VAR_NUM 5

// The main class for the Vaisala WXT520
class VaisalaWXT536R : public SDI12SensorsR
{
public:
    // Constructors with overloads
    VaisalaWXT536R(char SDI12address, int8_t powerPin, int8_t dataPin, uint8_t measurementsToAverage = 1)
     : SDI12SensorsR(SDI12address, powerPin, dataPin, measurementsToAverage,
                    "VaisalaWXT536R", WXTR_NUM_VARIABLES,
                    WXTR_WARM_UP_TIME_MS, WXTR_STABILIZATION_TIME_MS, WXTR_MEASUREMENT_TIME_MS)
    {}
    VaisalaWXT536R(char *SDI12address, int8_t powerPin, int8_t dataPin, uint8_t measurementsToAverage = 1)
     : SDI12SensorsR(SDI12address, powerPin, dataPin, measurementsToAverage,
                    "VaisalaWXT536R", WXTR_NUM_VARIABLES,
                    WXTR_WARM_UP_TIME_MS, WXTR_STABILIZATION_TIME_MS, WXTR_MEASUREMENT_TIME_MS)
    {}
    VaisalaWXT536R(int SDI12address, int8_t powerPin, int8_t dataPin, uint8_t measurementsToAverage = 1)
     : SDI12SensorsR(SDI12address, powerPin, dataPin, measurementsToAverage,
                    "VaisalaWXT536R", WXTR_NUM_VARIABLES,
                    WXTR_WARM_UP_TIME_MS, WXTR_STABILIZATION_TIME_MS, WXTR_MEASUREMENT_TIME_MS)
    {}
    // Destructor
    ~VaisalaWXT536R(){}
};

// Defines the Dm Variable
class VaisalaWXT536R_Dm : public Variable
{
public:
    VaisalaWXT536R_Dm(SensorR *parentSense,
                    const char *uuid = "",
                    const char *varCode = "WXTRDm")
      : Variable(parentSense,
                 (const uint8_t)WXTR_DM_VAR_NUM,
                 (uint8_t)WXTR_DM_RESOLUTION,
                 "direction", "degrees",
                 varCode, uuid)
    {}
    VaisalaWXT536R_Dm()
      : Variable((const uint8_t)WXTR_DM_VAR_NUM,
                 (uint8_t)WXTR_DM_RESOLUTION,
                 "direction", "degrees", "WXTRDm")
    {}
    ~VaisalaWXT536R_Dm(){}
};

// Defines the Sm Variable
class VaisalaWXT536R_Sm : public Variable
{
public:
    VaisalaWXT536R_Sm(SensorR *parentSense,
                    const char *uuid = "",
                    const char *varCode = "WXTRSm")
      : Variable(parentSense,
                 (const uint8_t)WXTR_SM_VAR_NUM,
                 (uint8_t)WXTR_SM_RESOLUTION,
                 "speed", "metersPerSecond",
                 varCode, uuid)
    {}
    VaisalaWXT536R_Sm()
      : Variable((const uint8_t)WXTR_SM_VAR_NUM,
                 (uint8_t)WXTR_SM_RESOLUTION,
                 "speed", "metersPerSecond", "WXTRSm")
    {}
    ~VaisalaWXT536R_Sm(){}
};


// Defines the Pa Variable
class VaisalaWXT536R_Pa : public Variable
{
public:
    VaisalaWXT536R_Pa(SensorR *parentSense,
                     const char *uuid = "",
                     const char *varCode = "WXTRPa")
      : Variable(parentSense,
                 (const uint8_t)WXTR_PA_VAR_NUM,
                 (uint8_t)WXTR_PA_RESOLUTION,
                 "airPressure", "hPa",
                 varCode, uuid)
    {}
    VaisalaWXT536R_Pa()
      : Variable((const uint8_t)WXTR_PA_VAR_NUM,
                 (uint8_t)WXTR_PA_RESOLUTION,
                 "airPressure", "hPa", "WXTRPa")
    {}
    ~VaisalaWXT536R_Pa(){}
};

// Defines the Ta Variable
class VaisalaWXT536R_Ta : public Variable
{
public:
    VaisalaWXT536R_Ta(SensorR *parentSense,
                    const char *uuid = "",
                    const char *varCode = "WXTRTa")
      : Variable(parentSense,
                 (const uint8_t)WXTR_TA_VAR_NUM,
                 (uint8_t)WXTR_TA_RESOLUTION,
                 "airTemperature", "degreeCelsius",
                 varCode, uuid)
    {}
    VaisalaWXT536R_Ta()
      : Variable((const uint8_t)WXTR_TA_VAR_NUM,
                 (uint8_t)WXTR_TA_RESOLUTION,
                 "airTemperature", "degreeCelsius", "WXTRTa")
    {}
    ~VaisalaWXT536R_Ta(){}
};

// Defines the Ua Variable
class VaisalaWXT536R_Ua : public Variable
{
public:
    VaisalaWXT536R_Ua(SensorR *parentSense,
                     const char *uuid = "",
                     const char *varCode = "WXTRUa")
      : Variable(parentSense,
                 (const uint8_t)WXTR_UA_VAR_NUM,
                 (uint8_t)WXTR_UA_RESOLUTION,
                 "relativeHumidity", "percent",
                 varCode, uuid)
    {}
    VaisalaWXT536R_Ua()
      : Variable((const uint8_t)WXTR_UA_VAR_NUM,
                 (uint8_t)WXTR_UA_RESOLUTION,
                 "relativeHumidity", "percent", "WXTRUa")
    {}
    ~VaisalaWXT536R_Ua(){}
};


// Defines the Rc Variable
class VaisalaWXT536R_Rc : public Variable
{
public:
    VaisalaWXT536R_Rc(Sensor *parentSense,
                    const char *uuid = "",
                    const char *varCode = "WXTRRc")
      : Variable(parentSense,
                 (const uint8_t)WXTR_RC_VAR_NUM,
                 (uint8_t)WXTR_RC_RESOLUTION,
                 "rainfall", "mm",
                 varCode, uuid)
    {}
    VaisalaWXT536R_Rc()
      : Variable((const uint8_t)WXTR_RC_VAR_NUM,
                 (uint8_t)WXTR_RC_RESOLUTION,
                 "rainfall", "mm", "WXTRRc")
    {}
    ~VaisalaWXT536R_Rc(){}
};

#endif  // Header Guard
