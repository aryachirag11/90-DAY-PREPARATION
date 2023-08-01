#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ---------------DP Solution---------------
int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp)
{
  if (i == (m - 1) && j == (n - 1))
    return 1;
  if (i >= m || j >= n)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j]; // checking if sol^n is present in dp
  else
  {
    dp[i][j] = countPaths(i + 1, j, m, n, dp)    // down move
               + countPaths(i, j + 1, m, n, dp); // right move
    return dp[i][j];
  }
}

int uniquePaths1(int m, int n)
{
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

  int paths_Count = countPaths(0, 0, m, n, dp);

  if (m == 1 && n == 1)
    return paths_Count;

  return dp[0][0];
}

// ----------------Combinatorics Solution-----------
int uniquePaths2(int m, int n)
{
  // calculation nCr
  int no_of_moves = m + n - 2;     // total moves
  int no_of_chosesn_moves = m - 1; // right or down moves your wish
  double Combinations = 1.0;

  for (int i = 1; i <= no_of_chosesn_moves; i++)
    Combinations = Combinations * (no_of_moves - no_of_chosesn_moves + i) / i;

  return (int)Combinations;
}

int main()
{
  return 0;
}