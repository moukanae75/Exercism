package lasagna

// TODO: define the 'PreparationTime()' function

// TODO: define the 'Quantities()' function

// TODO: define the 'AddSecretIngredient()' function

// TODO: define the 'ScaleRecipe()' function

// Your first steps could be to read through the tasks, and create
// these functions with their correct parameter lists and return types.
// The function body only needs to contain `panic("")`.
// 
// This will make the tests compile, but they will fail.
// You can then implement the function logic one by one and see
// an increasing number of tests passing as you implement more 
// functionality.
func PreparationTime(layers []string, nbr int) int {
	if nbr ==0{
		nbr = 2
	}
	return len(layers)*nbr
}
func Quantities(layers []string) (int ,float64) {
	t := make(map[string]int)
	for _, c := range layers {
		t[c]++
	}
	var nbr int
	var sbr float64
	value, _ := t["noodles"]
	val, _ := t["sauce"]

	nbr = value * 50
	sbr = float64(val) * 0.2
	return nbr , sbr
}
func AddSecretIngredient(friendsList,myList []string){
	for i:=0;i<len(myList);i++{
		if myList[i]=="?"{
			myList[i]=friendsList[len(friendsList)-1]
		}
	}

}
func ScaleRecipe(quantity []float64, nbr int) []float64{
	t:=make([]float64,len(quantity))
	for i:=0;i<len(quantity);i++{
		t[i]=quantity[i]*float64(nbr)/2.0
		t[i]=float64(int(t[i]*100+0.5)) / 100
		
	}
	return t
}
