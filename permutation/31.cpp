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
        int max = binarySearch(nums, index, nums.size()-1, nums[index-1]);
        
        swap(nums[max], nums[index-1]);
        reverse(nums.begin()+index, nums.end());
    }
private:
    int binarySearch(vector<int>& nums, int start, int end, int target) {

        while (start < end) {
            int mid = start + (end-start)/2;
            if (nums[mid] > target && nums[mid+1] <= target) {
                return mid;
            }
            if (nums[mid] <= target) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return start;
    }
};