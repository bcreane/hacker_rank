package main

import "fmt"

func getNumStudents() (numStudents uint32) {
	fmt.Scanf("%d", &numStudents)
	return numStudents
}

func getGrades() []int {
	numStudents := getNumStudents()
	grades := make([]int, numStudents)
	for i := range grades {
		fmt.Scanf("%d", &grades[i])
	}

	return grades
}

func roundGrades(grades []int) {
	for i := range grades {
		if grades[i] >= 38 {
			nextMultiple := ((grades[i] / 5) + 1) * 5
			if nextMultiple-grades[i] < 3 {
				grades[i] = nextMultiple
			}
		}
	}
}

func printGrades(grades []int) {
	for i := range grades {
		fmt.Println(grades[i])
	}
	fmt.Println()
}

func main() {
	grades := getGrades()
	roundGrades(grades)
	printGrades(grades)
}
