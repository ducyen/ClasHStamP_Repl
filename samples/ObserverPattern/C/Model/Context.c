/* File generated by Đức's ClasHStamP */
#define __Context_INTERNAL__
#include "CommonInclude.h"
#include "Context.h"
Context* Context_Copy( Context* pContext, const Context* pSource ){
    pContext->attribute0 = pSource->attribute0;
    return ( Context* )pContext;
}
