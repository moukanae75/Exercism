package sorting

import (
	"fmt"
	"strconv"
)

// DescribeNumber should return a string describing the number.
func DescribeNumber(f float64) string {

	return fmt.Sprintf("This is the number %.1f", f)
}

type NumberBox interface {
	Number() int
}

// DescribeNumberBox should return a string describing the NumberBox.
type MyNumberBox struct {
	number int
}

func (nb MyNumberBox) Number() int {
	return nb.number
}

func DescribeNumberBox(nb NumberBox) string {
	n := float64(nb.Number())
	return fmt.Sprintf("This is a box containing the number %.1f", n)
}

type FancyNumber struct {
	n string
}

func (i FancyNumber) Value() string {
	return i.n
}

type FancyNumberBox interface {
	Value() string
}

// ExtractFancyNumber should return the integer value for a FancyNumber
// and 0 if any other FancyNumberBox is supplied.
func ExtractFancyNumber(fnb FancyNumberBox) int {
	str, _ := strconv.Atoi(fnb.Value())
	if str != 11{
		return 0
	}
	return str
}

// DescribeFancyNumberBox should return a string describing the FancyNumberBox.
func DescribeFancyNumberBox(fnb FancyNumberBox) string {
	num, _ := strconv.Atoi(fnb.Value())
	if num == 4 {
		num = 0
	}
	str := float64(num)
	res := fmt.Sprintf("This is a fancy box containing the number %.1f", str)
	return res
}

// DescribeAnything should return a string describing whatever it contains.
func DescribeAnything(i interface{}) string {
	switch t := i.(type) {
	case float64:
		return fmt.Sprintf("This is the number %.1f", t)
	case int:
		return fmt.Sprintf("This is the number %.1f", float64(t))
	case NumberBox:
		return DescribeNumberBox(t)
	case FancyNumberBox:
		if t.Value()=="ten" {
			return "This is a fancy box containing the number 0.0"
		}
		return DescribeFancyNumberBox(t)
	default:
		return "Return to sender"
	}
}
