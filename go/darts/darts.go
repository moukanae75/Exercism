package darts

import "math"

func Score(x, y float64) int {
	x= math.Abs(x)
	y = math.Abs(y)
	res := x+y
	
	if res >= 0 && res < 1.5 {
		return 10
	}else if res >= 1.5 && res <= 7 {
		return 5
	}else if res >= 7.2 && res <= 14{
		return 1
	}
	return 0
}
