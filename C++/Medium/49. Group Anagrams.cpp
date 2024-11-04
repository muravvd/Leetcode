/*
Given an array of strings strs, group the  anagrams together. You can return the answer in any order.

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void printVV(const vector<vector<string> > &vec) {
    for (const auto &inner_vec: vec) {
        for (const auto &word: inner_vec) {
            cout << word << " ";
        }
        cout << endl;
    }
}

bool isAnagram(string s1, string s2) {
    // frequency method, O(n)
    if (s1.length() != s2.length())
        return false;
    vector<int> count(26, 0);
    for (char c: s1)
        count[c - 'a']++;
    for (char c: s2) {
        count[c - 'a']--;
        if (count[c - 'a'] < 0)
            return false;
    }
    return true;
}

/*
class Solution {    // O(n^2), time limit exceeded
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector used(strs.size(), false);
        for (int i = 0; i < strs.size(); i++) {
            if (used[i])
                continue;
            vector cur = {strs[i]};
            used[i] = true;
            for (int j = i + 1; j < strs.size(); j++)
                if (!used[j] && isAnagram(strs[i], strs[j])) {
                    cur.push_back(strs[j]);
                    used[j] = true;
                }
            res.push_back(cur);
        }
        return res;
    }
};
*/

class Solution {    // O(n * len log len)       11ms    24mb
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> res;
        for (string& word: strs) {
            string keyword = word;
            sort(keyword.begin(), keyword.end());
            anagrams[keyword].push_back(word);
        }
        for (auto& set: anagrams)
            res.push_back(set.second);
        return res;
    }
};

/*
class Solution {    // key generation, O(n * len)   73ms   33mb
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (string word : strs) {
            vector<int> count(26, 0);
            for (char c : word)
                count[c - 'a']++;
            string key;
            for (int i : count)
                key += '#' + to_string(i);
            anagrams[key].push_back(word);
        }
        vector<vector<string>> res;
        for (const auto& set : anagrams)
            res.push_back(set.second);
        return res;
    }
};
*/

int main() {
    Solution test;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    printVV(test.groupAnagrams(strs));
    return 0;
}
