package elon

// Car represents a remote controlled car with speed and battery characteristics.
type Car struct {
	speed        int
	batteryDrain int
	battery      int
	distance     int
}

// NewCar creates a new remote controlled car with the specified speed and battery drain.
func NewCar(speed, batteryDrain int) Car {
	return Car{
		speed:        speed,
		batteryDrain: batteryDrain,
		battery:      100,
		distance:     0,
	}
}
