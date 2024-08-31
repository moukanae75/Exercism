package anagram

import (
	"reflect"
	"strings"
)

func Detect(subject string, candidates []string) []string {
	var result []string
	subject = strings.ToLower(subject)
	for _, candidate := range candidates {
		if strings.ToLower(candidate) == subject {
			continue
		} else if len(candidate) == len(subject) {
			
			sub := make(map[rune]int)
			cand := make(map[rune]int)

			
			for _, s := range subject {
				sub[s]++
			}
			for _, c := range strings.ToLower(candidate) {
				cand[c]++
			}
			
			if reflect.DeepEqual(sub, cand) {
				result = append(result, candidate)
			}
		}
	}
	return result
}
