class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell=1;
        int buy=0;
        int profit=0;
        while(sell<prices.size()){
            if(prices[sell]<prices[buy]){
                buy=sell;
            }
            else{
                profit=max(profit,prices[sell]-prices[buy]);
            }
            sell++;
        }
        return profit;
    }
};