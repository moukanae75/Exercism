package resistorcolorduo

var color = map[string]int{
	"black":0,
	"brown":1,
	"red":2,
	"orange":3,
	"yellow":4,
	"green":5,
	"blue":6,
	"violet":7,
	"grey":8,
	"white":9,
}

// Value should return the resistance value of a resistor with a given colors.
func Value(colors []string) int {
	
	var sum int

	for i,c := range colors {
			if i == 0 {
				sum += color[c]*10
			}else if i == 1{
				sum += color[c]
			}

		}
		return sum
	}
	

