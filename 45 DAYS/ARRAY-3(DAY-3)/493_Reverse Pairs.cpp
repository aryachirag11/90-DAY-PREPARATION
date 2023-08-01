#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &nums, int low, int mid, int high)
{
  vector<int> temp;
  int left = low;
  int right = mid + 1;

  while (left <= mid && right <= high)
  {
    if (nums[left] <= nums[right])
    {
      temp.push_back(nums[left]);
      left++;
    }
    else
    {
      temp.push_back(nums[right]);
      right++;
    }
  }
  while (left <= mid)
  {
    temp.push_back(nums[left]);
    left++;
  }
  while (right <= high)
  {
    temp.push_back(nums[right]);
    right++;
  }

  for (int i = low; i <= high; i++)
  {
    nums[i] = temp[i - low];
  }
}

int countReversePairs(vector<int> &nums, int low, int mid, int high)
{
  int count = 0;
  int right = mid + 1;

  for (int i = low; i <= mid; i++)
  {
    while (right <= high && nums[i] > 2 * (long)(nums[right]))
      right++;
    count += (right - (mid + 1));
  }

  return count;
}

int merge_Sort(vector<int> &nums, int low, int high)
{
  int count = 0;
  if (low >= high)
    return count;

  int mid = (low + high) / 2;

  count += merge_Sort(nums, low, mid);
  count += merge_Sort(nums, mid + 1, high);
  count += countReversePairs(nums, low, mid, high);

  merge(nums, low, mid, high);

  return count;
}

int reversePairs(vector<int> &nums)
{
  int n = nums.size();
  return merge_Sort(nums, 0, n - 1);
}

int main()
{
  return 0;
}
