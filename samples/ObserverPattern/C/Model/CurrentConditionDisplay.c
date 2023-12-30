/* File generated by Đức's ClasHStamP */
#define __CurrentConditionDisplay_INTERNAL__
#include "CommonInclude.h"
#include "CurrentConditionDisplay.h"
/** @public @memberof CurrentConditionDisplay */
static void CurrentConditionDisplay_update(
    CurrentConditionDisplay* pCurrentConditionDisplay,
    float temperature,
    float humidity,
    float pressure
){
    pCurrentConditionDisplay->temperature = temperature;
    pCurrentConditionDisplay->humidity = humidity;
    CurrentConditionDisplay_display(pCurrentConditionDisplay);
} /* CurrentConditionDisplay_update */

/** @public @memberof CurrentConditionDisplay */
void CurrentConditionDisplay_display(
    CurrentConditionDisplay* pCurrentConditionDisplay
){
    printf("Current condition: %fdegrees and %f% humidity\n", pCurrentConditionDisplay->temperature, pCurrentConditionDisplay->humidity);
} /* CurrentConditionDisplay_display */

ObserverIfc* CurrentConditionDisplay_Copy( CurrentConditionDisplay* pCurrentConditionDisplay, const CurrentConditionDisplay* pSource ){
    ObserverIfc_Copy( ( ObserverIfc* )pCurrentConditionDisplay, ( ObserverIfc* )pSource );
    pCurrentConditionDisplay->temperature = pSource->temperature;
    pCurrentConditionDisplay->humidity = pSource->humidity;
    pCurrentConditionDisplay->weatherData = pSource->weatherData;
    return ( ObserverIfc* )pCurrentConditionDisplay;
}
const ObserverIfcVtbl gCurrentConditionDisplayVtbl = {
    .pupdate                     = CurrentConditionDisplay_update,
};
