class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        random_shuffle(nums.begin(), nums.end());
        return quickSelect(nums, 0, nums.size()-1, k);
    }
private:

    int quickSelect(vector<int>& nums, int start, int end, int k) {
        int targetIndex = nums.size() - k;
        int mid;
        while (start < end) {
            mid = partition(nums, start, end);
            if (targetIndex == mid) {
                return nums[mid];
            } else if (targetIndex > mid) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return nums[start];
    }

    int partition(vector<int>& nums, int leftBound, int rightBound) {
        int leftIndex = leftBound, rightIndex = rightBound + 1;
        int pivot = nums[leftIndex];
        while (true) {
            while (nums[++leftIndex] < pivot) {
                if (leftIndex >= rightBound) {
                    break;
                }
            }

            while (nums[--rightIndex] > pivot) {
                if (rightIndex <= leftBound) {
                    break;
                }
            }

            if (leftIndex >= rightIndex) {
                break;
            }

            swap(nums[leftIndex], nums[rightIndex]);
        }
        swap(nums[leftBound], nums[rightIndex]);
        return rightIndex;
    }
};