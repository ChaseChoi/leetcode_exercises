class Solution {
public:

    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int low = 0, high = size - 1;
        for (int current = 0; current <= high; ++current) {
            if (nums[current] == 0) {
                swap(nums[current], nums[low++]);
            }

            if (nums[current] == 2) {
                swap(nums[current--], nums[high--]);
            }
        }
    }
};