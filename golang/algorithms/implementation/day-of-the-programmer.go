package main

import "fmt"

func main() {
	year := getYear()
	day := 13
	month := 9

	if year < 1918 {
		if is_leap_julian(year) {
			day -= 1
		}
	} else if year == 1918 {
		day += 13
		if is_leap_gregorian(year) {
			day -= 1
		}
	} else {
		if is_leap_gregorian(year) {
			day -= 1
		}
	}
	fmt.Println(fmt.Sprintf("%d.0%d.%d", day, month, year))
}

func is_leap_julian(year int) bool {
	return year%4 == 0
}

func is_leap_gregorian(year int) bool {
	return (year%400 == 0) || (year%100 != 0 && year%4 == 0)
}

func getYear() (year int) {
	fmt.Scanf("%d\n", &year)
	return year
}
