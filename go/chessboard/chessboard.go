package chessboard

// Declare a type named File which stores if a square is occupied by a piece - this will be a slice of bools
type File []bool
// Declare a type named Chessboard which contains a map of eight Files, accessed with keys from "A" to "H"
type Chessboard map[string]File
// CountInFile returns how many squares are occupied in the chessboard,
// within the given file.
func CountInFile(cb Chessboard, file string) int {
	count:=0
	for _,c :=range cb[file]{
		if c {
			count++
		}
	}
	return count
}
// CountInRank returns how many squares are occupied in the chessboard,
// within the given rank.
func CountInRank(cb Chessboard, rank int) int {
	all:=[]string{"A","B","C","D","E","F","G","H"}
	count :=0
	for _,d :=range all{
	for i,c :=range cb[d]{
		if c && i+1==rank {
				count++
			}
		}
	}
	return count
}
// CountAll should count how many squares are present in the chessboard.
func CountAll(cb Chessboard) int {
	all:=[]string{"A","B","C","D","E","F","G","H"}
	count :=0
	for _,d :=range all{
	for _,c :=range cb[d]{
		if c || !c{
				count++
			}
		}
	}
	return count
}

// CountOccupied returns how many squares are occupied in the chessboard.
func CountOccupied(cb Chessboard) int {
	all:=[]string{"A","B","C","D","E","F","G","H"}
	count :=0
	for _,d :=range all{
	for _,c :=range cb[d]{
		if c {
				count++
			}
		}
	}
	return count
}
