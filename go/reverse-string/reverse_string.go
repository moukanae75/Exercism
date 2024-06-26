package reverse

import (
	"strings"
	"unicode/utf8"
)


func Reverse(input string) string {
	var sb strings.Builder
	for i := len(input); i > 0; {
		r, size := utf8.DecodeLastRuneInString(input[:i])
		sb.WriteRune(r)
		i -= size
	}
	return sb.String()
}

// func Reverse(input string) string {
// 	result := []rune(input)
// 	var sb strings.Builder
// 	for i := len(result)-1; i > -1; i--{
		
// 		sb.WriteRune(result[i])
		
// 	}
// 	return sb.String()
// }
