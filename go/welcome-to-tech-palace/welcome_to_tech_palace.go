package techpalace

import "strings"

// WelcomeMessage returns a welcome message for the customer.
func WelcomeMessage(customer string) string {
	customer = strings.ToUpper(customer)
	return "Welcome to the Tech Palace, "+ customer
}

// AddBorder adds a border to a welcome message.
func AddBorder(welcomeMsg string, numStarsPerLine int) string {
	etoil := strings.Repeat("*",numStarsPerLine)
	return etoil + "\n" + welcomeMsg + "\n" + etoil
}

// CleanupMessage cleans up an old marketing message.
func CleanupMessage(oldMsg string) string {
	var newMsg string
	var stock string
	var final string
	var ultra string
	var tb []int
	count := 0

	for i, c := range oldMsg {
		if c == ' ' || c == '*' || c == '\n' {
			continue
		} else {
			newMsg += string(c)
			count++
			if oldMsg[i+1] == ' ' {
				stock += newMsg
				newMsg = ""
				tb = append(tb, count)
				count = 0

			}
		}
	}
	if tb == nil {
		return newMsg
	}

	index := 0
	for _, d := range tb {

		for i := index; i < len(stock); i++ {
			c := stock[i]
			final += string(c)

			if len(final) == d {

				final += " "
				ultra += final
				final = ""
				index = i + 1
				break
			}
		}
	}

	return ultra[:len(ultra)-1]
}
