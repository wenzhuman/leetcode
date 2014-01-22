class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int length = prices.size();
        vector<int> beforeProfit;
        beforeProfit.assign( length, 0);
        int lowest = 0, maxProfit1 = 0;
        for(int i = 0; i < length ; i++){
            int currentProfit = prices[i] - prices[lowest];
            if(currentProfit>maxProfit1){
                maxProfit1 = currentProfit;
            }
            beforeProfit[i] = maxProfit1; 
            if(prices[i]<prices[lowest]) 
            {
              lowest = i;
            }
        }
        vector<int> afterProfit;
        afterProfit.assign( length, 0);
        int highest = length - 1;
        int maxProfit2 = 0, maxProfit = 0;
        for(int i = length - 2; i>=0 ; i--){
            
            int currentProfit = prices[highest] - prices[i]; 
            if(prices[highest]<prices[i]){
                highest = i;
            }
            if(currentProfit>maxProfit2){
                maxProfit2 = currentProfit;
            }
            afterProfit[i] = maxProfit2;
            if(afterProfit[i]+beforeProfit[i]>maxProfit){
                maxProfit = afterProfit[i]+beforeProfit[i];
            }
            
        }
        return maxProfit;
    }
};