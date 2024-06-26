package meteorology

import "fmt"

type TemperatureUnit int

const (
	Celsius    TemperatureUnit = 0
	Fahrenheit TemperatureUnit = 1
)

// Add a String method to the TemperatureUnit type

func (tu TemperatureUnit) String() string {
	if tu == Celsius {
		return "°C"
	}
	return "°F"
}

type Temperature struct {
	degree int
	unit   TemperatureUnit
}

// Add a String method to the Temperature type

func (te Temperature) String() string {
	return fmt.Sprintf("%d %s",te.degree,te.unit)
}

type SpeedUnit int

const (
	KmPerHour    SpeedUnit = 0
	MilesPerHour SpeedUnit = 1
)

// Add a String method to SpeedUnit

func (sp SpeedUnit) String() string {
	if sp == KmPerHour {
		return "km/h"
	}
	return "mph"
}

type Speed struct {
	magnitude int
	unit      SpeedUnit
}

// Add a String method to Speed

func (spe Speed) String() string {
	return fmt.Sprintf("%d %s",spe.magnitude,spe.unit)
}

type MeteorologyData struct {
	location      string
	temperature   Temperature
	windDirection string
	windSpeed     Speed
	humidity      int
}

// Add a String method to MeteorologyData

func (met MeteorologyData) String() string {
	return fmt.Sprintf("%s: %d %s, Wind %s at %d %s, %d%% Humidity",met.location,met.temperature.degree,met.temperature.unit,met.windDirection,met.windSpeed.magnitude,met.windSpeed.unit,met.humidity)
}