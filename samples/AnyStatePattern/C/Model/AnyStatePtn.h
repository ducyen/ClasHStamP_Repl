#ifndef __AnyStatePtn_H__
#define __AnyStatePtn_H__
#include "Context.h"
typedef struct tagAnyStatePtn AnyStatePtn;
typedef enum tagAnyStatePtnEvent {
    AnyStatePtn_ev0,                                            
    AnyStatePtn_ev1,                                            
    AnyStatePtn_ev2,                                            
    AnyStatePtn_ev3,                                            
    AnyStatePtn_EVENT_NUM
}AnyStatePtn_EVENT;
const TCHAR* AnyStatePtnEvent_toString( AnyStatePtn_EVENT value );
#endif//__AnyStatePtn_H__
#if !defined( AnyStatePtn_Init ) && ( defined( __AnyStatePtn_INTERNAL__ )  || defined( __Main_INTERNAL__ )  )
#define __Context_INTERNAL__
#include "Context.h"
#define __HdStateMachine_INTERNAL__
#include "HdStateMachine.h"
/** @class AnyStateStm
 * @extends HdStateMachine
 */
typedef struct tagAnyStateStm {
    HdStateMachine base;
#define AnyStateStm_AnyStateTop_Dmy             ( 1 <<  0 )
#define AnyStateStm_AnyStateTop                 ( AnyStateStm_AnyStateTop_Dmy | AnyStateStm_CompositeState )
#define AnyStateStm_InitPt1                     ( 1 << ( 31 -  0 ) )
#define AnyStateStm_State0                      ( 1 <<  1 )
#define AnyStateStm_State1                      ( 1 <<  2 )
#define AnyStateStm_State2                      ( 1 <<  3 )
#define AnyStateStm_State3                      ( 1 <<  4 )
#define AnyStateStm_InitPt2                     ( 1 << ( 31 -  1 ) )
#define AnyStateStm_CompositeState_Dmy          ( 1 <<  5 )
#define AnyStateStm_CompositeState              ( AnyStateStm_CompositeState_Dmy | AnyStateStm_State0 | AnyStateStm_State1 | AnyStateStm_State2 | AnyStateStm_State3 )
}AnyStateStm;
#define AnyStateStm_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(AnyStateStm_AnyStateTop, AnyStateStm_AnyStateTop) ),\
}
/** @memberof AnyStatePtn
 * @brief AnyStatePtn auto-generated constructor
 */
#define AnyStatePtn_Init(_attribute0)\
    Context_Init( P( _attribute0 ) )\
    .mainStm = AnyStateStm_Init(),\

#define AnyStatePtn_Ctor( InitFunc, optionParams )    ( AnyStatePtn ){\
    InitFunc\
\
}
Context* AnyStatePtn_Copy( AnyStatePtn* pAnyStatePtn, const AnyStatePtn* pSource );
/** @class AnyStatePtn
 * @extends Context
 */
#define AnyStatePtn_CLASS                                                                       \
    Context_CLASS                                                                               \
    AnyStateStm mainStm;                                        

typedef struct tagAnyStatePtn{
    AnyStatePtn_CLASS    
}AnyStatePtn;
BOOL AnyStatePtn_EventProc( AnyStatePtn* pAnyStatePtn, AnyStatePtn_EVENT nEventId, void* pEventParams );
BOOL AnyStatePtn_Start( AnyStatePtn* pAnyStatePtn );
#endif//__AnyStatePtn_INTERNAL__
