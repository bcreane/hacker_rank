package main

import "bufio"
import "fmt"
import "os"

type input struct {
	s string
}

// Return the maximum length string from 2 unique/alternating character
// permutations from stdin For example, given ABAC
//   ABA  length == 3
//   AC   length == 2
// So max length is 3
//
func main() {
	input := getInput()
	set := deduplicatedChars(input.s)
	maxMatchLength := 0
	for x := 0; x < len(set)-1; x++ {
		for y := x + 1; y < len(set); y++ {
			s := matchTwoChars(input.s, set[x], set[y])
			l := len(s)
			if doesAlternate(s) && maxMatchLength < l {
				maxMatchLength = l
			}
		}
	}
	fmt.Println(maxMatchLength)
}

// Returns true if each character alternates based on an AB pattern
// for example: ABA, or ABAB is true, but ACD is false
//
func doesAlternate(s string) bool {
	switch len(s) {
	case 0:
	case 1:
		return false
	case 2:
		return s[0] != s[1]
	default:
		if s[0] == s[1] {
			return false
		}
	}

	for i := 2; i < len(s); i++ {
		if s[i%2] != s[i] {
			return false
		}
	}
	return true
}

// Return a set of characters for easy iteration
func deduplicatedChars(s string) (r string) {
	m := make(map[byte]bool)
	for i := range s {
		if _, ok := m[s[i]]; !ok {
			m[s[i]] = true
			r += string(s[i])
		}
	}

	return r
}

// Return a string which only has characters a/b from s
func matchTwoChars(s string, a byte, b byte) (r string) {
	for i := range s {
		if s[i] == a || s[i] == b {
			r += string(s[i])
		}
	}
	return r
}

func getInput() (i input) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan() // discard string length
	scanner.Scan()
	i.s = scanner.Text()
	return i
}
