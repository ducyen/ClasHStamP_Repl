#pragma once
/* File generated by Đức's ClasHStamP */
#include "Generic/CommonInclude.h"
#include "Abstracts/BaseClass.hpp"                              
#include "Interfaces/Interface2.hpp"                            
#include "Interfaces/Interface1.hpp"                            
#include "Model/Composition.hpp"                                
#include "Model/Aggregration.hpp"                               
#include "Model/CalledDependency.hpp"                           
#include "Model/UsedDependency.hpp"                             

class Context: public BaseClass, public Interface2, public Interface1{
    private: static int classOrStaticAttribute;                 
    private: static std::vector<int> initializedStaticArray;    
    private: static const int finalConstantAttribute = 5;       
    public:  static void classOrStaticMethod(
    ){
    } /* Context.classOrStaticMethod */
    public: virtual void publicMethod(
    ){
    } /* Context.publicMethod */
    private: void privateLeafMethod(
    ){
    } /* Context.privateLeafMethod */
    public:  Context(
    ): BaseClass(3), readOnlyAttribute(5){
        std::cout << "Manual Constructor" << std::endl;
    } /* Context.Context */
    public: void methodWithParams(
        String parm1,
        float parm2
    ){
    } /* Context.methodWithParams */
    public: UsedDependency methodReturnsSomething(
    ){
    } /* Context.methodReturnsSomething */
    public: void methodThrowsException(
    ){
    } /* Context.methodThrowsException */
    public: void finalMethod(
    ){
    } /* Context.finalMethod */
    protected: virtual int& setDerivableAttribute(const int& value) {
        return privateAttribute = value;
    };
    friend class Main;
    protected: virtual void protectedMethod(
    ){
    } /* Context.protectedMethod */

    protected: virtual void packageVisibleMethod(
    ){
    } /* Context.packageVisibleMethod */

    public:  Context(
        int _derivableAttribute,
        String _publicAttribute,
        int _privateAttribute,
        int _internalAttribute,
        int _readOnlyAttribute,
        std::vector<Composition*> &_aProtectedComposition
    ):  BaseClass( _derivableAttribute ),
        publicAttribute( _publicAttribute ),
        privateAttribute( _privateAttribute ),
        internalAttribute( _internalAttribute ),
        isInitializedAttribute( true ),
        readOnlyAttribute( _readOnlyAttribute ),
        anAggregation(   ),
        aProtectedComposition( _aProtectedComposition )
    {
    }                                                                                           
    public: String publicAttribute;                             
    private: int privateAttribute;                              
    public: int internalAttribute;                              
    private: boolean isInitializedAttribute;                    
    private: const int readOnlyAttribute;                       
    private: std::vector<Aggregration*> anAggregation;          
    protected: std::vector<Composition*> aProtectedComposition; 
};
