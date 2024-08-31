package atbash

import "strings"

func Atbash(s string) string {
	s = strings.ReplaceAll(s, " ", "")
	s = strings.ReplaceAll(s, ",", "")
	s = strings.ReplaceAll(s, ".", "")
	ciph := []string{}
	for i := 'z'; i >= 'a'; i-- {
		ciph = append(ciph, string(i))
	}
	new := ""
	s = strings.ToLower(s)
	for i, c := range s {
		if i%5 == 0 && i != 0 {
			new += " "
		} else if c >= '0' && c <= '9' {
			new += string(c)
			continue
		}
		new += ciph[int(c-97)]
	}

	return new

}
