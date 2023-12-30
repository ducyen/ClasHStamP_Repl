#ifndef __ContextImpl_H__
#define __ContextImpl_H__
#include "Context.h"
typedef struct tagContextImpl ContextImpl;
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
/** @class S111Stm
 * @extends HdStateMachine
 */
typedef struct tagS111Stm {
    HdStateMachine base;
#define S111Stm_S111Top_Dmy                     ( 1 <<  0 )
#define S111Stm_S111Top                         ( S111Stm_S111Top_Dmy | S111Stm_S14 | S111Stm_S15 )
#define S111Stm_Entry1                          ( 1 << ( 31 -  0 ) )
#define S111Stm_S14                             ( 1 <<  1 )
#define S111Stm_InitPt                          ( 1 << ( 31 -  1 ) )
#define S111Stm_S15                             ( 1 <<  2 )
}S111Stm;
#define S111Stm_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(S111Stm_S111Top, S111Stm_S111Top) ),\
}
/** @class S112Stm
 * @extends HdStateMachine
 */
typedef struct tagS112Stm {
    HdStateMachine base;
#define S112Stm_S112Top_Dmy                     ( 1 <<  3 )
#define S112Stm_S112Top                         ( S112Stm_S112Top_Dmy | S112Stm_S16 | S112Stm_S17 )
#define S112Stm_S16                             ( 1 <<  4 )
#define S112Stm_S17                             ( 1 <<  5 )
#define S112Stm_Entry1                          ( 1 << ( 31 -  0 ) )
#define S112Stm_InitPt                          ( 1 << ( 31 -  1 ) )
#define S112Stm_Entry2                          ( 1 << ( 31 -  2 ) )
}S112Stm;
#define S112Stm_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(S112Stm_S112Top, S112Stm_S112Top) ),\
}
/** @class S18Stm
 * @extends HdStateMachine
 */
typedef struct tagS18Stm {
    HdStateMachine base;
#define S18Stm_S18Top_Dmy                       ( 1 <<  6 )
#define S18Stm_S18Top                           ( S18Stm_S18Top_Dmy | S18Stm_S181 | S18Stm_S182 )
#define S18Stm_Entry1                           ( 1 << ( 31 -  0 ) )
#define S18Stm_Exit1                            ( 1 << ( 31 -  1 ) )
#define S18Stm_InitPt                           ( 1 << ( 31 -  2 ) )
#define S18Stm_S181                             ( 1 <<  7 )
#define S18Stm_S182                             ( 1 <<  8 )
}S18Stm;
#define S18Stm_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(S18Stm_S18Top, S18Stm_S18Top) ),\
}
/** @class MainStm
 * @extends HdStateMachine
 */
typedef struct tagMainStm {
    HdStateMachine base;
    S18Stm S18S18Stm;                                           
    S111Stm S111S111Stm;                                        
    S112Stm S112S112Stm;                                        
    UINT32 nS6History;
    UINT32 nS9History;
#define MainStm_StmTop_Dmy                      ( 1 <<  9 )
#define MainStm_StmTop                          ( MainStm_StmTop_Dmy | MainStm_S1 | MainStm_S2 | MainStm_S5 | MainStm_S6 | MainStm_S18 | MainStm_S11 | MainStm_S9 | MainStm_S19 | MainStm_S20 | MainStm_S10 )
#define MainStm_InitPt                          ( 1 << ( 31 -  0 ) )
#define MainStm_S1                              ( 1 << 10 )
#define MainStm_S3                              ( 1 << 11 )
#define MainStm_S4                              ( 1 << 12 )
#define MainStm_S5                              ( 1 << 13 )
#define MainStm_S7                              ( 1 << 14 )
#define MainStm_S8                              ( 1 << 15 )
#define MainStm_Junction                        ( 1 << ( 31 -  1 ) )
#define MainStm_S18                             ( 1 << 16 )
#define MainStm_S12                             ( 1 << 17 )
#define MainStm_S13                             ( 1 << 18 )
#define MainStm_S91                             ( 1 << 19 )
#define MainStm_S92                             ( 1 << 20 )
#define MainStm_S19                             ( 1 << 21 )
#define MainStm_S20                             ( 1 << 22 )
#define MainStm_S10                             ( 1 << 23 )
#define MainStm_S2_Dmy                          ( 1 << 24 )
#define MainStm_S2                              ( MainStm_S2_Dmy | MainStm_S3 | MainStm_S4 )
#define MainStm_S6_Dmy                          ( 1 << 25 )
#define MainStm_S6                              ( MainStm_S6_Dmy | MainStm_S7 | MainStm_S8 )
#define MainStm_S11_Dmy                         ( 1 << 26 )
#define MainStm_S11                             ( MainStm_S11_Dmy | MainStm_S12 | MainStm_S13 )
#define MainStm_S9_Dmy                          ( 1 << 27 )
#define MainStm_S9                              ( MainStm_S9_Dmy | MainStm_S91 | MainStm_S92 )
}MainStm;
#define MainStm_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(MainStm_StmTop, MainStm_StmTop) ),\
    .S18S18Stm = S18Stm_Init(),\
    .S111S111Stm = S111Stm_Init(),\
    .S112S112Stm = S112Stm_Init(),\
}
/** @memberof ContextImpl
 * @brief ContextImpl auto-generated constructor
 */
#define ContextImpl_Init(_attribute0, _aComposition)\
    Context_Init( P( _attribute0 ), P( _aComposition ) )\
    .attribute2 = 123,\
    .attribute3 = 789,\
    .mainStm = MainStm_Init(),\

#define ContextImpl_Ctor( InitFunc, optionParams )    ( ContextImpl ){\
    InitFunc\
\
}
Context* ContextImpl_Copy( ContextImpl* pContextImpl, const ContextImpl* pSource );
/** @class ContextImpl
 * @extends Context
 */
#define ContextImpl_CLASS                                                                       \
    Context_CLASS                                                                               \
    int attribute2;                                                                                                           \
    int attribute3;                                                                                                           \
    MainStm mainStm;                                            

typedef struct tagContextImpl{
    ContextImpl_CLASS    
}ContextImpl;
BOOL ContextImpl_EventProc( ContextImpl* pContextImpl, ContextImpl_EVENT nEventId, void* pEventParams );
BOOL ContextImpl_Start( ContextImpl* pContextImpl );
#endif//__ContextImpl_INTERNAL__
