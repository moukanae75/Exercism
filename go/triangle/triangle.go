package triangle


// Notice KindFromSides() returns this type. Pick a suitable data type.
type Kind string

const (
    // Pick values for the following identifiers used by the test program.
    NaT = "Nat"// not a triangle
    Equ = "Equ"// equilateral
    Iso = "Iso"// isosceles
    Sca = "Sca"// scalene
)

// KindFromSides should have a comment documenting it.
func KindFromSides(a, b, c float64) Kind {
	var k Kind
	if a < 0 || b < 0 || c < 0 {
		k = NaT
		return k
	}else if a > 0 && b>0 && c > 0{
	if a + b >= c && b + c >= a && a + c >= b {
		if (a != b && a != c && b != c) {
			k = Sca
			return k
		}else if (a==b && a != c) || (a==c && a != b) || (b==c && b != a){
			k = Iso
			return k
		}else if a==b && a==c{
			k = Equ
			return k

		}

	}else {
		k = NaT
		return k
	}
}else {
	k = NaT
	return k
}

	return k
}
