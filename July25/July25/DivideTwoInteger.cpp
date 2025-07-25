class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        bool isNegative = (dividend < 0) ^ (divisor < 0);

        long long ldividend = abs((long long)dividend);
        long long ldivisor = abs((long long)divisor);

        long long start = 0, end = ldividend, answer = 0;

        while (start <= end) {
            long long mid = start + ((end - start) >> 1);
            long long product = mid * ldivisor;

            if (product <= ldividend) {
                answer = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        if (isNegative) {
            answer = -answer;
        }

        return (int)answer;
    }
};
