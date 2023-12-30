#ifndef __AirspeedSensor_H__
#define __AirspeedSensor_H__
#include "Context.h"
typedef struct tagAirspeedSensor AirspeedSensor;
typedef enum tagAirspeedSensorEvent {
    AirspeedSensor_evDataReady,                                 
    AirspeedSensor_evDisablePolling,                            
    AirspeedSensor_evEnablePolling,                             
    AirspeedSensor_evFinish,                                    
    AirspeedSensor_evStart,                                     
    AirspeedSensor_evStop,                                      
    AirspeedSensor_tm_POLLTIME,                                 
    AirspeedSensor_EVENT_NUM
}AirspeedSensor_EVENT;
const TCHAR* AirspeedSensorEvent_toString( AirspeedSensor_EVENT value );
#endif//__AirspeedSensor_H__
#if !defined( AirspeedSensor_Init ) && ( defined( __AirspeedSensor_INTERNAL__ )  || defined( __Main_INTERNAL__ )  )
#define __Context_INTERNAL__
#include "Context.h"
#define __HdStateMachine_INTERNAL__
#include "HdStateMachine.h"
/** @class PollingRegionStm
 * @extends HdStateMachine
 */
typedef struct tagPollingRegionStm {
    HdStateMachine base;
#define PollingRegionStm_PollingRegionTop_Dmy   ( 1 <<  0 )
#define PollingRegionStm_PollingRegionTop       ( PollingRegionStm_PollingRegionTop_Dmy | PollingRegionStm_NotAcquiring | PollingRegionStm_WaitingToAcquire )
#define PollingRegionStm_NotAcquiring           ( 1 <<  1 )
#define PollingRegionStm_InitialPseudostate0    ( 1 << ( 31 -  0 ) )
#define PollingRegionStm_WaitingToAcquire       ( 1 <<  2 )
}PollingRegionStm;
#define PollingRegionStm_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(PollingRegionStm_PollingRegionTop, PollingRegionStm_PollingRegionTop) ),\
}
/** @class AirspeedSensorStm
 * @extends HdStateMachine
 */
typedef struct tagAirspeedSensorStm {
    HdStateMachine base;
    PollingRegionStm PollingRegionPollingRegionStm;             
#define AirspeedSensorStm_AirspeedSensorTop_Dmy ( 1 <<  3 )
#define AirspeedSensorStm_AirspeedSensorTop     ( AirspeedSensorStm_AirspeedSensorTop_Dmy | AirspeedSensorStm_DataHandlingRegion )
#define AirspeedSensorStm_InitPt1               ( 1 << ( 31 -  0 ) )
#define AirspeedSensorStm_Inactive              ( 1 <<  4 )
#define AirspeedSensorStm_Idle                  ( 1 <<  5 )
#define AirspeedSensorStm_CrunchingData         ( 1 <<  6 )
#define AirspeedSensorStm_InitialPseudostate1   ( 1 << ( 31 -  1 ) )
#define AirspeedSensorStm_Active_Dmy            ( 1 <<  7 )
#define AirspeedSensorStm_Active                ( AirspeedSensorStm_Active_Dmy | AirspeedSensorStm_Idle | AirspeedSensorStm_CrunchingData )
#define AirspeedSensorStm_DataHandlingRegion_Dmy ( 1 <<  8 )
#define AirspeedSensorStm_DataHandlingRegion    ( AirspeedSensorStm_DataHandlingRegion_Dmy | AirspeedSensorStm_Inactive | AirspeedSensorStm_Active )
}AirspeedSensorStm;
#define AirspeedSensorStm_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(AirspeedSensorStm_AirspeedSensorTop, AirspeedSensorStm_AirspeedSensorTop) ),\
    .PollingRegionPollingRegionStm = PollingRegionStm_Init(),\
}
/** @memberof AirspeedSensor
 * @brief AirspeedSensor auto-generated constructor
 */
#define AirspeedSensor_Init(_attribute0)\
    Context_Init( P( _attribute0 ) )\
    .mainStm = AirspeedSensorStm_Init(),\

#define AirspeedSensor_Ctor( InitFunc, optionParams )    ( AirspeedSensor ){\
    InitFunc\
\
}
Context* AirspeedSensor_Copy( AirspeedSensor* pAirspeedSensor, const AirspeedSensor* pSource );
/** @class AirspeedSensor
 * @extends Context
 */
#define AirspeedSensor_CLASS                                                                    \
    Context_CLASS                                                                               \
    AirspeedSensorStm mainStm;                                  

typedef struct tagAirspeedSensor{
    AirspeedSensor_CLASS    
}AirspeedSensor;
BOOL AirspeedSensor_EventProc( AirspeedSensor* pAirspeedSensor, AirspeedSensor_EVENT nEventId, void* pEventParams );
BOOL AirspeedSensor_Start( AirspeedSensor* pAirspeedSensor );
#endif//__AirspeedSensor_INTERNAL__
