class Solution {
public:
    int forPos(vector<int>& arr) {
        int startingPos = INT_MAX;
        int start = 0, end = arr.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] > 0) {
                startingPos = min(startingPos, mid);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return startingPos;
    }

    int forNeg(vector<int>& arr) {
        int endingNeg = INT_MIN;
        int start = 0, end = arr.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] < 0) {
                endingNeg = max(endingNeg, mid);
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return endingNeg;
    }

    int maximumCount(vector<int>& nums) {
        int sp = forPos(nums);
        int en = forNeg(nums);
        int size = nums.size();

        if (sp == INT_MAX && en == INT_MIN) {
            return 0;
        }
        if (sp == INT_MAX) {
            return en + 1;
        }
        if (en == INT_MIN) {
            return size - sp;
        }

        int countPos = size - sp;
        int countNeg = en + 1;

        return max(countPos, countNeg);
    }
};