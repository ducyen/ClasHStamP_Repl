#ifndef __Espresso_H__
#define __Espresso_H__
#include "Beverage.h"
typedef struct tagEspresso Espresso;
#endif//__Espresso_H__
#if !defined( Espresso_Init ) && ( defined( __Espresso_INTERNAL__ )  || defined( __Main_INTERNAL__ )  )
#define __Beverage_INTERNAL__
#include "Beverage.h"
/** @memberof Espresso
 * @brief Espresso auto-generated constructor
 */
#define Espresso_Init()\
    Beverage_Init( P( MakeString( "Espresso" ) ) )\
    .vTbl = &gEspressoVtbl,\

#define Espresso_Ctor( InitFunc, optionParams )    ( Espresso ){\
    InitFunc\
\
}
extern const BeverageVtbl gEspressoVtbl;
Beverage* Espresso_Copy( Espresso* pEspresso, const Espresso* pSource );
/** @class Espresso
 * @extends Beverage
 */
#define Espresso_CLASS                                                                          \
    Beverage_CLASS                                                                              \

typedef struct tagEspresso{
    Espresso_CLASS    
}Espresso;
#endif//__Espresso_INTERNAL__
