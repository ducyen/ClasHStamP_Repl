#ifndef __Beverage_H__
#define __Beverage_H__
typedef struct tagBeverage Beverage;
double Beverage_cost( Beverage* pBeverage );
String Beverage_GetDescription( const Beverage* pBeverage );
void Beverage_SetDescription( Beverage* pBeverage, String value );
#endif//__Beverage_H__
#if !defined( Beverage_Init ) && ( defined( __Beverage_INTERNAL__ )  || defined( __Main_INTERNAL__ )  )
/** @memberof Beverage
 * @brief Beverage auto-generated constructor
 */
#define Beverage_Init(_description)\
    .description = _description,\

#define Beverage_Ctor( InitFunc, optionParams )    ( Beverage ){\
    InitFunc\
\
}
typedef struct tagBeverageVtbl{
    double ( * const pcost )( Beverage* );
}BeverageVtbl;
Beverage* Beverage_Copy( Beverage* pBeverage, const Beverage* pSource );
/** @class Beverage
 * @extends 
 */
#define Beverage_CLASS                                                                          \
    const BeverageVtbl* const vTbl;                                                             \
    size_t cbSize;                                                                              \
    String description;                                                                                                   \

typedef struct tagBeverage{
    Beverage_CLASS    
}Beverage;
#endif//__Beverage_INTERNAL__
