package pangram

import (
	
	"strings"
)

func IsPangram(input string) bool {
		
	
	var alpha = map[rune]int {
		'a':0,'b':0,'c':0,'d':0,'e':0,'f':0,'g':0,'h':0,'i':0,'j':0,'k':0,'l':0,'m':0,'n':0,'o':0,
		'p':0,'q':0,'r':0,'s':0,'t':0,'u':0,'v':0,'w':0,'x':0,'y':0,'z':0,

	}

	input = strings.ToLower(input)
	for _,c := range input {
		
		alpha[c]++

	} 
	for c := range alpha {
		if alpha[c] == 0 {
			return false
		}
	}
	return true

	// result := make(map[rune]bool)

	// for _,c := range strings.ToLower(input) {
	// 	if c >= 'a' && c <='z' {
	// 		result[c] = true
	// 	}
	// }
	// return len(result) == 26
	
}
