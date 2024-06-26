//Package weather organise work for project in the same folder.
package weather
//CurrentCondition variable type string.
var CurrentCondition string
//CurrentLocation variable type string.
var CurrentLocation string
//Forecast function that take in inpute two string and return string.
func Forecast(city, condition string) string {
	CurrentLocation, CurrentCondition = city, condition
	return CurrentLocation + " - current weather condition: " + CurrentCondition
}
