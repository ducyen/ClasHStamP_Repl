/* File generated by Đức's ClasHStamP */
#define __Espresso_INTERNAL__
#include "CommonInclude.h"
#include "Espresso.h"
/** @public @memberof Espresso */
static double Espresso_cost(
    Espresso* pEspresso
){
    return 1.99;
} /* Espresso_cost */

Beverage* Espresso_Copy( Espresso* pEspresso, const Espresso* pSource ){
    Beverage_Copy( ( Beverage* )pEspresso, ( Beverage* )pSource );
    return ( Beverage* )pEspresso;
}
const BeverageVtbl gEspressoVtbl = {
    .pcost                       = Espresso_cost,
};
