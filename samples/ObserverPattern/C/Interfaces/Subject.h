#ifndef __Subject_H__
#define __Subject_H__
#include "ObserverIfc.h"
typedef struct tagSubject Subject;
void Subject_registerObserver( Subject* pSubject, ObserverIfc* o );
void Subject_removeObserver( Subject* pSubject, ObserverIfc* o );
void Subject_notifyObserver( Subject* pSubject );
#endif//__Subject_H__
#if !defined( Subject_Init ) && ( defined( __Subject_INTERNAL__ )  )
/** @memberof Subject
 * @brief Subject auto-generated constructor
 */
#define Subject_Init()\

#define Subject_Ctor( InitFunc, optionParams )    ( Subject ){\
    InitFunc\
\
}
typedef struct tagSubjectVtbl{
    void ( * const pregisterObserver )( Subject*, ObserverIfc* );
    void ( * const premoveObserver )( Subject*, ObserverIfc* );
    void ( * const pnotifyObserver )( Subject* );
}SubjectVtbl;
Subject* Subject_Copy( Subject* pSubject, const Subject* pSource );
/** @class Subject
 * @extends 
 */
#define Subject_CLASS                                                                           \
    const SubjectVtbl* const vTbl;                                                              \
    size_t cbSize;                                                                              \

typedef struct tagSubject{
    Subject_CLASS    
}Subject;
#endif//__Subject_INTERNAL__
