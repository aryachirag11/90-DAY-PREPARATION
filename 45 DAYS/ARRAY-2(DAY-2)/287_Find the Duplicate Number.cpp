#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// brute force solution -> T.C : O(nlogn) S.C : O(1);
int findDuplicate1(vector<int> &nums)
{
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size() - 1; i++)
  {
    if (nums[i] == nums[i + 1])
      return nums[i];
  }
  return -1;
}

// frequency array solution -> T.C : O(n) S.C : O(n + 1);
int findDuplicate2(vector<int> &nums)
{
  int n = nums.size();
  vector<int> frequencies(n + 1, 0);

  for (int i = 0; i < n; i++)
  {
    if (frequencies[nums[i]] == 0)
      frequencies[nums[i]]++;
    else
      return nums[i];
  }
  return 0;
}

// mark the indexes  = value of elements -> T.C : O(n) S.C : O(1);
int findDuplicate3(vector<int> &nums)
{
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    int index = abs(nums[i]);
    if (nums[index] < 0)
      return index;
    nums[index] *= -1;
  }
  return -1;
}

// optimal solution (positioning method) -> T.C : O(n) S.C : O(1);
int findDuplicate4(vector<int> &nums)
{
  while (nums[0] != nums[nums[0]])
  {
    swap(nums[0], nums[nums[0]]);
  }
  return nums[0];
}

// Floyd's Cyclic Method -> T.C : O(n) S.C : O(1);
int findDuplicate5(vector<int> &nums)
{
  int smallStep = nums[0];
  int bigStep = nums[0];
  do
  {
    smallStep = nums[smallStep];
    bigStep = nums[nums[bigStep]];
  } while (smallStep != bigStep);

  bigStep = nums[0];
  while (smallStep != bigStep)
  {
    smallStep = nums[smallStep];
    bigStep = nums[bigStep];
  }
  return smallStep;
}

int main()
{
  int n;
  cout << "Enter array size : ";
  cin >> n;
  vector<int> arr(n);
  cout << "Enter " << n << " items : " << endl;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "The duplicate number is : " << findDuplicate5(arr);
  return 0;
}