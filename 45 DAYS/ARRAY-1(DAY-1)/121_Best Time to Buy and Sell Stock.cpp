class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int minPrice = INT_MAX;
    int maximumProfit = 0;

    for (int i = 0; i < prices.size(); i++)
    {
      minPrice = min(minPrice, prices[i]);
      maximumProfit = max(maximumProfit, prices[i] - minPrice);
    }
    return maximumProfit;
  }
};