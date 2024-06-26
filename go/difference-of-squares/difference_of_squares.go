package diffsquares

func SquareOfSum(n int) int {
	var Sum int
	for i:= n ; i>=0 ; i-- {
		Sum += i
	}
	return Sum * Sum
	
}
func SumOfSquares(n int) int {
	var Sum int
	for i:= n ; i>=0 ; i-- {
		Sum += i*i
	}
	return Sum
}
func Difference(n int) int {
	return SquareOfSum(n)-SumOfSquares(n)
}
