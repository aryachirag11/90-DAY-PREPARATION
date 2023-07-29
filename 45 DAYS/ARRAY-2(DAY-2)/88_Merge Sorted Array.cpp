#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// brute force
void merge1(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
  vector<int> ans;
  int i = 0;
  int j = 0;
  while (i < m && j < n)
  {
    if (nums1[i] <= nums2[j])
    {
      ans.push_back(nums1[i]);
      i++;
    }
    else
    {
      ans.push_back(nums2[j]);
      j++;
    }
  }
  while (i < m)
  {
    ans.push_back(nums1[i]);
    i++;
  }
  while (j < n)
  {
    ans.push_back(nums2[j]);
    j++;
  }

  nums1.clear();

  for (int i = 0; i < m + n; i++)
  {
    nums1.push_back(ans[i]);
  }
}

// optimal approach
void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
  int i = m - 1;     // nums1's index (actual nums)
  int j = n - 1;     // nums2's index
  int k = m + n - 1; // nums1's index (next filled position)

  // revrse in reverse order
  while (j >= 0)
    if (i >= 0 && nums1[i] > nums2[j])
      nums1[k--] = nums1[i--];
    else
      nums1[k--] = nums2[j--];
}

int main()
{
  return 0;
}
