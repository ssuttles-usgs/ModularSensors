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
#ifndef VaisalaWXT536RG_h
#define VaisalaWXT536RG_h

// Included Dependencies
#include "sensors/SDI12SensorsR.h"

// Sensor Specific Defines
#define WXT_NUM_VARIABLES 8
#define WXT_WARM_UP_TIME_MS 500
#define WXT_STABILIZATION_TIME_MS 0
// #define WXT_MEASUREMENT_TIME_MS 12500
#define WXT_MEASUREMENT_TIME_MS 3350 // instrument says it returns in 61 seconds, but give it a little extra

#define WXT_DN_RESOLUTION 0
#define WXT_DN_VAR_NUM 0

#define WXT_DM_RESOLUTION 0
#define WXT_DM_VAR_NUM 1

#define WXT_DX_RESOLUTION 0
#define WXT_DX_VAR_NUM 2

#define WXT_SN_RESOLUTION 1
#define WXT_SN_VAR_NUM 3

#define WXT_SM_RESOLUTION 1
#define WXT_SM_VAR_NUM 4

#define WXT_SX_RESOLUTION 1
#define WXT_SX_VAR_NUM 5

#define WXT_TA_RESOLUTION 1
#define WXT_TA_VAR_NUM 6

#define WXT_UA_RESOLUTION 1
#define WXT_UA_VAR_NUM 7

/*#define WXT_PA_RESOLUTION 1
#define WXT_PA_VAR_NUM 8
*/
/*#define WXT_RC_RESOLUTION 2
#define WXT_RC_VAR_NUM 9
 */
// The main class for the Vaisala WXT520
class VaisalaWXT536RG : public SDI12SensorsR
{
public:
    // Constructors with overloads
    VaisalaWXT536RG(char SDI12address, int8_t powerPin, int8_t dataPin, uint8_t measurementsToAverage = 1)
     : SDI12SensorsR(SDI12address, powerPin, dataPin, measurementsToAverage,
                    "VaisalaWXT536RG", WXT_NUM_VARIABLES,
                    WXT_WARM_UP_TIME_MS, WXT_STABILIZATION_TIME_MS, WXT_MEASUREMENT_TIME_MS)
    {}
    VaisalaWXT536RG(char *SDI12address, int8_t powerPin, int8_t dataPin, uint8_t measurementsToAverage = 1)
     : SDI12SensorsR(SDI12address, powerPin, dataPin, measurementsToAverage,
                    "VaisalaWXT536RG", WXT_NUM_VARIABLES,
                    WXT_WARM_UP_TIME_MS, WXT_STABILIZATION_TIME_MS, WXT_MEASUREMENT_TIME_MS)
    {}
    VaisalaWXT536RG(int SDI12address, int8_t powerPin, int8_t dataPin, uint8_t measurementsToAverage = 1)
     : SDI12SensorsR(SDI12address, powerPin, dataPin, measurementsToAverage,
                    "VaisalaWXT536RG", WXT_NUM_VARIABLES,
                    WXT_WARM_UP_TIME_MS, WXT_STABILIZATION_TIME_MS, WXT_MEASUREMENT_TIME_MS)
    {}
    // Destructor
    ~VaisalaWXT536RG(){}
};

// Defines the Dm Variable
class VaisalaWXT536RG_Dn : public Variable
{
public:
    VaisalaWXT536RG_Dn(Sensor *parentSense,
                    const char *uuid = "",
                    const char *varCode = "WXTDn")
      : Variable(parentSense,
                 (const uint8_t)WXT_DN_VAR_NUM,
                 (uint8_t)WXT_DN_RESOLUTION,
                 "direction", "degrees",
                 varCode, uuid)
    {}
    VaisalaWXT536RG_Dn()
      : Variable((const uint8_t)WXT_DN_VAR_NUM,
                 (uint8_t)WXT_DN_RESOLUTION,
                 "direction", "degrees", "WXTDn")
    {}
    ~VaisalaWXT536RG_Dn(){}
};

class VaisalaWXT536RG_Dm : public Variable
{
public:
    VaisalaWXT536RG_Dm(Sensor *parentSense,
                    const char *uuid = "",
                    const char *varCode = "WXTDm")
      : Variable(parentSense,
                 (const uint8_t)WXT_DM_VAR_NUM,
                 (uint8_t)WXT_DM_RESOLUTION,
                 "direction", "degrees",
                 varCode, uuid)
    {}
    VaisalaWXT536RG_Dm()
      : Variable((const uint8_t)WXT_DM_VAR_NUM,
                 (uint8_t)WXT_DM_RESOLUTION,
                 "direction", "degrees", "WXTDm")
    {}
    ~VaisalaWXT536RG_Dm(){}
};

class VaisalaWXT536RG_Dx : public Variable
{
public:
    VaisalaWXT536RG_Dx(Sensor *parentSense,
                    const char *uuid = "",
                    const char *varCode = "WXTDx")
      : Variable(parentSense,
                 (const uint8_t)WXT_DX_VAR_NUM,
                 (uint8_t)WXT_DX_RESOLUTION,
                 "direction", "degrees",
                 varCode, uuid)
    {}
    VaisalaWXT536RG_Dx()
      : Variable((const uint8_t)WXT_DX_VAR_NUM,
                 (uint8_t)WXT_DX_RESOLUTION,
                 "direction", "degrees", "WXTDx")
    {}
    ~VaisalaWXT536RG_Dx(){}
};

