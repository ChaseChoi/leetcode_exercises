class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x, mid, answer;
        if (x == 0) {
            return 0;
        }
        while (low <= high) {
            mid = low + (high - low) / 2;
            answer = x / mid;
            if (mid == answer) {
                return answer;
            } else if (mid > answer) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return high; // high < low
    }
};