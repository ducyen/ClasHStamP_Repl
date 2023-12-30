#ifndef __Context_H__
#define __Context_H__
typedef struct tagContext Context;
#endif//__Context_H__
#if !defined( Context_Init ) && ( defined( __Context_INTERNAL__ )  || defined( __Main_INTERNAL__ )  )
/** @memberof Context
 * @brief Context auto-generated constructor
 */
#define Context_Init(_attribute0)\
    .attribute0 = _attribute0,\

#define Context_Ctor( InitFunc, optionParams )    ( Context ){\
    InitFunc\
\
}
Context* Context_Copy( Context* pContext, const Context* pSource );
/** @class Context
 * @extends 
 */
#define Context_CLASS                                                                           \
    size_t cbSize;                                                                              \
    int attribute0;                                                                                                           \

typedef struct tagContext{
    Context_CLASS    
}Context;
#endif//__Context_INTERNAL__
