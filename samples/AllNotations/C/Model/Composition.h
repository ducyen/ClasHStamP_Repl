#ifndef __Composition_H__
#define __Composition_H__
typedef struct tagComposition Composition;
#endif//__Composition_H__
#if !defined( Composition_Init ) && ( defined( __Composition_INTERNAL__ )  )
/** @memberof Composition
 * @brief Composition auto-generated constructor
 */
#define Composition_Init(_attribute4)\
    .attribute4 = _attribute4,\

#define Composition_Ctor( InitFunc, optionParams )    ( Composition ){\
    InitFunc\
\
}
Composition* Composition_Copy( Composition* pComposition, const Composition* pSource );
/** @class Composition
 * @extends 
 */
#define Composition_CLASS                                                                       \
    size_t cbSize;                                                                              \
    int attribute4;                                                                                                           \

typedef struct tagComposition{
    Composition_CLASS    
}Composition;
#endif//__Composition_INTERNAL__
