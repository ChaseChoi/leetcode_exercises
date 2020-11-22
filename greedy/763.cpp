class Solution {
public:
    vector<int> partitionLabels(string S) {
        int rightBoundStore[26];
        int groupEnd = 0, groupBegin = 0;
        vector<int> answer;
        
        for (int i = 0; i < S.length(); ++i) {
            rightBoundStore[S[i]-97] = i;
        }
        
        for (int j = 0; j < S.length(); ++j) {
            
            if (rightBoundStore[S[j]-97] > groupEnd) {
                groupEnd = rightBoundStore[S[j]-97];
            }
            
            if (j == groupEnd) {
                int groupLength = groupEnd - groupBegin + 1;
                answer.push_back(groupLength);
                groupBegin = j + 1;
            }
        }
        return answer;
    }  
};