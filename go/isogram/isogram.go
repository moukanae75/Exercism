package isogram

import "strings"

func IsIsogram(word string) bool {
	word = strings.ToLower(word)
	for i:=0 ; i<=len(word) ;i++ {
		for j:=i+1 ; j<len(word);j++{
			if word[i] == word[j] && word[i] != '-' && word[i] != ' ' {
				return false
			}

		}
		
	}
	return true
	
}
