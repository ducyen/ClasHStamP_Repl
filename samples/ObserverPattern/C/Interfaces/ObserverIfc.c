/* File generated by Đức's ClasHStamP */
#define __ObserverIfc_INTERNAL__
#include "CommonInclude.h"
#include "ObserverIfc.h"
/** @public @pure @memberof ObserverIfc */
void ObserverIfc_update(
    ObserverIfc* pObserverIfc,
    float temperature,
    float humidity,
    float pressure
){
    if( pObserverIfc->vTbl == NULL || pObserverIfc->vTbl->pupdate == NULL ){ return; }
    pObserverIfc->vTbl->pupdate( pObserverIfc, temperature, humidity, pressure );
} /* ObserverIfc_update */

ObserverIfc* ObserverIfc_Copy( ObserverIfc* pObserverIfc, const ObserverIfc* pSource ){
    return ( ObserverIfc* )pObserverIfc;
}
