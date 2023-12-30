package abstracts;


public  abstract class Beverage
{
    public abstract double cost(
    );
    public String getDescription(){
        return description;
    }
    public void setDescription(String value){
        description = value;
    }
    public  Beverage(
        String _description
    ){
        description = _description;
    }                                                                                           
    public  String description;                                 
}
