package main

import "fmt"

func getNumScores() int {
	var numScores int
	fmt.Scanf("%d", &numScores)
	return numScores
}

func getScores() []int {
	numScores := getNumScores()
	scores := make([]int, numScores)
	for i := range scores {
		fmt.Scanf("%d", &scores[i])
	}
	return scores
}

func main() {
	scores := getScores()
	var minScore, maxScore int = scores[0], scores[0]
	var brokeLowCnt, brokeHighCnt int

	for i := range scores {
		if i > 0 {
			if scores[i] < minScore {
				minScore = scores[i]
				brokeLowCnt++
			} else if scores[i] > maxScore {
				maxScore = scores[i]
				brokeHighCnt++
			}
		}
	}

	fmt.Printf("%d %d\n", brokeHighCnt, brokeLowCnt)
}