// Defines the Sm Variable
class VaisalaWXT536RG_Sn : public Variable
{
public:
    VaisalaWXT536RG_Sn(Sensor *parentSense,
                    const char *uuid = "",
                    const char *varCode = "WXTSn")
      : Variable(parentSense,
                 (const uint8_t)WXT_SN_VAR_NUM,
                 (uint8_t)WXT_SN_RESOLUTION,
                 "speed", "metersPerSecond",
                 varCode, uuid)
    {}
    VaisalaWXT536RG_Sn()
      : Variable((const uint8_t)WXT_SN_VAR_NUM,
                 (uint8_t)WXT_SN_RESOLUTION,
                 "speed", "metersPerSecond", "WXTSn")
    {}
    ~VaisalaWXT536RG_Sn(){}
};

class VaisalaWXT536RG_Sm : public Variable
{
public:
    VaisalaWXT536RG_Sm(Sensor *parentSense,
                    const char *uuid = "",
                    const char *varCode = "WXTSm")
      : Variable(parentSense,
                 (const uint8_t)WXT_SM_VAR_NUM,
                 (uint8_t)WXT_SM_RESOLUTION,
                 "speed", "metersPerSecond",
                 varCode, uuid)
    {}
    VaisalaWXT536RG_Sm()
      : Variable((const uint8_t)WXT_SM_VAR_NUM,
                 (uint8_t)WXT_SM_RESOLUTION,
                 "speed", "metersPerSecond", "WXTSm")
    {}
    ~VaisalaWXT536RG_Sm(){}
};

class VaisalaWXT536RG_Sx : public Variable
{
public:
    VaisalaWXT536RG_Sx(Sensor *parentSense,
                    const char *uuid = "",
                    const char *varCode = "WXTSx")
      : Variable(parentSense,
                 (const uint8_t)WXT_SX_VAR_NUM,
                 (uint8_t)WXT_SX_RESOLUTION,
                 "speed", "metersPerSecond",
                 varCode, uuid)
    {}
    VaisalaWXT536RG_Sx()
      : Variable((const uint8_t)WXT_SX_VAR_NUM,
                 (uint8_t)WXT_SX_RESOLUTION,
                 "speed", "metersPerSecond", "WXTSx")
    {}
    ~VaisalaWXT536RG_Sx(){}
};

/* // Defines the Pa Variable
class VaisalaWXT536RG_Pa : public Variable
{
public:
    VaisalaWXT536RG_Pa(Sensor *parentSense,
                     const char *uuid = "",
                     const char *varCode = "WXTPa")
      : Variable(parentSense,
                 (const uint8_t)WXT_PA_VAR_NUM,
                 (uint8_t)WXT_PA_RESOLUTION,
                 "airPressure", "hPa",
                 varCode, uuid)
    {}
    VaisalaWXT536RG_Pa()
      : Variable((const uint8_t)WXT_PA_VAR_NUM,
                 (uint8_t)WXT_PA_RESOLUTION,
                 "airPressure", "hPa", "WXTPa")
    {}
    ~VaisalaWXT536RG_Pa(){}
}; */

// Defines the Ta Variable
class VaisalaWXT536RG_Ta : public Variable
{
public:
    VaisalaWXT536RG_Ta(Sensor *parentSense,
                    const char *uuid = "",
                    const char *varCode = "WXTTa")
      : Variable(parentSense,
                 (const uint8_t)WXT_TA_VAR_NUM,
                 (uint8_t)WXT_TA_RESOLUTION,
                 "airTemperature", "degreeCelsius",
                 varCode, uuid)
    {}
    VaisalaWXT536RG_Ta()
      : Variable((const uint8_t)WXT_TA_VAR_NUM,
                 (uint8_t)WXT_TA_RESOLUTION,
                 "airTemperature", "degreeCelsius", "WXTTa")
    {}
    ~VaisalaWXT536RG_Ta(){}
};

// Defines the Ua Variable
class VaisalaWXT536RG_Ua : public Variable
{
public:
    VaisalaWXT536RG_Ua(Sensor *parentSense,
                     const char *uuid = "",
                     const char *varCode = "WXTUa")
      : Variable(parentSense,
                 (const uint8_t)WXT_UA_VAR_NUM,
                 (uint8_t)WXT_UA_RESOLUTION,
                 "relativeHumidity", "percent",
                 varCode, uuid)
    {}
    VaisalaWXT536RG_Ua()
      : Variable((const uint8_t)WXT_UA_VAR_NUM,
                 (uint8_t)WXT_UA_RESOLUTION,
                 "relativeHumidity", "percent", "WXTUa")
    {}
    ~VaisalaWXT536RG_Ua(){}
};


/* // Defines the Rc Variable
class VaisalaWXT536RG_Rc : public Variable
{
public:
    VaisalaWXT536RG_Rc(Sensor *parentSense,
                    const char *uuid = "",
                    const char *varCode = "WXTRc")
      : Variable(parentSense,
                 (const uint8_t)WXT_RC_VAR_NUM,
                 (uint8_t)WXT_RC_RESOLUTION,
                 "rainfall", "mm",
                 varCode, uuid)
    {}
    VaisalaWXT536RG_Rc()
      : Variable((const uint8_t)WXT_RC_VAR_NUM,
                 (uint8_t)WXT_RC_RESOLUTION,
                 "rainfall", "mm", "WXTRc")
    {}
    ~VaisalaWXT536RG_Rc(){}
};  */
#endif  // Header Guard
