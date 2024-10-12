/*
Write a function that takes the binary representation of a positive integer and returns the number of
set bits it has (also known as the Hamming weight).
11 -> 1011 -> 3
128 -> 10000000 -> 1
*/

package main

import (
	"fmt"
)

func hammingWeight(n int) int { // O(log n)
	res := 0
	for n > 0 {
		if n%2 == 1 {
			res++
		}
		n /= 2
	}
	return res
}

/*func hammingWeight(n int) int { // O(1)
	res := 0
	for i := 0; i <= 31; i++ {
		if (n>>i)&1 == 1 {
			res++
		}
	}
	return res
}*/

func main() {
	fmt.Println(hammingWeight(128)) // 30
}
