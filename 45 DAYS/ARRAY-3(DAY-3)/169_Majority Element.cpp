#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int majorityElement(vector<int> &nums)
{
  int n = nums.size();
  int ele;
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    if (count == 0)
      ele = nums[i];

    if (nums[i] == ele)
      count++;

    else
      count--;
  }

  // return ele;

  int temp_cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] == ele)
      temp_cnt++;
  }

  if (temp_cnt > (n / 2))
    return ele;

  return -1;
}

int main()
{
  return 0;
}