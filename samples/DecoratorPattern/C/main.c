#define __Main_INTERNAL__
#include <stdio.h>
#include <string.h>
#include "CommonInclude.h"

#include "Beverage.h"
#include "DarkRoast.h"
#include "Espresso.h"
#include "HouseBlend.h"
#include "DarkRoast.h"
#include "Mocha.h"
#include "Whip.h"
#include "Soy.h"

String StrCat( String dest, char* src ){
    return strcat(dest->buf, src);
}

int main(){
    Beverage* beverage1 = ( Beverage* )&Espresso_Ctor( Espresso_Init() );
    printf( "%s $%f\n", GetCharBuf( Beverage_GetDescription( beverage1 ) ), Beverage_cost( beverage1 ) );

    Beverage* beverage2 = ( Beverage* )&DarkRoast_Ctor( DarkRoast_Init() );
    beverage2 = ( Beverage* )&Mocha_Ctor( Mocha_Init( beverage2 ), beverage2 );
    beverage2 = ( Beverage* )&Mocha_Ctor( Mocha_Init( beverage2 ), beverage2 );
    beverage2 = ( Beverage* )&Whip_Ctor( Whip_Init( beverage2 ), beverage2 );
    printf( "%s $%f\n", GetCharBuf( Beverage_GetDescription( beverage2 ) ), Beverage_cost( beverage2 ) );
    
    Beverage* beverage3 = ( Beverage* )&HouseBlend_Ctor( HouseBlend_Init() );
    beverage3 = ( Beverage* )&Soy_Ctor( Soy_Init( beverage3 ), beverage3 );
    beverage3 = ( Beverage* )&Mocha_Ctor( Mocha_Init( beverage3 ), beverage3 );
    beverage3 = ( Beverage* )&Whip_Ctor( Whip_Init( beverage3 ), beverage3 );
    printf( "%s $%f\n", GetCharBuf( Beverage_GetDescription( beverage3 ) ), Beverage_cost( beverage3 ) );

    return 0;
}
