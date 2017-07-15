package main

import "bufio"
import "fmt"
import "math"
import "os"
import "strconv"

type score struct {
	rank  int
	score int
}

type input struct {
	leaderboard  []score
	alicesScores []int
}

func getRank(leaderboard []score, alicesScore int, startSearch int) (int, int) {
	var l int = -1
	for l = len(leaderboard) - 1; l >= 0; l-- {
		if leaderboard[l].score > alicesScore {
			break
		}
	}

	rank := 1
	if l >= 0 {
		rank = leaderboard[l].rank + 1
	} else {
		l = 0
	}

	return rank, l
}

func main() {
	i := getInput()
	startSearch := len(i.leaderboard) - 1
	rank := 1
	for a := range i.alicesScores {
		rank, startSearch = getRank(i.leaderboard, i.alicesScores[a], startSearch)
		fmt.Println(rank)
	}
}

func getInput() (i input) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	numScores, _ := strconv.Atoi(scanner.Text())
	lb := make([]score, numScores)

	rank := 1
	lastScore := math.MaxInt32
	x := 0
	for cnt := 0; cnt < numScores; cnt++ {
		scanner.Scan()
		score, _ := strconv.Atoi(scanner.Text())
		if score < lastScore {
			rank++
		}
		lastScore = score
		lb[x].score = score
		lb[x].rank = rank
		x++
	}

	i.leaderboard = lb[1:x]

	fmt.Printf("%v, %v\n", lb, i.leaderboard)

	scanner.Scan()
	numScores, _ = strconv.Atoi(scanner.Text())
	i.alicesScores = make([]int, numScores)
	for x := 0; x < numScores; x++ {
		scanner.Scan()
		i.alicesScores[x], _ = strconv.Atoi(scanner.Text())
	}

	return i
}
