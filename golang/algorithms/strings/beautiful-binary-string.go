package main

import "fmt"

type input struct {
	s []byte
}

func minFlipsToMakeBeautiful(s []byte) {
	numFlips := 0
	for x := 0; x < len(s)-2; x++ {
		if s[x] == '0' && s[x+1] == '1' && s[x+2] == '0' {
			s[x+2] = '1'
			numFlips++
		}
	}
	fmt.Println(numFlips)
}

func main() {
	input := getInput()
	minFlipsToMakeBeautiful(input.s)
}

func getInput() (i input) {
	var stupidStrLen int
	fmt.Scanf("%d\n", &stupidStrLen)
	var s string
	fmt.Scanf("%s", &s)
	i.s = []byte(s)

	return i
}
