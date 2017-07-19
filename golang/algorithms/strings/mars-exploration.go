package main

import "fmt"

const p = "SOS"

func main() {
	var s string
	fmt.Scanf("%s", &s)

	mismatchCount := 0
	for x := range s {
		if s[x] != p[x%3] {
			mismatchCount++
		}
	}
	fmt.Println(mismatchCount)
}
