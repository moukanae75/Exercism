package gross

// Units stores the Gross Store unit measurements.
func Units() map[string]int {
	t := make(map[string]int)
	t["quarter_of_a_dozen"] = 3
	t["half_of_a_dozen"] = 6
	t["dozen"] = 12
	t["small_gross"] = 120
	t["gross"] = 144
	t["great_gross"] = 1728
	return t
}

// NewBill creates a new bill.
func NewBill() map[string]int {
	t :=make(map[string]int)
	return t
}

// AddItem adds an item to customer bill.
func AddItem(bill, units map[string]int, item, unit string) bool {
	units = Units()
	_, exists := units[unit]
	if !exists {
		return false
	} else {
		bill[item] += units[unit]
		return true
	}

}

// RemoveItem removes an item from customer bill.
func RemoveItem(bill, units map[string]int, item, unit string) bool {
	_, itemExists := bill[item]
	_, unitExists := units[unit]
	if !itemExists || !unitExists {
		return false
	}
	newQuantity := bill[item] - units[unit]
	if newQuantity < 0 {
		return false
	}

	if newQuantity == 0 {
		delete(bill, item)
	} else {
		bill[item] = newQuantity
	}

	return true
}

// GetItem returns the quantity of an item that the customer has in his/her bill.
func GetItem(bill map[string]int, item string) (int, bool) {
	quantity,exist :=bill[item]
	return quantity, exist
}
