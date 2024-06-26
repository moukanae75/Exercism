package blackjack

//ParseCard returns the integer value of a card following blackjack ruleset.
func ParseCard(card string) int {
	
	switch card{
	case "ace":
		return 11
	case "two":
		return 2
	case "three":
		return 3
	case "four":
		return 4
	case "five":
		return 5
	case "six":
		return 6
	case "seven":
		return 7
	case "eight":
		return 8
	case "nine":
		return 9
	case "ten" , "jack","queen","king":
		return 10
	default:
		return 0
	}
}

// FirstTurn returns the decision for the first turn, given two cards of the
// player and one card of the dealer.
func FirstTurn(card1, card2, dealerCard string) string {
	if card1 =="ace"&&card2=="ace"{
		return "P"
	}
	switch dealerCard{
	case "ace":
		if ParseCard(card1)>=10&&ParseCard(card2)>=10{
			return "S"
		}else if (ParseCard(card1)>=10&&ParseCard(card2)!=6)||ParseCard(card2)>=10{
			return "S"
		}else{
			return "H"
		}
	case "jack":
		return "H"
	case "king":
		return "H"
	case "ten":
		return "H"
	case "queen":
		if ParseCard(card1)>=10&&ParseCard(card2)>=10{
			return "S"
		}else{
			return "H"
		}
	default:
		if dealerCard =="six"{
			return "S"
		}else if card1 =="ten"||card2=="two"{
			return "H"
		}
		return "W"
	}
	return "S"
}
