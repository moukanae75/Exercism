package raindrops

import "fmt"

func Convert(number int) string {
	n := []int{3, 5, 7}
	txt := []string{"Pling", "Plang", "Plong"}
	res := ""
	for i, c := range n {
		if number%c == 0 {
			res += txt[i]
			continue

		}

	}
	if len(res) != 0 {
		return res
	}
	return fmt.Sprintf("%d", number)

}
