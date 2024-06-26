package parsinglogfiles

import "regexp"

func IsValidLine(text string) bool {
	re := regexp.MustCompile(`^` + `\[(TRC|DBG|INF|WRN|ERR|FTL)\]`)
	if re.MatchString(text) {
		return true
	}
	return false
}

func SplitLogLine(text string) []string {
	re := regexp.MustCompile(`<[~*=\-]*>`)
	return re.Split(text, -1)
}

func CountQuotedPasswords(lines []string) int {
	count := 0
	re := regexp.MustCompile(`"[^"]*(password|passWord)[^"]*"`)
	for _,c := range lines {
		if re.MatchString(c) {
			count++

		}
	}
	return count
}

func RemoveEndOfLineText(text string) string {
	re := regexp.MustCompile(`end-of-line+\d*`)
	str := re.ReplaceAllString(text,"")
	return str
}

func TagWithUserName(lines []string) []string {
	var new []string
	re := regexp.MustCompile(`User`)
	ex := regexp.MustCompile(`[a-zA-Z]+\d+`)
	for _, c := range lines {
		if re.MatchString(c) && ex.MatchString(c) {
			userName := ex.FindString(c)
			new = append(new, "[USR] "+userName +" "+c)
		} else {
			new = append(new, c)
		}
	}
	return new
}
