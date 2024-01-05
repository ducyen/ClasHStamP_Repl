#ifndef __BaseClass_H__
#define __BaseClass_H__
typedef struct tagBaseClass BaseClass;
void BaseClass_publicMethod( BaseClass* pBaseClass );
#endif//__BaseClass_H__
#if !defined( BaseClass_Init ) && ( defined( __BaseClass_INTERNAL__ )  )
void BaseClass_protectedMethod( BaseClass* pBaseClass );
void BaseClass_packageVisibleMethod( BaseClass* pBaseClass );
/** @memberof BaseClass
 * @brief BaseClass auto-generated constructor
 */
#define BaseClass_Init(_derivableAttribute)\
    .derivableAttribute = _derivableAttribute,\

#define BaseClass_Ctor( InitFunc, optionParams )    ( BaseClass ){\
    InitFunc\
\
}
typedef struct tagBaseClassVtbl{
    void ( * const ppublicMethod )( BaseClass* );
    void ( * const pprotectedMethod )( BaseClass* );
    void ( * const ppackageVisibleMethod )( BaseClass* );
}BaseClassVtbl;
BaseClass* BaseClass_Copy( BaseClass* pBaseClass, const BaseClass* pSource );
/** @class BaseClass
 * @extends 
 */
#define BaseClass_CLASS                                                                         \
    const BaseClassVtbl* const vTbl;                                                            \
    size_t cbSize;                                                                              \
    int derivableAttribute;                                                                                           \

typedef struct tagBaseClass{
    BaseClass_CLASS    
}BaseClass;
#endif//__BaseClass_INTERNAL__
