package proverb

// Proverb should have a comment documenting it.
func Proverb(rhyme []string) []string {
	result := []string{}
	if len(rhyme) == 0{
		return result
	}
	for i,c := range rhyme {
	if i != len(rhyme) -1 {
		str := "For want of a "+string(c)+" the "+string(rhyme[i+1])+" was lost."
		
		result = append(result, str)
	}
	

	}
	last := "And all for the want of a "+rhyme[0]+"."
	result = append(result,last) 
	return result
}