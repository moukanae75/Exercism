package bob

import (
	"regexp"
	"strings"
	"unicode"
)

// Hey should have a comment documenting it.
func Hey(remark string) string {

	ex := regexp.MustCompile(`[?]$`)
	up := regexp.MustCompile(`[A-Z']`)
	low := regexp.MustCompile(`[a-z]`)
	remark = strings.ReplaceAll(remark, "?   ", "?")
	if ex.MatchString(remark) {
		onlydigit := func(s string) bool {
			for i, c := range s {
				if !unicode.IsDigit(c) {
					if i == len(s)-1 {
						break
					}
					return false
				}
			}
			return true
		}

		if low.MatchString(remark) || onlydigit(remark) || !up.MatchString(remark) {
			return "Sure."
		}

		return "Calm down, I know what I'm doing!"
	} else if up.MatchString(remark) && !ex.MatchString(remark) {
		for _, c := range remark {
			if c >= 'a' && c <= 'z' {
				return "Whatever."
			}
		}
		return "Whoa, chill out!"
	} else {
		first := func(s string) bool {
			for _, c := range s {
				if c > 0x20 {
					return false
				}
			}
			return true
		}
		if first(remark) {
			return "Fine. Be that way!"
		}
	}

	return "Whatever."
}
