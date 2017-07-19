package main

import "fmt"

func reduce(s string) (r string) {
	for i := 0; i < len(s); i++ {
		if i < len(s)-1 && s[i] == s[i+1] {
			i++
		} else {
			r += string(s[i])
		}
	}
	return r
}

func isUpper(c byte) bool {
	return c >= 'A' && c <= 'Z'
}

func countCamelCaseWords(s string) int {
	if len(s) == 0 {
		return 0
	}

	wordCnt := 1
	for i := 0; i < len(s); i++ {
		if isUpper(s[i]) {
			wordCnt++
		}
	}
	return wordCnt
}

func main() {
	var s string
	fmt.Scanf("%s", &s)

	fmt.Println(countCamelCaseWords(s))
}
