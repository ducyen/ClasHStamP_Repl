/* File generated by Đức's ClasHStamP */
using System;                                                   
using System.Collections.Generic;
using boolean = System.Boolean;
namespace Abstracts {
    public  abstract class BaseClass
    {
        public abstract void publicMethod(
        );
        public abstract int derivableAttribute {
            set;
        }
        protected abstract void protectedMethod(
        );
        protected abstract void packageVisibleMethod(
        );
        public  BaseClass(
            int _derivableAttribute
        ){
            derivableAttribute = _derivableAttribute;
        }                                                                                       
    }
}
