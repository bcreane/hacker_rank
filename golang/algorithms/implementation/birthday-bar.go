package main

import "bufio"
import "fmt"
import "os"
import "strconv"

type input struct {
	blocks []int
	day    int
	month  int
}

func getInput() (i input) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	numBlocks, _ := strconv.Atoi(scanner.Text())

	i.blocks = make([]int, numBlocks)

	for x := 0; x < numBlocks; x++ {
		scanner.Scan()
		i.blocks[x], _ = strconv.Atoi(scanner.Text())
	}
	scanner.Scan()
	i.day, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	i.month, _ = strconv.Atoi(scanner.Text())

	return i
}

func main() {
	b := getInput()

	//fmt.Printf("%v\n", b)

	if b.month > len(b.blocks) {
		fmt.Println("Too few blocks for months")
		os.Exit(1)
	}

	var sum = 0
	for i := 0; i < b.month; i++ {
		sum += b.blocks[i]
	}

	var numSums = 0

	for i := 0; i <= len(b.blocks)-b.month; i++ {
		if sum == b.day {
			numSums++
		}
		if i < len(b.blocks)-b.month {
			sum -= b.blocks[i]
			sum += b.blocks[i+b.month]
		}
	}

	fmt.Println(numSums)
}
