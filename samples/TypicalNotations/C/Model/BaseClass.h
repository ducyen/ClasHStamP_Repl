#ifndef __BaseClass_H__
#define __BaseClass_H__
typedef struct tagBaseClass BaseClass;
void BaseClass_virtualFunc( BaseClass* pBaseClass, int param0 );
#endif//__BaseClass_H__
#if !defined( BaseClass_Init ) && ( defined( __BaseClass_INTERNAL__ )  )
/** @memberof BaseClass
 * @brief BaseClass auto-generated constructor
 */
#define BaseClass_Init()\

#define BaseClass_Ctor( InitFunc, optionParams )    ( BaseClass ){\
    InitFunc\
\
}
typedef struct tagBaseClassVtbl{
    void ( * const pvirtualFunc )( BaseClass*, int );
}BaseClassVtbl;
BaseClass* BaseClass_Copy( BaseClass* pBaseClass, const BaseClass* pSource );
/** @class BaseClass
 * @extends 
 */
#define BaseClass_CLASS                                                                         \
    const BaseClassVtbl* const vTbl;                                                            \
    size_t cbSize;                                                                              \

typedef struct tagBaseClass{
    BaseClass_CLASS    
}BaseClass;
#endif//__BaseClass_INTERNAL__
