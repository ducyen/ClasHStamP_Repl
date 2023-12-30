#ifndef __Sensor_H__
#define __Sensor_H__
#include "Context.h"
typedef struct tagSensor Sensor;
int Sensor_getData( Sensor* pSensor );
void Sensor_doLongComputationOnData( Sensor* pSensor, int _x );
void Sensor_doEvenMoreProcessing( Sensor* pSensor );
typedef enum tagSensorEvent {
    Sensor_evClearDataLatch,                                    
    Sensor_evDataComplete,                                      
    Sensor_evDataReady,                                         
    Sensor_evHasNewData,                                        
    Sensor_evSensorReset,                                       
    Sensor_tm_100,                                              
    Sensor_EVENT_NUM
}Sensor_EVENT;
const TCHAR* SensorEvent_toString( Sensor_EVENT value );
#endif//__Sensor_H__
#if !defined( Sensor_Init ) && ( defined( __Sensor_INTERNAL__ )  || defined( __Main_INTERNAL__ )  )
#define __Context_INTERNAL__
#include "Context.h"
#define __HdStateMachine_INTERNAL__
#include "HdStateMachine.h"
/** @class LatchStm
 * @extends HdStateMachine
 */
typedef struct tagLatchStm {
    HdStateMachine base;
#define LatchStm_LatchTop_Dmy                   ( 1 <<  0 )
#define LatchStm_LatchTop                       ( LatchStm_LatchTop_Dmy | LatchStm_NoData | LatchStm_HasNewData )
#define LatchStm_InitPt                         ( 1 << ( 31 -  0 ) )
#define LatchStm_NoData                         ( 1 <<  1 )
#define LatchStm_HasNewData                     ( 1 <<  2 )
}LatchStm;
#define LatchStm_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(LatchStm_LatchTop, LatchStm_LatchTop) ),\
}
/** @class DepedentStm
 * @extends HdStateMachine
 */
typedef struct tagDepedentStm {
    HdStateMachine base;
    LatchStm LatchLatchStm;                                     
#define DepedentStm_DependentTop_Dmy            ( 1 <<  3 )
#define DepedentStm_DependentTop                ( DepedentStm_DependentTop_Dmy | DepedentStm_Dependent )
#define DepedentStm_InitPt                      ( 1 << ( 31 -  0 ) )
#define DepedentStm_ProcessingData              ( 1 <<  4 )
#define DepedentStm_MoreProcessing              ( 1 <<  5 )
#define DepedentStm_ReadyToProcessData          ( 1 <<  6 )
#define DepedentStm_Dependent_Dmy               ( 1 <<  7 )
#define DepedentStm_Dependent                   ( DepedentStm_Dependent_Dmy | DepedentStm_ProcessingData | DepedentStm_MoreProcessing | DepedentStm_ReadyToProcessData )
}DepedentStm;
#define DepedentStm_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(DepedentStm_DependentTop, DepedentStm_DependentTop) ),\
    .LatchLatchStm = LatchStm_Init(),\
}
/** @class PredicateStm
 * @extends HdStateMachine
 */
typedef struct tagPredicateStm {
    HdStateMachine base;
    DepedentStm DependentDepedentStm;                           
#define PredicateStm_PredicateTop_Dmy           ( 1 <<  8 )
#define PredicateStm_PredicateTop               ( PredicateStm_PredicateTop_Dmy | PredicateStm_SensorActive )
#define PredicateStm_InitPt                     ( 1 << ( 31 -  0 ) )
#define PredicateStm_WaitingForData             ( 1 <<  9 )
#define PredicateStm_DataReady                  ( 1 << 10 )
#define PredicateStm_ResetingSensor             ( 1 << 11 )
#define PredicateStm_SensorActive_Dmy           ( 1 << 12 )
#define PredicateStm_SensorActive               ( PredicateStm_SensorActive_Dmy | PredicateStm_WaitingForData | PredicateStm_DataReady | PredicateStm_ResetingSensor )
}PredicateStm;
#define PredicateStm_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(PredicateStm_PredicateTop, PredicateStm_PredicateTop) ),\
    .DependentDepedentStm = DepedentStm_Init(),\
}
/** @memberof Sensor
 * @brief Sensor auto-generated constructor
 */
#define Sensor_Init(_attribute0)\
    Context_Init( P( _attribute0 ) )\
    .x = 0,\
    .mainStm = PredicateStm_Init(),\

#define Sensor_Ctor( InitFunc, optionParams )    ( Sensor ){\
    InitFunc\
\
}
Context* Sensor_Copy( Sensor* pSensor, const Sensor* pSource );
/** @class Sensor
 * @extends Context
 */
#define Sensor_CLASS                                                                            \
    Context_CLASS                                                                               \
    int x;                                                                                                                             \
    PredicateStm mainStm;                                       

typedef struct tagSensor{
    Sensor_CLASS    
}Sensor;
BOOL Sensor_EventProc( Sensor* pSensor, Sensor_EVENT nEventId, void* pEventParams );
BOOL Sensor_Start( Sensor* pSensor );
#endif//__Sensor_INTERNAL__
