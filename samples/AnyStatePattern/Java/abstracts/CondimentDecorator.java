package abstracts;

import abstracts.*;

public  abstract class CondimentDecorator extends Beverage
{
    public  CondimentDecorator(
        Beverage _beverage
    ) {
        super( "Unknown Beverage" );

        beverage = _beverage;
    }                                                                                           
    protected  Beverage beverage;                                 
}
