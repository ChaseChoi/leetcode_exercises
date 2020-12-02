class Solution {
public:
    string frequencySort(string s) {
        string result = "";
        unordered_map<char, int> freqCount;
        map<int, string, greater <int> > countToLetter;

        for (const auto& letter: s) {
            ++freqCount[letter];
        }

        for (const auto& freqPair: freqCount) {
            countToLetter[freqPair.second] += string(freqPair.second, freqPair.first);
        }

        for (const auto& pair: countToLetter) {
            result += pair.second;
        }
        
        return result;
    }
};