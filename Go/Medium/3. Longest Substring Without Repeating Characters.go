/*
Given a string s, find the length of the longest substring without repeating characters.
*/

package main

func lengthOfLongestSubstring(s string) int { // sliding window / 0ms
	start, maxL := 0, 0
	charPos := make(map[byte]int)
	for end := 0; end < len(s); end++ {
		pos, found := charPos[s[end]]
		if found && pos >= start {
			start = pos + 1
		}
		charPos[s[end]] = end
		if maxL < end-start+1 {
			maxL = end - start + 1
		}
	}
	return maxL
}

func main() {
	println(lengthOfLongestSubstring("abcabc"))
	return
}
