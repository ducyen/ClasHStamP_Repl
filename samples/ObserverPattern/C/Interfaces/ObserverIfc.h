#ifndef __ObserverIfc_H__
#define __ObserverIfc_H__
typedef struct tagObserverIfc ObserverIfc;
void ObserverIfc_update( ObserverIfc* pObserverIfc, float temperature, float humidity, float pressure );
#endif//__ObserverIfc_H__
#if !defined( ObserverIfc_Init ) && ( defined( __ObserverIfc_INTERNAL__ )  )
/** @memberof ObserverIfc
 * @brief ObserverIfc auto-generated constructor
 */
#define ObserverIfc_Init()\

#define ObserverIfc_Ctor( InitFunc, optionParams )    ( ObserverIfc ){\
    InitFunc\
\
}
typedef struct tagObserverIfcVtbl{
    void ( * const pupdate )( ObserverIfc*, float, float, float );
}ObserverIfcVtbl;
ObserverIfc* ObserverIfc_Copy( ObserverIfc* pObserverIfc, const ObserverIfc* pSource );
/** @class ObserverIfc
 * @extends 
 */
#define ObserverIfc_CLASS                                                                       \
    const ObserverIfcVtbl* const vTbl;                                                          \
    size_t cbSize;                                                                              \

typedef struct tagObserverIfc{
    ObserverIfc_CLASS    
}ObserverIfc;
#endif//__ObserverIfc_INTERNAL__
