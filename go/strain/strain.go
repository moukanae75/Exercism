package strain

// Implement the "Keep" and "Discard" function in this file.

type Predicate[T any] func(T)bool

func Keep[T any](slice []T,p Predicate[T]) []T{
	var result []T
	for _,c := range slice {
		if p(c) {
			result = append(result, c)
		}
	}
	return result
}

func Discard[T any](slice []T,p Predicate[T]) []T{
	var result []T
	for _,c := range slice {
		if !p(c) {
			result = append(result, c)
		}
	}
	return result
}
// You will need typed parameters (aka "Generics") to solve this exercise.
// They are not part of the Exercism syllabus yet but you can learn about
// them here: https://go.dev/tour/generics/1
