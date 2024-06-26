package booking

import (
	"fmt"
	"time"
)

// Schedule returns a time.Time from a string containing a date.
func Schedule(date string) time.Time {
	layout := "1/2/2006 15:04:05"
	t, _ := time.Parse(layout, date)

	return t
}

// HasPassed returns whether a date has passed.
func HasPassed(date string) bool {
	layout := "January 2, 2006 15:04:05"
	t, _ := time.Parse(layout, date)
	return t.Before(time.Now())
}

// IsAfternoonAppointment returns whether a time is in the afternoon.
func IsAfternoonAppointment(date string) bool {
	layout := "Monday, January 2, 2006 15:04:05"
	t, _ := time.Parse(layout, date)

	if t.Hour() >= 12 && t.Hour() < 18 {
		return true
	}

	return false
}

// Description returns a formatted string of the appointment time.
func Description(date string) string {
	layout := "1/2/2006 15:04:05"
	t, _ := time.Parse(layout, date)
	show := fmt.Sprintf("You have an appointment on %s, %s %d, %d, at %d:%d.", t.Weekday(), t.Month() , t.Day() , t.Year(), t.Hour() ,t.Minute())
	return show

}

// AnniversaryDate returns a Time with this year's anniversary.
func AnniversaryDate() time.Time {
	date :="9/15/2024 00:00:00"
	layout := "1/2/2006 15:04:05"
	t, _ := time.Parse(layout, date)

	return t
}
