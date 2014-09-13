class Solution {
public:
	int sqrt(int x) {
		// https://oj.leetcode.com/problems/sqrtx/
		//
		// Compute and return the square root of integer x
		//
		typedef unsigned int uint;
		uint u = x;
		if (x < 0) {
			return -1;
		}
		// take uint8 for example, 0 ... 0xff
		// sqrt(0x100) = 0x10, anything in uint8 will < 0x10, which is half-size of uint8
		//
		int INT_BITS = sizeof(int)* 8;   // for uint8, it is 8
		int HALF_BITS = INT_BITS / 2;    // 4
		uint UINT_HALF = 1 << HALF_BITS; // 0x10
		uint mask = (UINT_HALF >> 1);    // 8, or '1000'
		uint result = 0;
		for (int i = 0; i < HALF_BITS; i++) {
			//  u1 .. xx100^2 .. u2 .. xx111^2 .. u3
			//     0             1 
			uint r = result + mask; // xx100 above
			if (r * r <= u) {
				result += mask;
			}
			mask >>= 1;
		}
		return result;
	}
	void test() {
		vector<int> v = { 0, 1, 2, 3, 4, 5, 100, 101, INT_MAX, 0x7fff * 0x7fff + 1 };
		for (int x : v) {
			cout << x << " : sqrt = " << sqrt(x) << endl;
		}
	}
};
