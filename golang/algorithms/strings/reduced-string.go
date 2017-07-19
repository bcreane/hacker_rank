package main

import "fmt"

func reduce(s string) (r string) {
	for i := 0; i < len(s); i++ {
		if i < len(s)-1 && s[i] == s[i+1] {
			i++
		} else {
			r += string(s[i])
		}
	}
	return r
}

func main() {
	var s string
	fmt.Scanf("%s", &s)

	for {
		l := len(s)
		s = reduce(s)
		if l == len(s) {
			break
		}
	}
	if len(s) > 0 {
		fmt.Println(s)
	} else {
		fmt.Println("Empty String")
	}
}
