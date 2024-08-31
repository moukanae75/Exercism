package prime

import "errors"

// Nth returns the nth prime number. An error must be returned if the nth prime number can't be calculated ('n' is equal or less than zero)
func Nth(n int) (int, error) {
	if n == 0 {
		return 0, errors.New("there is no zeroth prime")
	}
	prime :=make([]bool,105000)
	for i := range prime {
		prime[i]=true
	}
	count := 0
	for i:=2;i<len(prime);i++ {
		if prime[i] {
			count++
			if count == n {
				return i, nil
			}
		for j:=i*i;j<len(prime);j+=i {
				prime[j] = false
			}
		}
	}
	return 0,errors.New("")
}
