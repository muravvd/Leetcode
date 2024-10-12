/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.

Those numbers for which this process ends in 1 are happy.
*/

package main

import (
	"fmt"
)

type Set map[int]struct{}

func (s Set) Find(value int) bool {
	_, exists := s[value] // Check if the key exists in the map
	return exists
}

func isHappy(n int) bool {
	mySet := make(Set)
	for !mySet.Find(n) {
		if n == 1 {
			return true
		}
		mySet[n] = struct{}{}
		n = getNext(n)
	}
	return false
}

func getNext(n int) int {
	res := 0
	for n > 0 {
		res += (n % 10) * (n % 10)
		n /= 10
	}
	return res
}

func main() {
	fmt.Println(isHappy(19))
}
