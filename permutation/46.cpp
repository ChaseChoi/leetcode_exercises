class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        exchange(nums, 0);
        return result;
    }
private:
    vector<vector<int>> result;

    void exchange(vector<int> &nums, int position) {
        if (position == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = position; i < nums.size(); ++i) {
            swap(nums[position], nums[i]);
            exchange(nums, position+1);
            swap(nums[position], nums[i]);
        }
    }
};