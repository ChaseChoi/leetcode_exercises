class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqCount;
        int maxCount = 0;
        vector<int> result;
        for (const auto& element: nums) {
            maxCount = max(++freqCount[element], maxCount);
        }

        vector<vector<int>> summary(maxCount+1);
        for (const auto& freqPair: freqCount) {
            summary[freqPair.second].push_back(freqPair.first);
        }

        for (int i = maxCount; i >= 0; --i) {
            if (summary[i].size()) {
                for (const auto& element: summary[i]) {
                    result.push_back(element);    
                    if (result.size() == k) {
                        return result;
                    }
                }
            }
        }

        return result;
    }
};