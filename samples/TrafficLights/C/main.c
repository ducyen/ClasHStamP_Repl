#define __Main_INTERNAL__
#include <stdio.h>

int InputValue(char* pMsg);
void DisplayMsg(char* pMsg);

#include "CommonInclude.h"
#include "Model/ContextImpl.h"

int InputValue(char* pMsg) {
    char n;
    printf( pMsg );
    scanf_s( "%c", &n );
    char c = 0;
    while( c != '\n' ){
        scanf_s( "%c", &c );
    }
    return n - '0';
}

void DisplayMsg(char* pMsg) {
    printf( "%s\n", pMsg );
}

int main( void ){
    ContextImpl context = ContextImpl_Ctor( ContextImpl_Init( 
        4, "", 1, 2, 3, { 0 },
        Composition_Ctor( Composition_Init( 3 ) )
    ) );
    char n;
    do {
        ContextImpl_Start( &context );
        do {
            n = InputValue( "Enter event number('q': quit, 'r':restart): E" );
            EventParams* pParams = NULL;
            E1Params e1Params = { .x = Two };
            if (n == ContextImpl_E1) {
                pParams = &e1Params;
            }
            ContextImpl_EventProc( &context, (ContextImpl_EVENT)n, pParams);
        } while (n+'0' != 'q' && n+'0' != 'r');
    }while (n+'0' != 'q');
    return 0;
}

