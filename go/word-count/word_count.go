package wordcount

import (
	"regexp"
	"strings"
)

type Frequency map[string]int

func WordCount(phrase string) Frequency {
	result := make(Frequency)
	re := regexp.MustCompile(`\b'?([a-zA-Z0-9']+)'?\b`)
	New := strings.FieldsFunc(phrase, func(r rune) bool {
        return r == ' ' || r == ',' || r == '\n'
    })
	for _,mots := range New {
		if re.MatchString(mots) {
			word := re.FindString(mots)
			result[strings.ToLower(word)]++
		}
	}
	return result
	
}
