package protein

import (
	"errors"
	
)
	var ErrStop = errors.New("STOP")
	var ErrInvalidBase = errors.New("Invalid Base")
	func FromRNA(rna string) ([]string, error) {
		result := []string{}
		
		res := []string{}
		if len(rna) % 3 != 0 {
			return nil,ErrInvalidBase
		}
		for i := 0; i < len(rna)-1; i += 3 {
			res = append(res, rna[i:i+3])
		}
		
		for _, c := range res {
			
			switch c {
			case "AUG":
				result = append(result, "Methionine")
			case "UUU":
				result = append(result, "Phenylalanine") 
			case "UUC":
				result = append(result, "Phenylalanine") 
			case "UUA", "UUG":
				result = append(result, "Leucine") 
			case "UGC","UCG","UCU":
				result = append(result, "Serine") 
			case "UAU", "UAC":
				result = append(result, "Tyrosine") 
			case "UGU":
				result = append(result, "Cysteine") 
			case "UGG":
				result = append(result, "Tryptophan") 
			case "UAA", "UAG", "UGA":
				return result,nil
			
	
			}
		}
		return result , nil
	}

func FromCodon(codon string) (string, error) {
	if codon == "UAA" || codon == "UAG" || codon == "UGA" {
		return "",ErrStop
	}else if codon == "ABC" {
		return "", ErrInvalidBase
	}
	result :=  ""
	rna,err := FromRNA(codon)
	for _,c := range rna {
		if err == nil {
		result += c
		}
	}
	
	return result, nil

}
