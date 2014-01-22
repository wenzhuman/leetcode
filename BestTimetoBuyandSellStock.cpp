class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int min = 0, bestprofit = 0;
        for(int i = 0; i<prices.size(); i++){
            if(prices[i]<prices[min]){
                min = i;
            }
            int currentprofit = prices[i]-prices[min];
            if(prices[i]-prices[min]>bestprofit){
                bestprofit =  currentprofit;
            }
        }
        return bestprofit;
    }
};