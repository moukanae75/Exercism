package romannumerals

import "errors"

func ToRomanNumeral(input int) (string, error) {
	if input <= 0 || input >= 4000 {
		return "",errors.New("")
	}

	var out string
	tb := []int{}
	result := 0

	for {
		if input == 0 {
			break
		}
		result = input % 10
		input = input/10
		tb = append(tb, result)
		result = 0

	}
	swap := func (arr []int) []int {
		reversed := make([]int, len(arr))
		for i, j := len(arr)-1, 0; i >= 0; i-- {
			reversed[j] = arr[i]
			j++
		}
	
		return reversed
	}
	tb = swap(tb)
	for i:= range tb {
		if i == len(tb)-1 {
			out += units(tb[i])
		}
		if i == len(tb)-2 {
			out += dozens(tb[i])
		}
		if i == len(tb)-3 {
			out += hundreds(tb[i])
		}
		if i == len(tb)-4 {
			out += thousends(tb[i])
		}
	}
	return out, nil
}

func units(n int) string {
rom := map[int]string{
	0:"",
	1:"I",
	2:"II",
	3:"III",
	4:"IV",
	5:"V",
	6:"VI",
	7:"VII",
	8:"VIII",
	9:"IX",
}
	return rom[n]
}
func dozens(n int) string {
Doz := map[int]string{
	0: "",
	1: "X",
	2: "XX",
	3: "XXX",
	4: "XL",
	5: "L",
	6: "LX",
	7: "LXX",
	8: "LXXX",
	9: "XC",
}
return Doz[n]
}

func hundreds(n int) string {
Hun := map[int]string{
	0: "",
	1: "C",
	2: "CC",
	3: "CCC",
	4: "CD",
	5: "D",
	6: "DC",
	7: "DCC",
	8: "DCCC",
	9: "CM",
}
return Hun[n]

}
func thousends(n int) string {
TH := map[int]string{
	0: "",
	1: "M",
	2: "MM",
	3: "MMM",
}
return TH[n]

}
