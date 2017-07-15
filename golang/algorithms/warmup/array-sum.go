package main

import "fmt"

func getNumElements() uint32 {
	var numElems uint32
	fmt.Scanf("%d\n", &numElems)

	return numElems
}

func sumArray(a []int) int {
	var sum int

	for i := range a {
		sum += a[i]
	}

	return sum
}

func main() {
	numElems := getNumElements()

	a := make([]int, numElems)

	for i := range a {
		fmt.Scanf("%d", &a[i])
	}

	fmt.Println(sumArray(a))
}
