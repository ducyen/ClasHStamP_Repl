/* File generated by Đức's ClasHStamP */
using System;                                                   
using System.Collections.Generic;
using boolean = System.Boolean;
using Interfaces;
namespace Interfaces {
    public  interface Subject
    {
        void registerObserver(
            ObserverIfc o
        );
        void removeObserver(
            ObserverIfc o
        );
        void notifyObserver(
        );
    }
}
