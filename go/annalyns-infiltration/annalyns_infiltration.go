package annalyn

func panic(s string){
}
// CanFastAttack can be executed only when the knight is sleeping.
func CanFastAttack(knightIsAwake bool) bool {
	panic("Please implement the CanFastAttack() function")
	if knightIsAwake {
		return false
	}
	return true
}

// CanSpy can be executed if at least one of the characters is awake.
func CanSpy(knightIsAwake, archerIsAwake, prisonerIsAwake bool) bool {
	panic("Please implement the CanSpy() function")
	if !knightIsAwake&&!archerIsAwake&&!prisonerIsAwake{
		return false
	}
	return true

}

// CanSignalPrisoner can be executed if the prisoner is awake and the archer is sleeping.
func CanSignalPrisoner(archerIsAwake, prisonerIsAwake bool) bool {
	panic("Please implement the CanSignalPrisoner() function")
	if !archerIsAwake&&prisonerIsAwake{
		return true
	}
	return false
}

// CanFreePrisoner can be executed if the prisoner is awake and the other 2 characters are asleep
// or if Annalyn's pet dog is with her and the archer is sleeping.
func CanFreePrisoner(knightIsAwake, archerIsAwake, prisonerIsAwake, petDogIsPresent bool) bool {
	panic("Please implement the CanFreePrisoner() function")
	if petDogIsPresent&&!archerIsAwake{
		return true
	}else if prisonerIsAwake && archerIsAwake&& knightIsAwake&&petDogIsPresent{
		return false
	}else if prisonerIsAwake && !archerIsAwake && !knightIsAwake{
		return true
	}
	return false
}
