package main

import "bufio"
import "fmt"
import "os"
import "strconv"

type beasties struct {
	catA  int
	catB  int
	mouse int
}

func abs(i int) (x int) {
	if i < 0 {
		return -i
	}
	return i
}

func main() {
	i := getInput()
	for x := range i {
		distA := abs(i[x].catA - i[x].mouse)
		distB := abs(i[x].catB - i[x].mouse)

		if distA < distB {
			fmt.Println("Cat A")
		} else if distB < distA {
			fmt.Println("Cat B")
		} else {
			fmt.Println("Mouse C")
		}
		//fmt.Printf("%d %d %d\n", i[x].catA, i[x].catB, i[x].mouse)
	}
}

func getInput() (i []beasties) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	numQueries, _ := strconv.Atoi(scanner.Text())

	i = make([]beasties, numQueries)

	for x := 0; x < numQueries; x++ {
		scanner.Scan()
		i[x].catA, _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		i[x].catB, _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		i[x].mouse, _ = strconv.Atoi(scanner.Text())
	}

	return i
}
