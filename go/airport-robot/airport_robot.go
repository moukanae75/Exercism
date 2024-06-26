package airportrobot

import "fmt"

type Greeter interface {
	LanguageName() string
	Greet(name string) string
}

func SayHello(name string, g Greeter) string {
	return fmt.Sprintf("%s: %s", g.LanguageName(), g.Greet(name))
}

// German Greeter implementation
type GermanGreeter struct{}

func (g GermanGreeter) LanguageName() string {
	return "I can speak German:"
}

func (g GermanGreeter) Greet(name string) string {
	return fmt.Sprintf("Hallo %s!", name)
}

// Italian Greeter implementation
type Italian struct{}

func (g Italian) LanguageName() string {
	return "I can speak Italian"
}

func (g Italian) Greet(name string) string {
	return fmt.Sprintf("Ciao %s!", name)
}

// Portuguese Greeter implementation
type Portuguese struct{}

func (g Portuguese) LanguageName() string {
	return "I can speak Portuguese"
}

func (g Portuguese) Greet(name string) string {
	return fmt.Sprintf("Olá %s!", name)
}

// Write your code here.
// This exercise does not have tests for each individual task.
// Try to solve all the tasks first before running the tests.
