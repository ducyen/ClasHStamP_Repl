#ifndef __Interface1_H__
#define __Interface1_H__
typedef struct tagInterface1 Interface1;
void Interface1_operation1( Interface1* pInterface1 );
#endif//__Interface1_H__
#if !defined( Interface1_Init ) && ( defined( __Interface1_INTERNAL__ )  )
/** @memberof Interface1
 * @brief Interface1 auto-generated constructor
 */
#define Interface1_Init()\

#define Interface1_Ctor( InitFunc, optionParams )    ( Interface1 ){\
    InitFunc\
\
}
typedef struct tagInterface1Vtbl{
    void ( * const poperation1 )( Interface1* );
}Interface1Vtbl;
Interface1* Interface1_Copy( Interface1* pInterface1, const Interface1* pSource );
/** @class Interface1
 * @extends 
 */
#define Interface1_CLASS                                                                        \
    const Interface1Vtbl* const vTbl;                                                           \
    size_t cbSize;                                                                              \

typedef struct tagInterface1{
    Interface1_CLASS    
}Interface1;
#endif//__Interface1_INTERNAL__
