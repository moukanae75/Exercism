package grains

import (
	"fmt"
	//"math"
)

func Square(number int) (uint64, error) {
	count := 1
	for i := 1; i <= 64; i++ {
		if i!=1 {
			count *= 2
			
		}
		if i== number {
			return uint64(count),nil
		}
		
	}
	return 0, fmt.Errorf("")
}

func Total() uint64 {
	count := 1
	total :=0
	for i := 1; i <= 64; i++ {
		if i!=1 {
			count *= 2
			total += count
			
		}
		total += count

		
	}
	return uint64(total)+2
}
