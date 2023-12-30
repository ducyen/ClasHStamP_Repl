#ifndef __Soy_H__
#define __Soy_H__
#include "CondimentDecorator.h"
typedef struct tagSoy Soy;
String Soy_GetDescription( const Soy* pSoy );
#endif//__Soy_H__
#if !defined( Soy_Init ) && ( defined( __Soy_INTERNAL__ )  || defined( __Main_INTERNAL__ )  )
#define __CondimentDecorator_INTERNAL__
#include "CondimentDecorator.h"
/** @memberof Soy
 * @brief Soy auto-generated constructor
 */
#define Soy_Init(_beverage)\
    CondimentDecorator_Init( P( _beverage ) )\
    .vTbl = &gSoyVtbl,\

#define Soy_Ctor( InitFunc, optionParams )    ( Soy ){\
    InitFunc\
    .description = StrCat(optionParams->description, ", Soy")\
}
extern const BeverageVtbl gSoyVtbl;
CondimentDecorator* Soy_Copy( Soy* pSoy, const Soy* pSource );
/** @class Soy
 * @extends CondimentDecorator
 */
#define Soy_CLASS                                                                               \
    CondimentDecorator_CLASS                                                                    \

typedef struct tagSoy{
    Soy_CLASS    
}Soy;
#endif//__Soy_INTERNAL__
