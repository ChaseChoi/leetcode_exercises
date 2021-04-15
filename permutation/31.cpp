class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        for (int end = nums.size()-1; end > 0; --end) {
            if (nums[end] > nums[end-1]) {
                index = end;
                break;
            }
        }

        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int max = index;
        for (int i = index; i <= nums.size()-1; ++i) {
            if (nums[index-1] < nums[i]) {
                max = i;
            }
        }
        swap(nums[max], nums[index-1]);
        reverse(nums.begin()+index, nums.end());
    }
};