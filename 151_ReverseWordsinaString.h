/*
 Author:     Chikun Hu, nicholas.hu.12ba@gmail.com
 Date:       Aug 13, 2014
 Problem:    Reverse Words in a String 
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/reverse-words-in-a-string/
 Notes:
 Given an input string, reverse the string word by word.

	For example,
	Given s = "the sky is blue",
	return "blue is sky the".

	click to show clarification.

	Clarification:
	What constitutes a word?
	A sequence of non-space characters constitutes a word.
	Could the input string contain leading or trailing spaces?
	Yes. However, your reversed string should not contain leading or trailing spaces.
	How about multiple spaces between two words?
	Reduce them to a single space in the reversed string.
 Solution:  1. modify tokens(remove spaces).
			2. reverse all the string.
			3. reverse every word partly.
*/

class Solution {
public:
	// 能别用extra space就最好别用了
	void reverseWords(string &s) {
		int i = 0, j = 0;
		while (i<s.size()) {
			if (s[i] == ' ') {
				s[j++] = ' ';
				while (++i < s.size() && s[i] == ' ');
			}
			else
				s[j++] = s[i++];
		}
		int N = j;
		if (s[N - 1] == ' ') { s.erase(N - 1, 1); --N; }
		if (s[0] == ' ') { s.erase(s.begin()); --N; }
		if (N <= 0) { s = ""; return; }
		s.resize(N);
		reverse(s.begin(), s.end());
		for (int i = 0; i < s.size(); ++i) {
			int j = i + 1;
			for (; j < s.size(); ++j) {
				if (s[j] == ' ') {
					reverse(&s[i], &s[j]);
					i = j;
					break;
				}
			}
			if (j == s.size()) { reverse(&s[i], &s[j]); break; }
		}
	}
};
 