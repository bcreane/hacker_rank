package main

import "bufio"
import "fmt"
import "os"
import "strconv"

type input struct {
	m map[int]int
}

func main() {
	i := getInput()

	var pairsCnt = 0
	for _, freq := range i.m {
		pairsCnt += freq / 2
	}
	fmt.Println(pairsCnt)
}

func getInput() (i input) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	numInts, _ := strconv.Atoi(scanner.Text())

	i.m = make(map[int]int)

	for x := 0; x < numInts; x++ {
		scanner.Scan()
		color, _ := strconv.Atoi(scanner.Text())
		i.m[color]++
	}

	return i
}
