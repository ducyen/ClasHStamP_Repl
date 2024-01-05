#ifndef __Context_H__
#define __Context_H__
#include "BaseClass.h"
#include "Interface2.h"
#include "Interface1.h"
#include "Composition.h"
#include "Aggregration.h"
#include "UsedDependency.h"
typedef struct tagContext Context;
void Context_classOrStaticMethod(  );
 Context_Context( Context* pContext );
void Context_methodWithParams( Context* pContext, String parm1, float parm2 );
UsedDependency* Context_methodReturnsSomething( Context* pContext );
void Context_methodThrowsException( Context* pContext );
void Context_finalMethod( Context* pContext );
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
#define Context_Init(_derivableAttribute, _publicAttribute, _privateAttribute, _internalAttribute, _readOnlyAttribute, _anAggregation, _aProtectedComposition)\
    BaseClass_Init( P( _derivableAttribute ) )\
    .vTbl = &gContextVtbl,\
    .publicAttribute = _publicAttribute,\
    .privateAttribute = _privateAttribute,\
    .internalAttribute = _internalAttribute,\
    .isInitializedAttribute = true,\
    .readOnlyAttribute = _readOnlyAttribute,\
    .anAggregation = P( _anAggregation ),\
    .aProtectedComposition = P( _aProtectedComposition ),\

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
    String publicAttribute;                                                                                           \
    int privateAttribute;                                                                                               \
    int internalAttribute;                                                                                             \
    boolean isInitializedAttribute;                                                                           \
    const int readOnlyAttribute;                                \
    Aggregration* anAggregation[ 3 ];                           \
    Composition aProtectedComposition[ 10 ];                    \

typedef struct tagContext{
    Context_CLASS    
}Context;
#endif//__Context_INTERNAL__
