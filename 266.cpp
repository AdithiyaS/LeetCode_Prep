class Solution {
public:
    bool canPermutePalindrome(string s) {
        int freq[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            char c = s[i]; // get each character from the string
            int index =
                c - 'a';   // find its position (0 for 'a', 1 for 'b', ...)
            freq[index]++; // increase its count in the freq array
        }
        int odd = 0;
        for (int i = 0; i < 26; ++i)
            if (freq[i] % 2)
                ++odd;
        return odd <= 1;
    }
};

/*
266. Palindrome Permutation

Given a string s, return true if a permutation of the string could form a palindrome and false otherwise.

 

Example 1:

Input: s = "code"
Output: false
Example 2:

Input: s = "aab"
Output: true
Example 3:

Input: s = "carerac"
Output: true
 

Constraints:

1 <= s.length <= 5000
s consists of only lowercase English letters.
*/