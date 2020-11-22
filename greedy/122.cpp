class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() == 1) {
            return 0;
        }
        int answer = 0;
        for (int i = 1; i < prices.size(); ++i) {
            
            if (prices[i] > prices[i-1]) {
                answer += prices[i] - prices[i-1];
            }
            
        }
        return answer;
    }
};