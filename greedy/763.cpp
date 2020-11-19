struct Element {
    int startIndex, endIndex;
    Element(int s, int e) {
        startIndex = s;
        endIndex = e;
    }
};
class Solution {
public:
    vector<int> partitionLabels(string S) {

        vector<int> result;
        
        vector<Element> charInterval;
        unordered_map<char, int> indexStore;
        
        int previousGroupEnd;
        int previousGroupStart = 0;

        for (int i = 0; i < S.length(); ++i) {
            if (indexStore.find(S[i]) == indexStore.end()) {
                Element current = Element(i, i);
                charInterval.push_back(current);
                indexStore[S[i]] = charInterval.size()-1;
            } else {
                int index = indexStore[S[i]];
                Element retrieved = charInterval[index];
                retrieved.endIndex = i;
                charInterval[index] = retrieved;
            }
        }
        previousGroupEnd = charInterval[0].endIndex;

        for (int j = 1; j < charInterval.size(); ++j) {
            int startIndex = charInterval[j].startIndex;

            if (startIndex < previousGroupEnd) {
                // overlap
                if (charInterval[j].endIndex > previousGroupEnd) {
                    previousGroupEnd = charInterval[j].endIndex;    
                }
            } else {
                int length = previousGroupEnd - previousGroupStart + 1;
                result.push_back(length);
                previousGroupStart = charInterval[j].startIndex;
                previousGroupEnd = charInterval[j].endIndex;
            }
        }
        int lastIndex = charInterval.size()-1;
        int lastStart = charInterval[lastIndex].startIndex;
        int lastEnd = charInterval[lastIndex].endIndex;
        if (previousGroupEnd < lastStart) {
            result.push_back(lastEnd-lastStart+1);
        } else if (lastEnd > previousGroupEnd) {
            result.push_back(lastEnd-previousGroupStart+1);
        } else {
            result.push_back(previousGroupEnd - previousGroupStart + 1);
        }
        return result;
    }
};