#ifndef __Mocha_H__
#define __Mocha_H__
#include "CondimentDecorator.h"
typedef struct tagMocha Mocha;
String Mocha_GetDescription( const Mocha* pMocha );
#endif//__Mocha_H__
#if !defined( Mocha_Init ) && ( defined( __Mocha_INTERNAL__ )  || defined( __Main_INTERNAL__ )  )
#define __CondimentDecorator_INTERNAL__
#include "CondimentDecorator.h"
/** @memberof Mocha
 * @brief Mocha auto-generated constructor
 */
#define Mocha_Init(_beverage)\
    CondimentDecorator_Init( P( _beverage ) )\
    .vTbl = &gMochaVtbl,\

#define Mocha_Ctor( InitFunc, optionParams )    ( Mocha ){\
    InitFunc\
    .description = StrCat(optionParams->description, ", Mocha")\
}
extern const BeverageVtbl gMochaVtbl;
CondimentDecorator* Mocha_Copy( Mocha* pMocha, const Mocha* pSource );
/** @class Mocha
 * @extends CondimentDecorator
 */
#define Mocha_CLASS                                                                             \
    CondimentDecorator_CLASS                                                                    \

typedef struct tagMocha{
    Mocha_CLASS    
}Mocha;
#endif//__Mocha_INTERNAL__
