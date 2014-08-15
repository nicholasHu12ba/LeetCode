/*
 Author:     Chikun Hu, nicholas.hu.12ba@gmail.com
 Date:       Aug 13, 2014
 Problem:    Max Points on a Line
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/max-points-on-a-line/
 Notes:
 Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 Solution: take care with the vertical line & points with same value.
*/

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int maxPoints(vector<Point> &points) {
		if (points.size() <= 2) return points.size();
		int res = 2;
		unordered_map<float, int> mp;
		for (int i = 0; i < points.size(); ++i) {
			mp.clear();
			int vertical = 1, cur = 1, cnt = 0;	// vertical:单计垂线, 
												// cnt单计相同节点的个数
			for (int j = i + 1; j < points.size(); ++j) {
				if (points[j].y == points[i].y && points[j].x == points[i].x) { cnt++; continue; }
				if (points[j].x == points[i].x) { cur = max(cur, ++vertical); continue; }
				float k = (float)(points[j].y - points[i].y) / (points[j].x - points[i].x);
				if (mp.find(k) == mp.end()) { mp.insert(make_pair(k, 2)); cur = max(cur, 2); }
				else cur = max(cur, ++mp[k]);
			}
			cur += cnt;
			res = max(res, cur);
		}
		return res;
	}
};
 