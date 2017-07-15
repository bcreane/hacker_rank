package main

import "fmt"
import "sort"

func getNumCandles() (numCandles uint32) {
	fmt.Scanf("%d\n", &numCandles)
	return numCandles
}

func getSortedCandleHeights() []int {
	numElems := getNumCandles()
	a := make([]int, numElems)

	for i := range a {
		fmt.Scanf("%d", &a[i])
	}

	sort.Ints(a)
	return a
}

func main() {
	a := getSortedCandleHeights()

	numTallestCandles := 0
	for i := len(a) - 1; i >= 0; i-- {
		if a[i] == a[len(a)-1] {
			numTallestCandles++
		} else {
			break
		}
	}
	fmt.Println(numTallestCandles)
}
