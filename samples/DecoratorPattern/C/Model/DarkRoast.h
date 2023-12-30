#ifndef __DarkRoast_H__
#define __DarkRoast_H__
#include "Beverage.h"
typedef struct tagDarkRoast DarkRoast;
#endif//__DarkRoast_H__
#if !defined( DarkRoast_Init ) && ( defined( __DarkRoast_INTERNAL__ )  || defined( __Main_INTERNAL__ )  )
#define __Beverage_INTERNAL__
#include "Beverage.h"
/** @memberof DarkRoast
 * @brief DarkRoast auto-generated constructor
 */
#define DarkRoast_Init()\
    Beverage_Init( P( MakeString( "Dark Roast" ) ) )\
    .vTbl = &gDarkRoastVtbl,\

#define DarkRoast_Ctor( InitFunc, optionParams )    ( DarkRoast ){\
    InitFunc\
\
}
extern const BeverageVtbl gDarkRoastVtbl;
Beverage* DarkRoast_Copy( DarkRoast* pDarkRoast, const DarkRoast* pSource );
/** @class DarkRoast
 * @extends Beverage
 */
#define DarkRoast_CLASS                                                                         \
    Beverage_CLASS                                                                              \

typedef struct tagDarkRoast{
    DarkRoast_CLASS    
}DarkRoast;
#endif//__DarkRoast_INTERNAL__
