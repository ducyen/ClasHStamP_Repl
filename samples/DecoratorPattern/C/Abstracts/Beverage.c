/* File generated by Đức's ClasHStamP */
#define __Beverage_INTERNAL__
#include "CommonInclude.h"
#include "Beverage.h"
/** @public @pure @memberof Beverage */
double Beverage_cost(
    Beverage* pBeverage
){
    if( pBeverage->vTbl == NULL || pBeverage->vTbl->pcost == NULL ){ return ( double )0; }
    return pBeverage->vTbl->pcost( pBeverage );
} /* Beverage_cost */

String Beverage_GetDescription( const Beverage* pBeverage ){
return pBeverage->description;
}
void Beverage_SetDescription( Beverage* pBeverage, String value ){
pBeverage->description = value;
}
Beverage* Beverage_Copy( Beverage* pBeverage, const Beverage* pSource ){
    pBeverage->description = pSource->description;
    return ( Beverage* )pBeverage;
}
