/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
	int maxPoints(vector<Point> &points) {
		// https://oj.leetcode.com/problems/max-points-on-a-line/
		//
		// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
		//
		int result = 0;
		for (Point &begin : points) {
			// map line to count of points on this line, exclude 'start' point
			// notice how we defines hash and == operator in order to use map<> for customized type
			unordered_map<Line, int, Line::Hash> lines;
			int dup = 0;
			int localMax = 0;
			for (Point &end : points) {
				if (equ(begin, end)) { // there will be at least one dup (to 'start' point itself)
					dup++;
					continue;
				}
				Line line(begin, end);
				lines[line]++;
				localMax = max(localMax, lines[line]);
			}
			localMax += dup;
			result = max(result, localMax);
		}
		return result;
	}
	static bool equ(const Point &p1, const Point &p2) {
		return (p1.x == p2.x) && (p1.y == p2.y);
	}
	struct Line {
		// aX + bY = c
		int a;
		int b;
		int c;
		Line(Point &p1, Point &p2) {
			a = p2.y - p1.y;
			b = p1.x - p2.x;
			c = p1.x * p2.y - p2.x * p1.y;
			int g = gcd(a, b);
			g = gcd(g, c);
			a /= g;
			b /= g;
			c /= g;
		}
		static int gcd(int x, int y) {
			// greatest common divisor
			while (y != 0) {
				int g = x % y;
				x = y;
				y = g;
			}
			return x;
		}
		bool operator == (const Line& line) const {
			return a == line.a && b == line.b && c == line.c;
		}
		struct Hash {
			size_t operator() (const Line& line) const {
				return hash<int>()(line.a) ^ hash<int>()(line.b) ^ hash<int>()(line.c);
			}
		};
	};
	void test() {
		vector<Point> points = { { 0, 0 }, { 1, 0 } };
		int n = maxPoints(points);
		cout << n << endl;
	}
};
