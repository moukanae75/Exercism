package birdwatcher

// TotalBirdCount return the total bird count by summing
// the individual day's counts.
func TotalBirdCount(birdsPerDay []int) int {
	var res int
	for _,c :=range birdsPerDay{
		res += c
	}
	return res
}

// BirdsInWeek returns the total bird count by summing
// only the items belonging to the given week.
func BirdsInWeek(birdsPerDay []int, week int) int {
	nbr := 7 * week
	var res int
	if nbr > len(birdsPerDay) || week < 0 {
		return -1
	}
	if week > 1 {
		count := 1
		for i := 7; i <= len(birdsPerDay); i += 7 {
			if week == count {
				for _, c := range birdsPerDay[i-7 : nbr] {
					res += c
				}
				return res
			}
			count++
		}
	} else {
		birdsPerDay = birdsPerDay[:nbr]
		for _, c := range birdsPerDay {
			res += c
		}

	}
	return res
}

// FixBirdCountLog returns the bird counts after correcting
// the bird counts for alternate days.
func FixBirdCountLog(birdsPerDay []int) []int {
	for i:=0;i<len(birdsPerDay);i+=2 {
		birdsPerDay [i] = birdsPerDay [i] + 1
	}
	return birdsPerDay
}
