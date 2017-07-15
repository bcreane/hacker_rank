package main

import "fmt"
import "sort"

func sumArray(a []int) int {
	sum := 0

	for i := range a {
		sum += a[i]
	}
	return sum
}

func main() {
	a := make([]int, 5)

	for i := range a {
		fmt.Scanf("%d", &a[i])
	}

	sort.Ints(a)

	sum := sumArray(a)
	fmt.Printf("%d %d\n", sum-a[4], sum-a[0])
}
