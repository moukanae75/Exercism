package luhn

import (
	"regexp"
	"strconv"
	"strings"
	"unicode"
)

func Valid(id string) bool {
	var count, sum int
	re := regexp.MustCompile(`^ 0`)
	if len(id) <= 1 || re.FindString(id) == " 0" {
		return false
	}

	id = strings.ReplaceAll(id, " ", "")
	id = reverseString(id)

	for i := 0; i <= len(id)-1; i++ {
		if !unicode.IsNumber(rune(id[i])) {
			return false
		}
		sum, _ = strconv.Atoi(string(id[i]))
		if sum*2 > 9 && i%2 != 0 {
			sum = sum*2 - 9
			count += sum
		} else if i%2 != 0 {
			count += sum * 2
		} else {
			count += sum
		}

	}
	return count%10 == 0
}

func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}
