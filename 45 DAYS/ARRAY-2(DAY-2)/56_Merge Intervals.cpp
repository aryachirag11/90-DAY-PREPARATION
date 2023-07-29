#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// brute force
vector<vector<int>> merge1(vector<vector<int>> &intervals)
{
  int n = intervals.size();
  vector<vector<int>> ans;
  // sort the intervals
  sort(intervals.begin(), intervals.end());

  for (int i = 0; i < n; i++)
  {
    // selecting interval
    int start = intervals[i][0];
    int end = intervals[i][1];

    // skipping all the merged intervals
    if (!ans.empty() && end <= ans.back()[1])
      continue;

    // checking the remaing intervals
    for (int j = i + 1; j < n; j++)
    {
      if (intervals[j][0] <= end)
        end = max(end, intervals[j][1]);
      else
        break;
    }

    // pusging the merged interval in ans
    ans.push_back({start, end});
  }
  return ans;
}

// optimal solution
vector<vector<int>> merge2(vector<vector<int>> &intervals)
{
  int n = intervals.size();
  sort(intervals.begin(), intervals.end());
  vector<vector<int>> ans;

  for (int i = 0; i < n; i++)
  {

    if (ans.empty() || intervals[i][0] > ans.back()[1])
    {
      ans.push_back(intervals[i]);
    }

    else
    {
      ans.back()[1] = max(ans.back()[1], intervals[i][1]);
    }
  }
  return ans;
}
int main()
{
  return 0;
}