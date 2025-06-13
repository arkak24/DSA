// we will be given an array of stock prices as day increased(according to index)
// we have to find the best time to buy or sell a stock and have to maximise the profit
// we can only sell the stock after it has been bought

// try to find the day too, when to buy and sell the stock considering array start with day 1

// TC : O(n); SC : O(1)

// if selling in the i'th day when we must buy in any day between 0->(i-1)'th day
// so check every index

#include <iostream>
#include <vector>

int maximum_profit(std::vector<int> &prices){
      int minimum = prices[0];
      int max_profit = 0;
      for(int i = 1; i < prices.size(); i++){
            int cost = prices[i] - minimum;
            max_profit = std::max(max_profit, cost);
            minimum = std::min(minimum, prices[i]);
      }
      return max_profit;
}

int main(){
      std::vector<int> prices = {7, 1, 5, 3, 6, 4};
      int ans = maximum_profit(prices);
      std::cout << "The maximum profit will be " << ans << std::endl;

      return 0;
}