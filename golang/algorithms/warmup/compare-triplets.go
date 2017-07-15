package main

import "fmt"

func myCompare(a []int, b []int) (int, int) {
	pa := 0
	pb := 0

	for i := range a {
		if a[i] > b[i] {
			pa++
		} else if b[i] > a[i] {
			pb++
		}
	}

	return pa, pb
}

func readVector(a []int) {
	for i := range a {
		fmt.Scanf("%d", &a[i])
	}
}

func main() {
	const vectorSize = 3

	a := make([]int, vectorSize)
	readVector(a)

	b := make([]int, vectorSize)
	readVector(b)

	pa, pb := myCompare(a, b)
	fmt.Printf("%d %d\n", pa, pb)
}
