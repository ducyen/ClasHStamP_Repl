#ifndef __Interface2_H__
#define __Interface2_H__
typedef struct tagInterface2 Interface2;
void Interface2_operation2( Interface2* pInterface2 );
#endif//__Interface2_H__
#if !defined( Interface2_Init ) && ( defined( __Interface2_INTERNAL__ )  )
/** @memberof Interface2
 * @brief Interface2 auto-generated constructor
 */
#define Interface2_Init()\

#define Interface2_Ctor( InitFunc, optionParams )    ( Interface2 ){\
    InitFunc\
\
}
typedef struct tagInterface2Vtbl{
    void ( * const poperation2 )( Interface2* );
}Interface2Vtbl;
Interface2* Interface2_Copy( Interface2* pInterface2, const Interface2* pSource );
/** @class Interface2
 * @extends 
 */
#define Interface2_CLASS                                                                        \
    const Interface2Vtbl* const vTbl;                                                           \
    size_t cbSize;                                                                              \

typedef struct tagInterface2{
    Interface2_CLASS    
}Interface2;
#endif//__Interface2_INTERNAL__
