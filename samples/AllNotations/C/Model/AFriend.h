#ifndef __AFriend_H__
#define __AFriend_H__
#include "Composition.h"
#include "Aggregration.h"
typedef struct tagAFriend AFriend;
#endif//__AFriend_H__
#if !defined( AFriend_Init ) && ( defined( __AFriend_INTERNAL__ )  )
/** @memberof AFriend
 * @brief AFriend auto-generated constructor
 */
#define AFriend_Init(_attribute3)\
    .attribute3 = _attribute3,\

#define AFriend_Ctor( InitFunc, optionParams )    ( AFriend ){\
    InitFunc\
\
}
AFriend* AFriend_Copy( AFriend* pAFriend, const AFriend* pSource );
/** @class AFriend
 * @extends 
 */
#define AFriend_CLASS                                                                           \
    size_t cbSize;                                                                              \
    int attribute3;                                                                                                           \

typedef struct tagAFriend{
    AFriend_CLASS    
}AFriend;
#endif//__AFriend_INTERNAL__
