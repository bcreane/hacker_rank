package main

import "bufio"
import "fmt"
import "os"
import "sort"
import "strconv"

type input struct {
	arr []int
}

func main() {
	i := getInput()

	maxSetSize := 0
	for x := 0; x < len(i.arr)-1; x++ {
		currentSetSize := 1
		for y := x + 1; y < len(i.arr); y++ {
			if i.arr[y]-i.arr[x] <= 1 {
				currentSetSize++
			} else {
				break
			}
		}

		if currentSetSize > maxSetSize {
			maxSetSize = currentSetSize
		}
	}

	fmt.Println(maxSetSize)
}

func getInput() (i input) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	numInts, _ := strconv.Atoi(scanner.Text())
	i.arr = make([]int, numInts)

	for x := 0; x < numInts; x++ {
		scanner.Scan()
		i.arr[x], _ = strconv.Atoi(scanner.Text())
	}

	sort.Ints(i.arr)

	return i
}
