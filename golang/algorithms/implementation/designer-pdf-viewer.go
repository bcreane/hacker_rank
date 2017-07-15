package main

import "bufio"
import "fmt"
import "os"
import "strconv"

type input struct {
	heights []int
	letters []int
}

func main() {
	input := getInput()

	maxHeight := 0
	for x := range input.letters {
		curHeight := input.heights[input.letters[x]]
		if curHeight > maxHeight {
			maxHeight = curHeight
		}
	}

	fmt.Println(maxHeight * len(input.letters))
}

func getInput() (i input) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	i.heights = make([]int, 26)
	for x := 0; x < 26; x++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		i.heights[x] = num
	}

	scanner.Scan()
	text := scanner.Text()

	i.letters = make([]int, len(text))
	for x := range text {
		i.letters[x] = int(text[x] - 'a')
	}

	return i
}
