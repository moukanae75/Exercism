package logs

import "unicode/utf8"

// Application identifies the application emitting the given log.
func Application(log string) string {
	applications := map[rune]string{
		'❗': "recommendation",
		'🔍': "search",
		'☀': "weather",
	}
	for _, char := range log {
		app, ok := applications[char]
		if  ok {
			return app
		}
	}
	return "default"
}

// Replace replaces all occurrences of old with new, returning the modified log
// to the caller.
func Replace(log string, oldRune, newRune rune) string {
	newLog:=""
	for _,c :=range log {
		if oldRune==c{
			c = newRune	
		}
		newLog += string(c)
	}
	return newLog
}

// WithinLimit determines whether or not the number of characters in log is
// within the limit.
func WithinLimit(log string, limit int) bool {
	limi := utf8.RuneCountInString(log)
	return limit>=limi
}
