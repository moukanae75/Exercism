package wordy

import (
	"fmt"
	"regexp"
	"strings"
)

func Answer(question string) (int, bool) {
	var numbers []int
	var operations []rune
	nb := regexp.MustCompile(`[0-9\-]+`)
	words := strings.Split(question, " ")
	empty := true
	for _, word := range words {
		if nb.MatchString(word) {
			num, err := Atoi(word)
			if err != nil {
				return 0, false
			}
			numbers = append(numbers, num)
			if len(numbers) > 0 {
				empty = false
			}
		} else if word == "plus" && !empty {
			operations = append(operations, '+')
		} else if word == "minus" && !empty {
			operations = append(operations, '-')
		} else if word == "multiplied" && !empty {
			operations = append(operations, '*')
		} else if word == "divided" && !empty {
			operations = append(operations, '/')
		}
	}
	if _, err := Atoi(words[len(words)-1]); err != nil {
		return 0, false
	}
	if (len(numbers) < 2 && len(operations) != 0) || len(numbers)-len(operations) != 1 {
		return 0, false
	}
	result := numbers[0]

	for i, op := range operations {
		switch op {
		case '+':
			result += numbers[i+1]
		case '-':
			result -= numbers[i+1]
		case '*':
			result *= numbers[i+1]
		case '/':
			if numbers[i+1] == 0 {
				return 0, false
			}
			result /= numbers[i+1]
		}
	}

	return result, true
}
func Atoi(s string) (int, error) {
	negative := false
	var nbr int
	for _, i := range s {
		if i == '-' {
			negative = true
			continue
		}
		if i >= '0' && i <= '9' {
			nbr = nbr*10 + int(i-48)

		} else if i <= '0' || i >= '9' {
			continue
		}
	}
	if negative {
		nbr *= -1
	} else if nbr == 0 {
		return 0, fmt.Errorf("There is no number")
	}

	return nbr, nil
}
