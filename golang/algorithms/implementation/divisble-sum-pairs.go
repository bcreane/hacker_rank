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
	i := getInput()
	numEvenlyDivisibleIntoK := 0

	for x := 0; x < len(i.arr); x++ {
		for y := x + 1; y < len(i.arr); y++ {
			sum := i.arr[x] + i.arr[y]
			if sum%i.k == 0 {
				numEvenlyDivisibleIntoK++
				//fmt.Printf("%d + %d = %d\n", i.arr[x], i.arr[y], sum)
			}
		}
	}
	fmt.Println(numEvenlyDivisibleIntoK)
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
