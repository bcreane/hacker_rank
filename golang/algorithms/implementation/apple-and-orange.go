package main

import "fmt"

type positions struct {
	houseLeft  int
	houseRight int
	appleTree  int
	orangeTree int
	apples     []int
	oranges    []int
}

func getPositions() positions {
	ft := positions{}
	fmt.Scanf("%d %d", &ft.houseLeft, &ft.houseRight)
	fmt.Scanf("%d %d", &ft.appleTree, &ft.orangeTree)

	numApples := 0
	numOranges := 0

	fmt.Scanf("%d %d", &numApples, &numOranges)
	ft.apples = make([]int, numApples)
	ft.oranges = make([]int, numOranges)

	for i := range ft.apples {
		fmt.Scanf("%d", &ft.apples[i])
	}

	for i := range ft.oranges {
		fmt.Scanf("%d", &ft.oranges[i])
	}

	return ft
}

func fruitsOnRoof(ft positions) (applesOnRoof int, orangesOnRoof int) {
	for i := range ft.apples {
		pos := ft.appleTree + ft.apples[i]
		if pos >= ft.houseLeft && pos <= ft.houseRight {
			applesOnRoof++
		}
	}

	for i := range ft.oranges {
		pos := ft.orangeTree + ft.oranges[i]
		if pos >= ft.houseLeft && pos <= ft.houseRight {
			orangesOnRoof++
		}
	}

	return applesOnRoof, orangesOnRoof
}

func main() {
	ft := getPositions()
	applesOnRoof, orangesOnRoof := fruitsOnRoof(ft)
	fmt.Printf("%d\n%d\n", applesOnRoof, orangesOnRoof)
}
