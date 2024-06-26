package space

import "math"

type Planet string

func Age(seconds float64, planet Planet) float64 {
	var orbitalPeriod float64
	switch planet {
	case "Mercury":
		orbitalPeriod = 0.2408467 * 365.25 
	case "Venus":
		orbitalPeriod = 0.61519726 * 365.25 
	case "Earth":
		orbitalPeriod = 365.25 
	case "Mars":
		orbitalPeriod = 1.8808158 * 365.25 
	case "Jupiter":
		orbitalPeriod = 11.862615 * 365.25 
	case "Saturn":
		orbitalPeriod = 29.447498 * 365.25 
	case "Uranus":
		orbitalPeriod = 84.016846 * 365.25 
	case "Neptune":
		orbitalPeriod = 164.79132 * 365.25 
	default:
		return -1.00

	}
	earthYears := seconds / (orbitalPeriod * 24 * 60 * 60)
	return math.Round(earthYears*100) / 100
}
