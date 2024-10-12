package main

import "fmt"

func titleToNumber(columnTitle string) int {
	result := 0
	mult := 1
	for i := len(columnTitle) - 1; i >= 0; i-- {
		result += (int(columnTitle[i]) - int('A') + 1) * mult
		mult *= 26
	}
	return result
}

func main() {
	s := "ZY"
	fmt.Println(titleToNumber(s))
}
