class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int maxprofit = 0, buy = 0, sell = 0;
        bool increase = false;
        for(int i = 1; i<prices.size(); i++){
            if(prices.at(i)>prices.at(i-1)){
                if(!increase){
                  increase = true;
                  buy = i-1;
                }
            }
            else{
                if(increase){
                  increase = false;
                  sell = i-1;
                  maxprofit =  maxprofit + prices.at(sell)-prices.at(buy);
                }
            }
            if(increase&&i==prices.size()-1){
                sell = i;
                maxprofit =  maxprofit + prices.at(sell)-prices.at(buy);
            }
            
        }
        return maxprofit;
    }
};