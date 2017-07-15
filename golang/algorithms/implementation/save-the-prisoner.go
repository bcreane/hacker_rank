package main

import "bufio"
import "fmt"
import "os"
import "strconv"

type test_case struct {
	n int // number of prisoners
	m int // number of sweets
	s int // id of prisoner where distribution begins (0 index)
}

type input struct {
	t []test_case
}

func savePrisonerId(t test_case) int {
	p := (t.m + t.s - 1) % t.n
	if p == 0 {
		return t.n
	} else {
		return p
	}
	return p
}

func main() {
	input := getInput()
	for x := range input.t {
		fmt.Println(savePrisonerId(input.t[x]))
	}
}

func getInput() (i input) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	numTestCases, _ := strconv.Atoi(scanner.Text())

	i.t = make([]test_case, numTestCases)

	for x := 0; x < numTestCases; x++ {
		scanner.Scan()
		i.t[x].n, _ = strconv.Atoi(scanner.Text())

		scanner.Scan()
		i.t[x].m, _ = strconv.Atoi(scanner.Text())

		scanner.Scan()
		i.t[x].s, _ = strconv.Atoi(scanner.Text())
	}

	return i
}
