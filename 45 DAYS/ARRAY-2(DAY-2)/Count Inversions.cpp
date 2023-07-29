#include <iostream>
#include <vector>
using namespace std;

// brute force
long long getInversions1(long long *arr, int n)
{
  // Write your code here.
  long long count = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[i])
        count++;
    }
  }
  return count;
}

// optimal solution
{

  int merge(vector<int> & arr, int low, int mid, int high)
  {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int count = 0;

    while (left <= mid && right <= high)
    {
      if (arr[left] <= arr[right])
      {
        temp.push_back(arr[left]);
        left++;
      }
      else
      {
        temp.push_back(arr[right]);
        count += (mid - left + 1);
        right++;
      }
    }
    while (left <= mid)
    {
      temp.push_back(arr[left]);
      left++;
    }
    while (right <= high)
    {
      temp.push_back(arr[right]);
      right++;
    }

    for (int i = low; i <= high; i++)
    {
      arr[i] = temp[i - low];
    }
    return count;
  }

  int merge_Sort(vector<int> & arr, int low, int high)
  {
    int count = 0;
    if (low >= high)
      return count;

    int mid = (low + high) / 2;

    count += merge_Sort(arr, low, mid);
    count += merge_Sort(arr, mid + 1, high);

    count += merge(arr, low, mid, high);

    return count;
  }

  long long getInversions(long long *arr, int n)
  {
    // Write your code here.
    vector<int> v;
    for (int i = 0; i < n; i++)
      v.push_back(arr[i]);
    return (long long)merge_Sort(v, 0, n - 1);
  }
}
int main()
{
  return 0;
}