package dndcharacter

import (
	"math"
	"math/rand"
	"sort"
	//"time"
)

type Character struct {
	Strength     int
	Dexterity    int
	Constitution int
	Intelligence int
	Wisdom       int
	Charisma     int
	Hitpoints    int
}

// Modifier calculates the ability modifier for a given ability score
func Modifier(score int) int {
	return int(math.Floor(float64(score-10) / 2))
}

// Ability uses randomness to generate the score for an ability
func Ability() int {
	dice := []int{1, 2, 3, 4, 5, 6}

	rand.Shuffle(len(dice), func(i, j int) { dice[i], dice[j] = dice[j], dice[i] })
	var sum int
	result := make([]int, 4)
	for i := range result {
		result[i] = dice[i]
	}
	sort.Ints(result)
	result[0] = 0

	for i := range result {

		sum += result[i]

	}
	return sum
}

// GenerateCharacter creates a new Character with random scores for abilities
func GenerateCharacter() Character {

	char := &Character{Strength: Modifier(10) + 10, Dexterity: Modifier(10) + 10, Constitution: Modifier(10) + 10,
		Intelligence: Modifier(10) + 10, Wisdom: Modifier(10) + 10, Charisma: Modifier(10) + 10, Hitpoints: Modifier(10) + 10}

	return *char
}
