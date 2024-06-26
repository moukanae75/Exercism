package rotationalcipher

func RotationalCipher(plain string, shiftKey int) string {
	result :=""
	var trans byte
	for _,c := range plain  {
		if c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' {
			trans = byte(c + rune(shiftKey))
			if c + rune(shiftKey) > 26 {
				trans -= 26
			}
			result += string(trans)
		}else {
			result += string(c)
		}
		
		
	}
	return result
}
