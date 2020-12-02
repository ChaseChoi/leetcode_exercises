class Solution {
public:
    string frequencySort(string s) {
        string result = "";
        unordered_map<char, int> freqCount;
        int maxCount = 0;
        for (const auto& letter: s) {
            maxCount = max(++freqCount[letter], maxCount);
        }

        vector<vector<int>> countToElement(maxCount+1);
        for (const auto& letterPair: freqCount) {
            countToElement[letterPair.second].push_back(letterPair.first);
        }

        for (int i = countToElement.size()-1; i >= 0; --i) {
            if (countToElement[i].size()) {
                for (const auto& letter: countToElement[i]) {
                    for (int j = 0; j < i; ++j) {
                        result += letter;                        
                    }
                }
            }
        }
        return result;
    }
};