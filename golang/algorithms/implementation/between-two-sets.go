package main

import "fmt"
import "sort"

type sets struct {
	a []int
	b []int
}

func getSets() sets {
	s := sets{}
	var numA, numB int
	fmt.Scanf("%d %d", &numA, &numB)

	s.a = make([]int, numA)
	for i := range s.a {
		fmt.Scanf("%d", &s.a[i])
	}
	sort.Ints(s.a)

	s.b = make([]int, numB)
	for i := range s.b {
		fmt.Scanf("%d", &s.b[i])
	}
	sort.Ints(s.b)

	return s
}

func main() {
	s := getSets()
	fmt.Printf("%v\n", s)

	numBetween := 0

	for i := s.a[len(s.a)-1]; i <= s.b[0]; i++ {
		allEvenlyDivide := true
		for m := range s.a {
			if i%s.a[m] != 0 {
				allEvenlyDivide = false
			}
		}

		if allEvenlyDivide {
			allMultiples := true
			for n := range s.b {
				if s.b[n]%i != 0 {
					allMultiples = false
				}
			}
			if allMultiples {
				numBetween++
			}
		}
	}

	fmt.Println(numBetween)
}
