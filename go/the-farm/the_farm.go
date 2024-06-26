package thefarm

import (
	"errors"
	"fmt"
)


type fodderCalculator struct {
	amount float64
	factor float64
}



func DivideFood(f FodderCalculator, nbr int) (float64, error) {
	if nbr <= 0 {
		return 0, errors.New("invalid number of cows")
	}

	amount, err := f.FodderAmount(nbr)
	if err != nil {
		return 0, err
	}

	factor, err := f.FatteningFactor()
	if err != nil {
		return 0, err
	}

	return (amount * factor) / float64(nbr), nil
}

func (f fodderCalculator) FodderAmount(nbr int) (float64, error) {
	// Implement your logic to calculate the total amount of fodder for the given number of cows.
	// Return the calculated amount or an error if something goes wrong.
	return f.amount, nil
}

func (f fodderCalculator) FatteningFactor() (float64, error) {
	// Implement your logic to retrieve the fattening factor.
	// Return the factor or an error if something goes wrong.
	return f.factor, nil
}

func ValidateInputAndDivideFood(fc FodderCalculator, nbr int) (float64, error) {
	if nbr <= 0 {
		return 0, errors.New("invalid number of cows")
	}
	return DivideFood(fc, nbr)
}


func (e *InvalidCowsError) Error() string {
	return fmt.Sprintf("%d cows are invalid: %s", e.NumberOfCows, e.Message)
}

func ValidateNumberOfCows(nbr int) error {
	if nbr < 0 {
		return &InvalidCowsError{NumberOfCows: nbr, Message: "there are no negative cows"}
	} else if nbr == 0 {
		return &InvalidCowsError{NumberOfCows: nbr, Message: "no cows don't need food"}
	}
	return nil
}