/* Say you have an array for which the ith element is the price of a given stock
   on day i.
   Design an algorithm to find the maximum profit. You may complete as many
   transactions as you like (i.e., buy one and sell one share of the stock
   multiple times).
   Note: You may not engage in multiple transactions at the same time (i.e., you
   must sell the stock before you buy again).

    Example 1:

    Input: [7,1,5,3,6,4]
    Output: 7
    Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
                 Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
    Example 2:

    Input: [1,2,3,4,5]
    Output: 4
    Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
                 Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
                 engaging multiple transactions at the same time. You must sell before buying again.
   LC 122. Best Time to Buy and Sell Stock II
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
            if(prices[i] <= buying_price){
                buying_price = prices[i]; // buying price is min of current known price
            }
            if(prices[i] > buying_price) {
                selling_price = prices[i]; // update selling price and profit if higher price known
                max_profit =  max(max_profit, max_profit + (selling_price - buying_price));
                buying_price = selling_price; // update buying price, as current price, as the old price stock share sold
            }
        }
        return max_profit;
    }
};
