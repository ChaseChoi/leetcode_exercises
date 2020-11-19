class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> count(ratings.size(),1);
        int total = 0;
        
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i-1] < ratings[i]) {
                count[i] = count[i-1] + 1;
            }
        }
        
        for (int k = ratings.size()-2; k >= 0; --k) {
            if (ratings[k] > ratings[k+1] && count[k] <= count[k+1]) {
                count[k] = count[k+1]+1;
            }
        }
        
         for (int z = 0; z < ratings.size(); ++z) {
            total += count[z];
        }
        
        return total;
    }
};
