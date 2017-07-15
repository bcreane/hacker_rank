package main

import "bufio"
import "fmt"
import "os"
import "strconv"

type input struct {
	steps []byte
}

func main() {
	i := getInput()

	currentAltitude := 0
	numOfValleys := 0

	for c := range i.steps {
		oldAltitude := currentAltitude
		switch i.steps[c] {
		case 'U':
			currentAltitude++
		case 'D':
			currentAltitude--
		default:
			fmt.Printf("Unknown step: %c\n", i.steps[c])
		}
		if oldAltitude < 0 && currentAltitude == 0 {
			numOfValleys++
		}
	}

	fmt.Println(numOfValleys)
}

func getInput() (i input) {
	scanWord := bufio.NewScanner(os.Stdin)
	scanWord.Split(bufio.ScanRunes) // read one rune (UTF8) at a time

	var num string // read each digit in the number ...
	for scanWord.Scan() {
		c := scanWord.Text()
		if c == "\n" {
			break
		}
		num += string(c)
	}

	numSteps, _ := strconv.Atoi(num)
	i.steps = make([]byte, numSteps)
	for x := 0; scanWord.Scan(); {
		c := scanWord.Text()
		if c != "\n" && c != " " {
			i.steps[x] = c[0]
			x++
		}
	}

	return i
}
