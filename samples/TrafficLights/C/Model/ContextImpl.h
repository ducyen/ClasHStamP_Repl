#ifndef __ContextImpl_H__
#define __ContextImpl_H__
#include "Context.h"
typedef struct tagContextImpl ContextImpl;
typedef enum tagAnEnum {
    One,                                                        
    Two,                                                        
    Three,                                                      
    AnEnum_NUM
}AnEnum;
const TCHAR* AnEnum_toString( AnEnum value );
typedef struct tagE1Params {
    EventParams base;
    AnEnum x;                                                   
}E1Params;
typedef enum tagContextImplEvent {
    ContextImpl_E1,                                             
    ContextImpl_E2,                                             
    ContextImpl_E3,                                             
    ContextImpl_EVENT_NUM
}ContextImpl_EVENT;
const TCHAR* ContextImplEvent_toString( ContextImpl_EVENT value );
BOOL ContextImpl_EventProc( ContextImpl* pContextImpl, ContextImpl_EVENT nEventId, void* pEventParams );
BOOL ContextImpl_Start( ContextImpl* pContextImpl );
#endif//__ContextImpl_H__
#if !defined( ContextImpl_Init ) && ( defined( __ContextImpl_INTERNAL__ )  || defined( __AFriend_INTERNAL__ )  || defined( __Main_INTERNAL__ )  )
#define __Context_INTERNAL__
#include "Context.h"
#define __HdStateMachine_INTERNAL__
#include "HdStateMachine.h"
boolean ContextImpl_checkE1Params( EventParams* e );
/** @class SecondaryRoad
 * @extends HdStateMachine
 */
typedef struct tagSecondaryRoad {
    HdStateMachine base;
#define SecondaryRoad_SecondaryRoadTop_Dmy      ( 1 <<  0 )
#define SecondaryRoad_SecondaryRoadTop          ( SecondaryRoad_SecondaryRoadTop_Dmy | SecondaryRoad_SRed | SecondaryRoad_SYellow | SecondaryRoad_SGreen | SecondaryRoad_PRedWait )
#define SecondaryRoad_InitialPseudostate2       ( 1 << ( 31 -  0 ) )
#define SecondaryRoad_SRed                      ( 1 <<  1 )
#define SecondaryRoad_SYellow                   ( 1 <<  2 )
#define SecondaryRoad_SGreen                    ( 1 <<  3 )
#define SecondaryRoad_PRedWait                  ( 1 <<  4 )
}SecondaryRoad;
#define SecondaryRoad_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(SecondaryRoad_SecondaryRoadTop, SecondaryRoad_SecondaryRoadTop) ),\
}
/** @class MainStm
 * @extends HdStateMachine
 */
typedef struct tagMainStm {
    HdStateMachine base;
    SecondaryRoad SubmachineState0SecondaryRoad;                
#define MainStm_MainTop_Dmy                     ( 1 <<  5 )
#define MainStm_MainTop                         ( MainStm_MainTop_Dmy | MainStm_Starting | MainStm_ManagingThroughTraffic )
#define MainStm_InitialPseudostate0             ( 1 << ( 31 -  0 ) )
#define MainStm_Starting                        ( 1 <<  6 )
#define MainStm_InitialPseudostate1             ( 1 << ( 31 -  1 ) )
#define MainStm_PRed                            ( 1 <<  7 )
#define MainStm_PGreen                          ( 1 <<  8 )
#define MainStm_PYellow                         ( 1 <<  9 )
#define MainStm_SRedWait                        ( 1 << 10 )
#define MainStm_ManagingThroughTraffic_Dmy      ( 1 << 11 )
#define MainStm_ManagingThroughTraffic          ( MainStm_ManagingThroughTraffic_Dmy | MainStm_PRed | MainStm_PGreen | MainStm_PYellow | MainStm_SRedWait )
}MainStm;
#define MainStm_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(MainStm_MainTop, MainStm_MainTop) ),\
    .SubmachineState0SecondaryRoad = SecondaryRoad_Init(),\
}
/** @memberof ContextImpl
 * @brief ContextImpl auto-generated constructor
 */
#define ContextImpl_Init(_derivableAttribute, _publicAttribute, _privateAttribute, _internalAttribute, _readOnlyAttribute, _anAggregation, _aProtectedComposition)\
    Context_Init( P( _derivableAttribute ), P( _publicAttribute ), P( _privateAttribute ), P( _internalAttribute ), P( _readOnlyAttribute ), P( _anAggregation ), P( _aProtectedComposition ) )\
    .vTbl = &gContextImplVtbl,\
    .mainStm = MainStm_Init(),\

#define ContextImpl_Ctor( InitFunc, optionParams )    ( ContextImpl ){\
    InitFunc\
\
}
extern const BaseClassVtbl gContextImplVtbl;
Context* ContextImpl_Copy( ContextImpl* pContextImpl, const ContextImpl* pSource );
/** @class ContextImpl
 * @extends Context
 */
#define ContextImpl_CLASS                                                                       \
    Context_CLASS                                                                               \
    MainStm mainStm;                                            

typedef struct tagContextImpl{
    ContextImpl_CLASS    
}ContextImpl;
#endif//__ContextImpl_INTERNAL__
