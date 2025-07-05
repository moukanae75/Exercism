package knapsack

type Item struct {
	Weight, Value int
}

// Knapsack takes in a maximum carrying capacity and a collection of items
// and returns the maximum value that can be carried by the knapsack
// given that the knapsack can only carry a maximum weight given by maximumWeight
func Knapsack(maximumWeight int, items []Item) int {
    // Create a slice to store maximum values for each weight capacity
    tb := make([]int, maximumWeight+1)

    // Iterate over each item
    for _, item := range items {
        // Iterate backward through the tb array to avoid overwriting results from this iteration
        for i := maximumWeight; i >= item.Weight; i-- {
            // Update the tb array to consider including this item
            tb[i] = max(tb[i], tb[i-item.Weight]+item.Value)
        }
    }

    // The answer is the maximum value we can get for the full weight capacity
    return tb[maximumWeight]
}

// Utility function to return the maximum of two integers
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
