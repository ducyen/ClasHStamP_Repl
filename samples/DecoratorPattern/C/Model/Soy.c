/* File generated by Đức's ClasHStamP */
#define __Soy_INTERNAL__
#include "CommonInclude.h"
#include "Soy.h"
/** @public @memberof Soy */
static double Soy_cost(
    Soy* pSoy
){
    return .15 + Beverage_cost(pSoy->beverage);
} /* Soy_cost */

String Soy_GetDescription( const Soy* pSoy ){
return MakeString( "This sample does not use this as polymorphism property. Instead, it uses constructor code to do it." );
}
CondimentDecorator* Soy_Copy( Soy* pSoy, const Soy* pSource ){
    CondimentDecorator_Copy( ( CondimentDecorator* )pSoy, ( CondimentDecorator* )pSource );
    return ( Beverage* )pSoy;
}
const BeverageVtbl gSoyVtbl = {
    .pcost                       = Soy_cost,
};
