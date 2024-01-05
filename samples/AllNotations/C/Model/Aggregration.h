#ifndef __Aggregration_H__
#define __Aggregration_H__
typedef struct tagAggregration Aggregration;
#endif//__Aggregration_H__
#if !defined( Aggregration_Init ) && ( defined( __Aggregration_INTERNAL__ )  )
/** @memberof Aggregration
 * @brief Aggregration auto-generated constructor
 */
#define Aggregration_Init(_attribute2)\
    .attribute2 = _attribute2,\

#define Aggregration_Ctor( InitFunc, optionParams )    ( Aggregration ){\
    InitFunc\
\
}
Aggregration* Aggregration_Copy( Aggregration* pAggregration, const Aggregration* pSource );
/** @class Aggregration
 * @extends 
 */
#define Aggregration_CLASS                                                                      \
    size_t cbSize;                                                                              \
    int attribute2;                                                                                                           \

typedef struct tagAggregration{
    Aggregration_CLASS    
}Aggregration;
#endif//__Aggregration_INTERNAL__
