package lsproduct

import (
	"errors"
	"sort"
	"strconv"
)

func LargestSeriesProduct(digits string, span int) (int64, error) {
	var res []int
	if span < 0 {
		return 0, errors.New("span must not be negative")
	} else if len(digits) < span {
		return 0, errors.New("span must be smaller than string length")
	}
	for i := 0; i < len(digits); i++ {
		if digits[i] >= '0' && digits[i] <= '9' {
			nbr, _ := strconv.Atoi(string(digits[i]))
			res = append(res, nbr)
		} else {
			return 0, errors.New("digits input must only contain digits")
		}
	}
	var result []int
	sum := 1
	for i := 0; i < len(res); i++ {
		for j := i; j < i+span; j++ {
			if i+span <= len(res) {
				sum *= res[j]
			} else {
				break
			}

		}
		if len(res)-i >= span {
			result = append(result, sum)
			sum = 1
		} else {
			break
		}
	}
	sort.Ints(result)
	return int64(result[len(result)-1]), nil
}
