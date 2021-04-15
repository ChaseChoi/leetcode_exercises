class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int count = 1;
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }

        while (k != count) {
            nextPermutation(nums);
            count++;
        }

        string res;
        for (int j = 0; j < nums.size(); ++j) {
            res += char(48 + nums[j]);
        }
        return res;
    }
private:

    void nextPermutation(vector<int>& nums) {
        int index = -1;
        for (int end = nums.size() - 1; end > 0; --end) {
            if (nums[end - 1] < nums[end]) {
                index = end;
                break;
            }
        }

        if (index == -1) {
            reverse(nums.begin(), nums.end());
        }
        int max = index;
        for (int i = index; i <= nums.size() - 1; ++i) {
            if (nums[index - 1] < nums[i]) {
                max = i;
            }
        }

        swap(nums[max], nums[index - 1]);
        reverse(nums.begin() + index, nums.end());
    }
};