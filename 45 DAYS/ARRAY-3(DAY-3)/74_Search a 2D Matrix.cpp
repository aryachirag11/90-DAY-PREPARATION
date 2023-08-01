#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
  if (matrix.empty())
    return 0;
  int m = matrix.size();
  int n = matrix[0].size();

  int s = 0;
  int e = m * n;

  while (s < e)
  {
    int mid = s + (e - s) / 2;
    int i = mid / n;
    int j = mid % n;

    if (matrix[i][j] == target)
      return 1;
    if (matrix[i][j] < target)
      s = mid + 1;
    else
      e = mid;
  }

  return 0;
}

int main()
{
  return 0;
}