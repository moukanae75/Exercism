package strand

import (
	//"strings"
)

var translate = map[rune]byte {
	'A':'U',
	'T':'A',
	'C':'G',
	'G':'C',
}

func ToRNA(dna string) string {

	rna := make([]byte,len(dna))
	for i,c := range dna {
		rna[i] = translate[c]
	}
	return string(rna)
	/*rna :=""
	for _,r := range dna {
		rna += string(translate[r])
	}
	return rna*/

	/*return strings.Map(func(r rune) rune {
		switch r {
		case 'A':
			return 'U'
		case 'T':
			return 'A'
		case 'C':
			return 'G'
		case 'G':
			return 'C'
		default:
			return r
		}
	},dna)*/
	// arn :=""
	// for _,c :=range dna {
	// 	if c =='A' {
	// 		c = 'U'
	// 		arn += string(c)
	// 	}else if c == 'T' {
	// 		c = 'A'
	// 		arn += string(c)
	// 	}else if c == 'C' {
	// 		c = 'G'
	// 		arn += string(c)
	// 	}else {
	// 		c = 'C'
	// 		arn += string(c)
	// 	}
	// }
	// return arn
}
