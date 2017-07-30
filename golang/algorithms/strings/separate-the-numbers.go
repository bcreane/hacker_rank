package main

import "fmt"
import "strconv"

type input struct {
	s []string
}

func beautifulWordSearch(s string) {
	var firstMatchWord string // Report the first word in a "beautiful" word sequence

	// Outer loop tries different word lengths
	for length := 1; length <= (len(s))/2; length++ {
		var firstWord string
		innerLength := length

		// Inner loop searches the entire string, checking that a(i-1) == a(i) - 1
		// e.g. 91011 matches 9 -> 10 -> 11
		for w := 0; w+innerLength <= len(s); {
			word := s[w : w+innerLength]
			if w == 0 {
				firstWord = word
			}

			n, _ := strconv.Atoi(word)
			n1 := strconv.Itoa(n + 1)

			// Try to match both the same length as well as length+1,
			// e.g. 8->9, or 99->100
			var match, match1 string
			if w+innerLength+innerLength <= len(s) {
				match = s[w+innerLength : w+innerLength+innerLength]
			}
			if w+innerLength+innerLength+1 <= len(s) {
				match1 = s[w+innerLength : w+innerLength+innerLength+1]
			}

			if n1 == match {
				w += innerLength
			} else if n1 == match1 {
				innerLength++
				w += innerLength - 1 // back it up 1 since previous word length is innerLength-1
			} else {
				if w+innerLength != len(s) {
					firstWord = "" // we did not find a match
				}
				break
			}

		}

		if len(firstWord) > 0 {
			if len(firstMatchWord) == 0 {
				firstMatchWord = firstWord
			}
			break // we found a match, no need to keep looking
		}
	}

	if len(firstMatchWord) > 0 {
		fmt.Printf("YES %s\n", firstMatchWord)
	} else {
		fmt.Println("NO")
	}
}

func main() {
	input := getInput()
	for x := range input.s {
		beautifulWordSearch(input.s[x])
	}
}

func getInput() (i input) {
	numQueries := 0
	fmt.Scanf("%d\n", &numQueries)

	i.s = make([]string, numQueries)
	for n := 0; n < numQueries; n++ {
		fmt.Scanf("%s\n", &i.s[n])
	}

	return i
}
