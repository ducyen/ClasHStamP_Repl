#ifndef __CurrentConditionDisplay_H__
#define __CurrentConditionDisplay_H__
#include "ObserverIfc.h"
#include "Subject.h"
typedef struct tagCurrentConditionDisplay CurrentConditionDisplay;
void CurrentConditionDisplay_display( CurrentConditionDisplay* pCurrentConditionDisplay );
#endif//__CurrentConditionDisplay_H__
#if !defined( CurrentConditionDisplay_Init ) && ( defined( __CurrentConditionDisplay_INTERNAL__ )  || defined( __Main_INTERNAL__ )  )
#define __ObserverIfc_INTERNAL__
#include "ObserverIfc.h"
#include "Subject.h"
/** @memberof CurrentConditionDisplay
 * @brief CurrentConditionDisplay auto-generated constructor
 */
#define CurrentConditionDisplay_Init(_weatherData)\
    ObserverIfc_Init(  )\
    .vTbl = &gCurrentConditionDisplayVtbl,\
    .temperature = 0,\
    .humidity = 0,\
    .weatherData = _weatherData,\

#define CurrentConditionDisplay_Ctor( InitFunc, optionParams )    ( CurrentConditionDisplay ){\
    InitFunc\
\
}
extern const ObserverIfcVtbl gCurrentConditionDisplayVtbl;
ObserverIfc* CurrentConditionDisplay_Copy( CurrentConditionDisplay* pCurrentConditionDisplay, const CurrentConditionDisplay* pSource );
/** @class CurrentConditionDisplay
 * @extends ObserverIfc
 */
#define CurrentConditionDisplay_CLASS                                                           \
    ObserverIfc_CLASS                                                                           \
    float temperature;                                                                                                     \
    float humidity;                                                                                                           \
    Subject* weatherData;                                       \

typedef struct tagCurrentConditionDisplay{
    CurrentConditionDisplay_CLASS    
}CurrentConditionDisplay;
#endif//__CurrentConditionDisplay_INTERNAL__
