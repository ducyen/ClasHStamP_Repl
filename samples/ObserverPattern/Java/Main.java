import model.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		WeatherData weatherData = new WeatherData();
		
		CurrentConditionDisplay currentDisplay = new CurrentConditionDisplay(weatherData);
		
		weatherData.setMeasurements(27, 65, 30.4f);
		weatherData.setMeasurements(28, 70, 29.2f);
		weatherData.setMeasurements(26, 90, 29.2f);
	}

}
