/* File generated by Đức's ClasHStamP */
using System;                                                   
using System.Collections.Generic;
using boolean = System.Boolean;
using Model;
using Interfaces;
namespace Model {
    public  class Context: BaseClass, Interface2, Interface1
    {
        public override void virtualFunc(
            int param0
        ){
            Console.WriteLine("Hi, How are you");
            Console.WriteLine("One more line");                
        } /* Context.virtualFunc */

        public  static void staticFunc(
        ){
                    
        } /* Context.staticFunc */
        public void leafFunc(
        ){
        } /* Context.leafFunc */
        public void operation1(
        ){
            
        } /* Context.operation1 */
        public void operation2(
        ){
            
        } /* Context.operation2 */
        public  Context(
            int _attribute0,
            Composition _aComposition
        ):  base(  )
        {
            attribute1 = 345;
            attribute0 = _attribute0;
            anAggregation = null;
            aComposition = _aComposition;
        }                                                                                       
        private int attribute1;                                 
        private int attribute0;                                 
        private   Aggregration anAggregation;                   
        private Composition aComposition;                       
    }
}
