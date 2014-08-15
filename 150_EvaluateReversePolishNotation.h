/*
 Author:     Chikun Hu, nicholas.hu.12ba@gmail.com
 Date:       Aug 13, 2014
 Problem:    Evaluate Reverse Polish Notation
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
 Notes:
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.

 Valid operators are +, -, *, /. Each operand may be an integer or another expression.

 Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 Solution: reference wikipedia
*/

class Solution {
public:
	// 参考：http://zh.wikipedia.org/wiki/逆波兰表示法 即可
	int evalRPN(vector<string> &tokens) {
		stack<int> stk;
		for (int i = 0; i < tokens.size(); ++i) {
			string word = tokens[i];
			char ch = word[0];
			if (word.size() > 1 || isdigit(ch))
				stk.push(str2int(word));
			else {
				int val2 = stk.top(); stk.pop();
				int val1 = stk.top(); stk.pop();
				if (ch == '+') stk.push(val1 + val2);
				else if (ch == '-') stk.push(val1 - val2);
				else if (ch == '*') stk.push(val1 * val2);
				else if (ch == '/') stk.push(val1 / val2);
			}
		}
		return stk.top();
	}

	int str2int(string& s) {
		int res = 0, flag = 1, i = 0;
		if (!isdigit(s[0])) {
			flag = s[0] == '+' ? 1 : -1;
			++i;
		}
		for (; i < s.size(); ++i)
			res = res * 10 + (s[i] - '0');
		return res*flag;
	}
};
 