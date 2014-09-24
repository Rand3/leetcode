class Solution {
public:
    double pow(double x, int n) {
        // https://oj.leetcode.com/problems/powx-n/
        //
        // x^n := x1 * x2 * x3 *... * xn
        // for example: x^13 = x^(8+4+1) = x^8 * x^4 * x^1
        if (n == 0) { return 1; }
        bool neg = false;
        unsigned int mask = 1;
        unsigned int top = ((unsigned int)(INT_MAX)+1);
        unsigned int u;
        if (n == INT_MIN) {
            u = top;
        }
        else {
            if (n > 0) {
                u = n;
            }
            else {
                u = -n;
                neg = true;
            }
        }
        double power = abs(x);
        double result = 1;
        while (u >= mask && mask != top) {
            if ((u & mask) != 0) {
                result *= power;
            }
            mask <<= 1;
            power = power * power;
        }
        if (neg) {
            result = 1 / result;
        }
        if (x < 0 && u % 2 != 0) {
            result = -result;
        }
        return result;
    }
    void test() {
        double result = pow(3.89707, 2);
    }
};
