#ifndef __Context_H__
#define __Context_H__
#include "BaseClass.h"
#include "Interface2.h"
#include "Interface1.h"
#include "Composition.h"
#include "Aggregration.h"
#include "UsedDependency.h"
typedef struct tagContext Context;
void Context_staticFunc(  );
void Context_leafFunc( Context* pContext );
void Context_operation1( Context* pContext );
void Context_operation2( Context* pContext );
#endif//__Context_H__
#if !defined( Context_Init ) && ( defined( __Context_INTERNAL__ )  || defined( __Main_INTERNAL__ )  )
#define __BaseClass_INTERNAL__
#include "BaseClass.h"
#define __Interface2_INTERNAL__
#include "Interface2.h"
#define __Interface1_INTERNAL__
#include "Interface1.h"
#include "Aggregration.h"
#define __Composition_INTERNAL__
#include "Composition.h"
/** @memberof Context
 * @brief Context auto-generated constructor
 */
#define Context_Init(_attribute0, _aComposition)\
    BaseClass_Init(  )\
    .vTbl = &gContextVtbl,\
    .attribute1 = 345,\
    .attribute0 = _attribute0,\
    .anAggregation = null,\
    .aComposition = P( _aComposition ),\

#define Context_Ctor( InitFunc, optionParams )    ( Context ){\
    InitFunc\
\
}
extern const BaseClassVtbl gContextVtbl;
BaseClass* Context_Copy( Context* pContext, const Context* pSource );
/** @class Context
 * @extends BaseClass
 */
#define Context_CLASS                                                                           \
    BaseClass_CLASS                                                                             \
    int attribute1;                                                                                                           \
    int attribute0;                                                                                                           \
    Aggregration* anAggregation;                                \
    Composition aComposition;                                   \

typedef struct tagContext{
    Context_CLASS    
}Context;
#endif//__Context_INTERNAL__
