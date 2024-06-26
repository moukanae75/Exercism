package isbn

import (
	"strconv"
	"strings"
)

func IsValidISBN(isbn string) bool {
	sum := 0
	isbn = strings.ReplaceAll(isbn, "-", "")
	if len(isbn) != 10 {
		return false
	}
	i := 10
	for j, c := range isbn {
		if c == 'X' && j == len(isbn)-1 {
			sum += 10
		} else if c >= '0' && c <= '9' {
			res, _ := strconv.Atoi(string(c))
			sum += res * i
			i--
		} else {
			return false
		}
	}

	return sum%11 == 0
}
