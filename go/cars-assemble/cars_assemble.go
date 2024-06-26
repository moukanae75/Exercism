package cars

// CalculateWorkingCarsPerHour calculates how many working cars are
// produced by the assembly line every hour.
func CalculateWorkingCarsPerHour(productionRate int, successRate float64) float64 {
	return float64(productionRate)*(successRate/100)
}

// CalculateWorkingCarsPerMinute calculates how many working cars are
// produced by the assembly line every minute.
func CalculateWorkingCarsPerMinute(productionRate int, successRate float64) int {
	if successRate >= .5{
		successRate = float64(int(successRate+1))
	}
	return (productionRate*(int(successRate))/100)/60
}

// CalculateCost works out the cost of producing the given number of cars.
func CalculateCost(carsCount int) uint {
	if carsCount >= 1 && carsCount < 10 {
		return uint(carsCount) * 10000
	}
	if carsCount >= 10 {

		first := carsCount / 10
		sec := carsCount % 10
		final := ((uint(first) * 95000)) + (uint(sec) * 10000)
		return final
	}
	return (uint(carsCount) * 10000)
}
