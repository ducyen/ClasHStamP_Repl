#ifndef __HouseBlend_H__
#define __HouseBlend_H__
#include "Beverage.h"
typedef struct tagHouseBlend HouseBlend;
#endif//__HouseBlend_H__
#if !defined( HouseBlend_Init ) && ( defined( __HouseBlend_INTERNAL__ )  || defined( __Main_INTERNAL__ )  )
#define __Beverage_INTERNAL__
#include "Beverage.h"
/** @memberof HouseBlend
 * @brief HouseBlend auto-generated constructor
 */
#define HouseBlend_Init()\
    Beverage_Init( P( MakeString( "House Blend" ) ) )\
    .vTbl = &gHouseBlendVtbl,\

#define HouseBlend_Ctor( InitFunc, optionParams )    ( HouseBlend ){\
    InitFunc\
\
}
extern const BeverageVtbl gHouseBlendVtbl;
Beverage* HouseBlend_Copy( HouseBlend* pHouseBlend, const HouseBlend* pSource );
/** @class HouseBlend
 * @extends Beverage
 */
#define HouseBlend_CLASS                                                                        \
    Beverage_CLASS                                                                              \

typedef struct tagHouseBlend{
    HouseBlend_CLASS    
}HouseBlend;
#endif//__HouseBlend_INTERNAL__
