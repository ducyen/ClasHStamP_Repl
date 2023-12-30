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
    ContextImpl_E0,                                             
    ContextImpl_E1,                                             
    ContextImpl_E2,                                             
    ContextImpl_E3,                                             
    ContextImpl_E4,                                             
    ContextImpl_E5,                                             
    ContextImpl_EVENT_NUM
}ContextImpl_EVENT;
const TCHAR* ContextImplEvent_toString( ContextImpl_EVENT value );
#endif//__ContextImpl_H__
#if !defined( ContextImpl_Init ) && ( defined( __ContextImpl_INTERNAL__ )  || defined( __AFriend_INTERNAL__ )  || defined( __Main_INTERNAL__ )  )
#define __Context_INTERNAL__
#include "Context.h"
#define __HdStateMachine_INTERNAL__
#include "HdStateMachine.h"
boolean ContextImpl_checkE1Params( EventParams* e );
/** @class S82Stm
 * @extends HdStateMachine
 */
typedef struct tagS82Stm {
    HdStateMachine base;
#define S82Stm_S82Top_Dmy                       ( 1 <<  0 )
#define S82Stm_S82Top                           ( S82Stm_S82Top_Dmy | S82Stm_S821 | S82Stm_S822 )
#define S82Stm_InitPt                           ( 1 << ( 31 -  0 ) )
#define S82Stm_S821                             ( 1 <<  1 )
#define S82Stm_S822                             ( 1 <<  2 )
}S82Stm;
#define S82Stm_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(S82Stm_S82Top, S82Stm_S82Top), ),\
}
/** @class S83Stm
 * @extends HdStateMachine
 */
typedef struct tagS83Stm {
    HdStateMachine base;
#define S83Stm_S83Top_Dmy                       ( 1 <<  3 )
#define S83Stm_S83Top                           ( S83Stm_S83Top_Dmy | S83Stm_S831 | S83Stm_S832 )
#define S83Stm_InitPt                           ( 1 << ( 31 -  0 ) )
#define S83Stm_S831                             ( 1 <<  4 )
#define S83Stm_S832                             ( 1 <<  5 )
}S83Stm;
#define S83Stm_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(S83Stm_S83Top, S83Stm_S83Top), ),\
}
/** @class SharedStm
 * @extends HdStateMachine
 */
typedef struct tagSharedStm {
    HdStateMachine base;
#define SharedStm_SharedTop_Dmy                 ( 1 <<  6 )
#define SharedStm_SharedTop                     ( SharedStm_SharedTop_Dmy | SharedStm_Shared1 | SharedStm_Shared2 )
#define SharedStm_InitPt                        ( 1 << ( 31 -  0 ) )
#define SharedStm_Shared1                       ( 1 <<  7 )
#define SharedStm_Shared2                       ( 1 <<  8 )
#define SharedStm_Entry1                        ( 1 << ( 31 -  1 ) )
#define SharedStm_Exit1                         ( 1 << ( 31 -  2 ) )
}SharedStm;
#define SharedStm_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(SharedStm_SharedTop, SharedStm_SharedTop), ),\
}
/** @class MainStm
 * @extends HdStateMachine
 */
typedef struct tagMainStm {
    HdStateMachine base;
    SharedStm S6SharedStm;                                      
    S82Stm S82S82Stm;                                           
    S83Stm S83S83Stm;                                           
    SharedStm S9SharedStm;                                      
    UINT32 nS4History;
    UINT32 nS7History;
#define MainStm_MainTop_Dmy                     ( 1 <<  9 )
#define MainStm_MainTop                         ( MainStm_MainTop_Dmy | MainStm_S1 | MainStm_S2 | MainStm_S3 | MainStm_S4 | MainStm_S6 | MainStm_S8 | MainStm_S7 | MainStm_S10 | MainStm_S5 | MainStm_S9 )
#define MainStm_InitPt0                         ( 1 << ( 31 -  0 ) )
#define MainStm_S1                              ( 1 << 10 )
#define MainStm_S21                             ( 1 << 11 )
#define MainStm_S22                             ( 1 << 12 )
#define MainStm_InitPt1                         ( 1 << ( 31 -  1 ) )
#define MainStm_S3                              ( 1 << 13 )
#define MainStm_S41                             ( 1 << 14 )
#define MainStm_S42                             ( 1 << 15 )
#define MainStm_InitPt2                         ( 1 << ( 31 -  2 ) )
#define MainStm_Junction                        ( 1 << ( 31 -  3 ) )
#define MainStm_S6                              ( 1 << 16 )
#define MainStm_InitPt4                         ( 1 << ( 31 -  4 ) )
#define MainStm_S811                            ( 1 << 17 )
#define MainStm_S813                            ( 1 << 18 )
#define MainStm_S812                            ( 1 << 19 )
#define MainStm_InitPt3                         ( 1 << ( 31 -  5 ) )
#define MainStm_S71                             ( 1 << 20 )
#define MainStm_S72                             ( 1 << 21 )
#define MainStm_S10                             ( 1 << 22 )
#define MainStm_S5                              ( 1 << 23 )
#define MainStm_S9                              ( 1 << 24 )
#define MainStm_S2_Dmy                          ( 1 << 25 )
#define MainStm_S2                              ( MainStm_S2_Dmy | MainStm_S21 | MainStm_S22 )
#define MainStm_S4_Dmy                          ( 1 << 26 )
#define MainStm_S4                              ( MainStm_S4_Dmy | MainStm_S41 | MainStm_S42 )
#define MainStm_S8_Dmy                          ( 1 << 27 )
#define MainStm_S8                              ( MainStm_S8_Dmy | MainStm_S811 | MainStm_S813 | MainStm_S812 )
#define MainStm_S7_Dmy                          ( 1 << 28 )
#define MainStm_S7                              ( MainStm_S7_Dmy | MainStm_S71 | MainStm_S72 )
}MainStm;
#define MainStm_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(MainStm_MainTop, MainStm_MainTop), ),\
    .S6SharedStm = SharedStm_Init(),\
    .S82S82Stm = S82Stm_Init(),\
    .S83S83Stm = S83Stm_Init(),\
    .S9SharedStm = SharedStm_Init(),\
}
BOOL ContextImpl_EventProc( ContextImpl* pContextImpl, ContextImpl_EVENT nEventId, void* pEventParams );
BOOL ContextImpl_Start( ContextImpl* pContextImpl );
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
