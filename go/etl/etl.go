package etl

import "strings"

func Transform(in map[int][]string) map[string]int {
	result := make(map[string]int)
	for i,arr := range in {
		for _,c := range arr {
			c = strings.ToLower(c)
			_,ok := result[c]
			if !ok {
				result[c] = i
			}
		}
	}
	return result
}
