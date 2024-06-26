package collatzconjecture

import "fmt"

func CollatzConjecture(n int) (int, error) {
	count := 0
	if n <= 0 {
		return 0 , fmt.Errorf("This is not an positive number")
	}
	for {
		if n == 1 {
			break
		}
		if n%2 == 0 {
			n = n/2
		}else {
			n = 3*n + 1
		}
		count++
	}
	
	return count,nil
}