#ifndef __UsedDependency_H__
#define __UsedDependency_H__
typedef struct tagUsedDependency UsedDependency;
#endif//__UsedDependency_H__
#if !defined( UsedDependency_Init ) && ( defined( __UsedDependency_INTERNAL__ )  )
/** @memberof UsedDependency
 * @brief UsedDependency auto-generated constructor
 */
#define UsedDependency_Init(_attribute1)\
    .attribute1 = _attribute1,\

#define UsedDependency_Ctor( InitFunc, optionParams )    ( UsedDependency ){\
    InitFunc\
\
}
UsedDependency* UsedDependency_Copy( UsedDependency* pUsedDependency, const UsedDependency* pSource );
/** @class UsedDependency
 * @extends 
 */
#define UsedDependency_CLASS                                                                    \
    size_t cbSize;                                                                              \
    int attribute1;                                                                                                           \

typedef struct tagUsedDependency{
    UsedDependency_CLASS    
}UsedDependency;
#endif//__UsedDependency_INTERNAL__
