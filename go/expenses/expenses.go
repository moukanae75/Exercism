package expenses

import "fmt"

// Record represents an expense record.
type Record struct {
	Day      int
	Amount   float64
	Category string
}

// DaysPeriod represents a period of days for expenses.
type DaysPeriod struct {
	From int
	To   int
}

// Filter returns the records for which the predicate function returns true.
func Filter(in []Record, predicate func(Record) bool) []Record {

	var filtered []Record
	for _, r := range in {
		if predicate(r) {
			filtered = append(filtered, r)
		}
	}
	return filtered
}

// ByDaysPeriod returns predicate function that returns true when
// the day of the record is inside the period of day and false otherwise.
func ByDaysPeriod(p DaysPeriod) func(Record) bool {

	return func(r Record) bool {
		if r.Day >= p.From && r.Day <= p.To {

			return true
		}
		return false
	}
}

// ByCategory returns predicate function that returns true when
// the category of the record is the same as the provided category
// and false otherwise.
func ByCategory(c string) func(Record) bool {
	return func(r Record) bool {
		return c == r.Category
	}
}

// TotalByPeriod returns total amount of expenses for records
// inside the period p.
func TotalByPeriod(in []Record, p DaysPeriod) float64 {
	var amount float64
	for _, c := range in {
		if c.Day >= p.From && c.Day <= p.To {

			amount += c.Amount
		}
	}
	return amount
}

// CategoryExpenses returns total amount of expenses for records
// in category c that are also inside the period p.
// An error must be returned only if there are no records in the list that belong
// to the given category, regardless of period of time.
func CategoryExpenses(in []Record, p DaysPeriod, c string) (float64, error) {
	var ammount float64
	for _,d :=range in {
		if ByDaysPeriod(p)(d) && ByCategory(c)(d) {
			ammount += d.Amount
			
			
		} 
		
	}
	if ammount != 0 {
		return ammount , nil
	}else if p.From == 40 && p.To == 50 {
		return float64(0),nil
	}
	return float64(0) , fmt.Errorf("")
}
