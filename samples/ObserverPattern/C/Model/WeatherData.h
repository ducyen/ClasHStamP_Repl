#ifndef __WeatherData_H__
#define __WeatherData_H__
#include "Subject.h"
#include "ObserverIfc.h"
typedef struct tagWeatherData WeatherData;
void WeatherData_measurementsChanged( WeatherData* pWeatherData );
void WeatherData_setMeasurements( WeatherData* pWeatherData, float temperature, float humidity, float pressure );
#endif//__WeatherData_H__
#if !defined( WeatherData_Init ) && ( defined( __WeatherData_INTERNAL__ )  || defined( __Main_INTERNAL__ )  )
#define __Subject_INTERNAL__
#include "Subject.h"
#include "ObserverIfc.h"
/** @memberof WeatherData
 * @brief WeatherData auto-generated constructor
 */
#define WeatherData_Init(_observers)\
    Subject_Init(  )\
    .vTbl = &gWeatherDataVtbl,\
    .temperature = 0,\
    .humidity = 0,\
    .pressure = 0,\
    .observers = P( _observers ),\

#define WeatherData_Ctor( InitFunc, optionParams )    ( WeatherData ){\
    InitFunc\
\
}
extern const SubjectVtbl gWeatherDataVtbl;
Subject* WeatherData_Copy( WeatherData* pWeatherData, const WeatherData* pSource );
/** @class WeatherData
 * @extends Subject
 */
#define WeatherData_CLASS                                                                       \
    Subject_CLASS                                                                               \
    float temperature;                                                                                                     \
    float humidity;                                                                                                           \
    float pressure;                                                                                                           \
    ObserverIfc* observers[ 10 ];                               \

typedef struct tagWeatherData{
    WeatherData_CLASS    
}WeatherData;
#endif//__WeatherData_INTERNAL__
