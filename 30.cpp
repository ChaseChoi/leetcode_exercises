class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> quota, countdown;
        vector<int> result;
        
        if (words.size() == 0) {
            return result;
        }
        
        int wordLength = words[0].length();
        int intervalLength = words.size() * wordLength;

        for (auto word : words) {
            quota[word]++;
        }
        
        for (int i = 0; i < wordLength; ++i) {
            countdown = quota;
            int currentStartIndex = i, currentEndIndex = i;
            int bound = s.length() - wordLength;
            while (currentEndIndex <= bound) {
                string selectedWord = s.substr(currentEndIndex, wordLength);

                if (countdown.find(selectedWord) == countdown.end()) {
                    while (currentStartIndex < currentEndIndex) {
                        // order matters
                        string matched = s.substr(currentStartIndex, wordLength);
                        currentStartIndex += wordLength;
                        countdown[matched]++;
                    }
                    currentStartIndex += wordLength;
                    currentEndIndex += wordLength;
                } else {
                    // matched
                    currentEndIndex += wordLength;
                    // consumed one word
                    countdown[selectedWord]--;

                    while (countdown[selectedWord] < 0) {
                        countdown[s.substr(currentStartIndex, wordLength)]++;
                        currentStartIndex += wordLength;
                    }
                    
                    if (currentEndIndex == currentStartIndex + intervalLength) {
                        result.push_back(currentStartIndex);
                        countdown[s.substr(currentStartIndex, wordLength)]++;
                        currentStartIndex += wordLength;
                    }
                }
            }
        }
        return result;
    }
};