package elon

import "strconv"

// Drive drives the car for one meter.
func (car *Car) Drive() {
	if car.battery >= car.batteryDrain {
		car.distance += car.speed
		car.battery -= car.batteryDrain
	}
}

// DisplayDistance returns the distance driven by the car as a string.
func (car Car) DisplayDistance() string {
	return "Driven " + strconv.Itoa(car.distance) + " meters"
}

// DisplayBattery returns the current battery percentage of the car as a string.
func (car Car) DisplayBattery() string {
	return "Battery at " + strconv.Itoa(car.battery) + "%"
}

// CanFinish checks if the car can finish the race given the track distance.
// It returns true if the car has enough battery to cover the remaining distance,
// and false otherwise.
func (car Car) CanFinish(trackDistance int) bool {
    if car.distance >= trackDistance   {
        return true
    }
    return false
}