package main

import "bufio"
import "fmt"
import "os"
import "regexp"
import "strconv"

type input struct {
	s []string
}

func main() {
	input := getInput()

	re := regexp.MustCompile(".*h.*a.*c.*k.*e.*r.*r.*a.*n.*k.*")
	for x := range input.s {
		matched := re.MatchString(input.s[x])
		if matched {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

func getInput() (i input) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	numStrs, _ := strconv.Atoi(scanner.Text())

	i.s = make([]string, numStrs)

	for x := 0; x < numStrs; x++ {
		scanner.Scan()
		i.s[x] = scanner.Text()
	}

	return i
}
