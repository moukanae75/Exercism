package rotationalcipher

func RotationalCipher(plain string, shiftKey int) string {
	result :=""

	for _,c := range plain  {
		sum := c + rune(shiftKey)
		if c >= 'a' && c <= 'z' {
			if sum > 122  {
				sum -= 26
			}
			result += string(sum)
		}else if c >= 'A' && c <= 'Z'{
			if sum > 90 {
				sum -= 26
			}
			result += string(sum)
		}else{
			result += string(c)
		}
		
		
	}
	return result
}
