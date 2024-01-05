#ifndef __CalledDependency_H__
#define __CalledDependency_H__
typedef struct tagCalledDependency CalledDependency;
#endif//__CalledDependency_H__
#if !defined( CalledDependency_Init ) && ( defined( __CalledDependency_INTERNAL__ )  )
/** @memberof CalledDependency
 * @brief CalledDependency auto-generated constructor
 */
#define CalledDependency_Init(_attribute0)\
    .attribute0 = _attribute0,\

#define CalledDependency_Ctor( InitFunc, optionParams )    ( CalledDependency ){\
    InitFunc\
\
}
CalledDependency* CalledDependency_Copy( CalledDependency* pCalledDependency, const CalledDependency* pSource );
/** @class CalledDependency
 * @extends 
 */
#define CalledDependency_CLASS                                                                  \
    size_t cbSize;                                                                              \
    int attribute0;                                                                                                           \

typedef struct tagCalledDependency{
    CalledDependency_CLASS    
}CalledDependency;
#endif//__CalledDependency_INTERNAL__
