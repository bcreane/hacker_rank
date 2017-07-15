package main

import "bufio"
import "fmt"
import "os"
import "strconv"

type input struct {
	k   int
	arr []int
}

func main() {
	input := getInput()

	curMax := input.k
	cans := 0
	for i := range input.arr {
		if input.arr[i] > curMax {
			additionalCans := input.arr[i] - curMax
			curMax += additionalCans
			cans += additionalCans
		}
	}

	fmt.Println(cans)
}

func getInput() (i input) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	numInts, _ := strconv.Atoi(scanner.Text())

	scanner.Scan()
	i.k, _ = strconv.Atoi(scanner.Text())

	i.arr = make([]int, numInts)

	for x := 0; x < numInts; x++ {
		scanner.Scan()
		i.arr[x], _ = strconv.Atoi(scanner.Text())
	}

	return i
}
