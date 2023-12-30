#ifndef __Whip_H__
#define __Whip_H__
#include "CondimentDecorator.h"
typedef struct tagWhip Whip;
String Whip_GetDescription( const Whip* pWhip );
#endif//__Whip_H__
#if !defined( Whip_Init ) && ( defined( __Whip_INTERNAL__ )  || defined( __Main_INTERNAL__ )  )
#define __CondimentDecorator_INTERNAL__
#include "CondimentDecorator.h"
/** @memberof Whip
 * @brief Whip auto-generated constructor
 */
#define Whip_Init(_beverage)\
    CondimentDecorator_Init( P( _beverage ) )\
    .vTbl = &gWhipVtbl,\

#define Whip_Ctor( InitFunc, optionParams )    ( Whip ){\
    InitFunc\
    .description = StrCat(optionParams->description, ", Whip")\
}
extern const BeverageVtbl gWhipVtbl;
CondimentDecorator* Whip_Copy( Whip* pWhip, const Whip* pSource );
/** @class Whip
 * @extends CondimentDecorator
 */
#define Whip_CLASS                                                                              \
    CondimentDecorator_CLASS                                                                    \

typedef struct tagWhip{
    Whip_CLASS    
}Whip;
#endif//__Whip_INTERNAL__
