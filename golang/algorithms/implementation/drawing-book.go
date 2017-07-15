package main

import "bufio"
import "fmt"
import "os"
import "strconv"

type input struct {
	numPages int
	page     int
}

func main() {
	i := getInput()
	if i.numPages%2 == 0 {
		i.numPages += 1
	}
	pagesFromBeginning := i.page / 2
	pagesFromEnd := (i.numPages - i.page) / 2

	fmt.Println(Min(pagesFromBeginning, pagesFromEnd))
}

func getInput() (i input) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	i.numPages, _ = strconv.Atoi(scanner.Text())

	scanner.Scan()
	i.page, _ = strconv.Atoi(scanner.Text())

	return i
}

func Min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
