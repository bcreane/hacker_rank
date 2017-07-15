package main

import "bufio"
import "fmt"
import "os"
import "strconv"

type input struct {
	availCash int
	usbCosts  []int
	keyCosts  []int
}

func main() {
	i := getInput()

	maxCost := -1
	for u := range i.usbCosts {
		for k := range i.keyCosts {
			cost := i.usbCosts[u] + i.keyCosts[k]
			if cost > maxCost && cost <= i.availCash {
				maxCost = cost
			}
		}
	}
	fmt.Println(maxCost)
}

func getInput() (i input) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	i.availCash, _ = strconv.Atoi(scanner.Text())

	scanner.Scan()
	numUsb, _ := strconv.Atoi(scanner.Text())
	i.usbCosts = make([]int, numUsb)

	scanner.Scan()
	numKey, _ := strconv.Atoi(scanner.Text())
	i.keyCosts = make([]int, numKey)

	for x := 0; x < numUsb; x++ {
		scanner.Scan()
		i.usbCosts[x], _ = strconv.Atoi(scanner.Text())
	}

	for x := 0; x < numKey; x++ {
		scanner.Scan()
		i.keyCosts[x], _ = strconv.Atoi(scanner.Text())
	}

	return i
}
