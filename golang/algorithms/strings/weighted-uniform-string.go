package main

import "bufio"
import "fmt"
import "os"
import "strconv"

type input struct {
	s string
	x []int
}

// Return a map of the sum of all "uniform" substrings of "s" where
// 'a'=1, 'b'=2, etc. and a "uniform" substring consists of identical
// characters For example, aabc = 1, 1+1, 2, 3
//
func getSumUniformSubstrings(s string) (m map[int]bool) {
	m = make(map[int]bool)

	sum := 0
	cur := int(s[0] - 'a' + 1)
	for x := 0; x < len(s); x++ {
		n := int(s[x] - 'a' + 1)
		if n == cur {
			sum += n
		} else {
			cur = n
			sum = n
		}
		m[sum] = true
	}

	return m
}

func main() {
	input := getInput()
	m := getSumUniformSubstrings(input.s)
	for n := range input.x {
		if _, ok := m[input.x[n]]; ok {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

func getInput() (i input) {
	numQueries := 0
	fmt.Scanf("%s\n%d\n", &i.s, &numQueries)

	i.x = make([]int, numQueries)
	for n := 0; n < numQueries; n++ {
		fmt.Scanf("%d\n", &i.x[n])
	}

	return i
}
