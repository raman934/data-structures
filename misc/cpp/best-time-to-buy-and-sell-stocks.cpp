/* Say you have an array for which the ith element is the price of a given
   stock on day i.
   If you were only permitted to complete at most one transaction (i.e., buy
   one and sell one share of the stock), design an algorithm to find the
   maximum profit.
   Note that you cannot sell a stock before you buy one.

    Example 1:

    Input: [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
                 Not 7-1 = 6, as selling price needs to be larger than buying price.
    Example 2:

    Input: [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transaction is done, i.e. max profit = 0.

   LC 121. Best Time to Buy and Sell Stock
   Author: Shruti
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        if(prices.size() <= 1) {
            return max_profit;
        }
        int buying_price = prices[0]; // initialize buying price
        int selling_price;
        for(int i = 1; i < prices.size(); i++) {
            buying_price = min(buying_price, prices[i]); // buying price is min of current known price
            if(prices[i] > buying_price) {
                selling_price = prices[i]; // update selling price and profit if higher price known
                max_profit =  max(max_profit, (selling_price - buying_price));
            }
        }
        return max_profit;
    }
};
