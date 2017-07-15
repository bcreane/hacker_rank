package main

import "fmt"

func main() {
	var n int

	fmt.Scanf("%d", &n)

	people := 5
	sum := 0
	for day := 0; day < n; day++ {
		people = people / 2
		sum += people
		people *= 3
	}
	fmt.Println(sum)
}
