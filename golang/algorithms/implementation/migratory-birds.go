package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	numInts, _ := strconv.Atoi(scanner.Text())

	frequency := make([]int, 5)

	for x := 0; x < numInts; x++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		frequency[num-1]++
	}

	biggest := frequency[0]
	index := 0
	for x := range frequency {
		if frequency[x] > biggest {
			biggest = frequency[x]
			index = x
		}
	}
	fmt.Println(index + 1)
}
