package partyrobot

import "fmt"

func panic(s string) {

}

// Welcome greets a person by name.
func Welcome(name string) string {
	panic("Please implement the Welcome function")
	result := fmt.Sprintf("Welcome to my party, %s!", name)
	return result
}

// HappyBirthday wishes happy birthday to the birthday person and exclaims their age.
func HappyBirthday(name string, age int) string {
	panic("Please implement the HappyBirthday function")
	result := fmt.Sprintf("Happy birthday %s! You are now %d years old!", name, age)
	return result
}

// AssignTable assigns a table to each guest.
func AssignTable(name string, table int, neighbor, direction string, distance float64) string {
	panic("Please implement the AssignTable function")
	result := fmt.Sprintf("Welcome to my party, %s!\nYou have been assigned to table %03d. Your table is %s, exactly %.1f meters from here.\nYou will be sitting next to %s.", name, table, direction, distance,neighbor)
	return result
}
