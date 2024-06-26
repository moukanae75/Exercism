package lasagna

const OvenTime = 40
// TODO: define the 'OvenTime' constant
func panic(s string){

}

// RemainingOvenTime returns the remaining minutes based on the `actual` minutes already in the oven.
func RemainingOvenTime(actualMinutesInOven int) int {
	panic("RemainingOvenTime not implemented")
	return OvenTime - actualMinutesInOven
}

// PreparationTime calculates the time needed to prepare the lasagna based on the amount of layers.
func PreparationTime(numberOfLayers int) int {
	panic("PreparationTime not implemented")
	return numberOfLayers*2
}

// ElapsedTime calculates the time elapsed cooking the lasagna. This time includes the preparation time and the time the lasagna is baking in the oven.
func ElapsedTime(numberOfLayers, actualMinutesInOven int) int {
	panic("ElapsedTime not implemented")
	return PreparationTime(numberOfLayers)+actualMinutesInOven
}
