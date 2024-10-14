/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

/*func nextNode(val int) *ListNode {		overflow on huge numbers, testcase #1566
	if val == 0 {
		return nil
	}
	return &ListNode{val % 10, nextNode(val / 10)}
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1.Val+l2.Val == 0 && l1.Next == nil && l2.Next == nil {
		return l1
	}
	if l1.Val == 0 && l1.Next == nil {
		return l2
	}
	if l2.Val == 0 && l2.Next == nil {
		return l1
	}
	sum := 0
	mp := 1
	for l1 != nil {
		sum += l1.Val * mp
		mp *= 10
		l1 = l1.Next
	}
	mp = 1
	for l2 != nil {
		sum += l2.Val * mp
		mp *= 10
		l2 = l2.Next
	}
	return &ListNode{sum % 10, nextNode(sum / 10)}
}*/

func printList(l *ListNode) {
	for l != nil {
		fmt.Printf("%d ", l.Val)
		l = l.Next
	}
	fmt.Println()
}

/* func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode { // 9ms
	sum := &ListNode{}
	temp, carry := sum, 0
	for l1 != nil || l2 != nil || carry > 0 {
		v1, v2 := 0, 0
		if l1 != nil {
			v1 = l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			v2 = l2.Val
			l2 = l2.Next
		}
		total := v1 + v2 + carry
		carry = total / 10
		temp.Next = &ListNode{
			Val: total % 10,
		}
		temp = temp.Next
	}
	return sum.Next
} */

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode { // 0ms
	sum := &ListNode{}
	temp, carry := sum, 0
	for l1 != nil && l2 != nil {
		v1, v2 := 0, 0
		v1 = l1.Val
		l1 = l1.Next
		v2 = l2.Val
		l2 = l2.Next
		total := v1 + v2 + carry
		carry = total / 10
		temp.Next = &ListNode{
			Val: total % 10,
		}
		temp = temp.Next
	}
	for l1 != nil {
		total := l1.Val + carry
		l1 = l1.Next
		carry = total / 10
		temp.Next = &ListNode{
			Val: total % 10,
		}
		temp = temp.Next
	}
	for l2 != nil {
		total := l2.Val + carry
		l2 = l2.Next
		carry = total / 10
		temp.Next = &ListNode{
			Val: total % 10,
		}
		temp = temp.Next
	}
	for carry > 0 {
		temp.Next = &ListNode{
			Val: carry % 10,
		}
		temp = temp.Next
		carry = carry / 10
	}
	return sum.Next
}

func main() {
	l1 := &ListNode{0, &ListNode{8, &ListNode{6, &ListNode{5, &ListNode{6, &ListNode{8, &ListNode{3, &ListNode{5, &ListNode{7, nil}}}}}}}}}
	l2 := &ListNode{6, &ListNode{7, &ListNode{8, &ListNode{0, &ListNode{8, &ListNode{5, &ListNode{8, &ListNode{9, &ListNode{7, nil}}}}}}}}}
	printList(l1)
	printList(l2)
	printList(addTwoNumbers(l1, l2))
	return
}
