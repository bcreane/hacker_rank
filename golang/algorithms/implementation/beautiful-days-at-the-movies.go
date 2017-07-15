package main

import "bufio"
import "fmt"
import "os"
import "strconv"

type input struct {
	i int
	j int
	k int
}

func reverseDigits(d int) (r int) {
	r = 0
	for d > 0 {
		digit := d % 10
		d /= 10
		r = r*10 + digit
	}
	return r
}

func abs(d int) int {
	if d >= 0 {
		return d
	} else {
		return -d
	}
}

func main() {
	input := getInput()

	beautifulDays := 0
	for x := input.i; x <= input.j; x++ {
		diff := abs(x - reverseDigits(x))
		if diff%input.k == 0 {
			beautifulDays++
		}
	}
	fmt.Println(beautifulDays)
}

func getInput() (i input) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	i.i, _ = strconv.Atoi(scanner.Text())

	scanner.Scan()
	i.j, _ = strconv.Atoi(scanner.Text())

	scanner.Scan()
	i.k, _ = strconv.Atoi(scanner.Text())

	return i
}
