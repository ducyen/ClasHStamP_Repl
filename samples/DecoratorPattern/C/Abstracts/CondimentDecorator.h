#ifndef __CondimentDecorator_H__
#define __CondimentDecorator_H__
#include "Beverage.h"
typedef struct tagCondimentDecorator CondimentDecorator;
#endif//__CondimentDecorator_H__
#if !defined( CondimentDecorator_Init ) && ( defined( __CondimentDecorator_INTERNAL__ )  )
#define __Beverage_INTERNAL__
#include "Beverage.h"
/** @memberof CondimentDecorator
 * @brief CondimentDecorator auto-generated constructor
 */
#define CondimentDecorator_Init(_beverage)\
    Beverage_Init( P( MakeString( "Unknown Beverage" ) ) )\
    .beverage = _beverage,\

#define CondimentDecorator_Ctor( InitFunc, optionParams )    ( CondimentDecorator ){\
    InitFunc\
\
}
Beverage* CondimentDecorator_Copy( CondimentDecorator* pCondimentDecorator, const CondimentDecorator* pSource );
/** @class CondimentDecorator
 * @extends Beverage
 */
#define CondimentDecorator_CLASS                                                                \
    Beverage_CLASS                                                                              \
    Beverage* beverage;                                         \

typedef struct tagCondimentDecorator{
    CondimentDecorator_CLASS    
}CondimentDecorator;
#endif//__CondimentDecorator_INTERNAL__
