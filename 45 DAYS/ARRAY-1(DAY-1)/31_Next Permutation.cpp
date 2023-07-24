class Solution
{
public:
  void nextPermutation(vector<int> &nums)
  {
    int breakPoint = -1;
    int n = nums.size();
    // findig the break point
    for (int i = n - 2; i >= 0; i--)
    {
      if (nums[i] < nums[i + 1])
      {
        breakPoint = i;
        break;
      }
    }

    // if breakPoint is not found-> last permutation in the order
    if (breakPoint == -1)
    {
      reverse(nums.begin(), nums.end());
      return;
    }

    // find the break point for the next permutation
    for (int i = n - 1; i > breakPoint; i--)
    {
      if (nums[i] > nums[breakPoint])
      {
        swap(nums[i], nums[breakPoint]);
        break;
      }
    }

    // rearrange the right to find the minimum
    reverse(nums.begin() + breakPoint + 1, nums.end());
  }
};