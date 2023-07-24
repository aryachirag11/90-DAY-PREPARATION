class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    int m = matrix[0].size();
    int col0 = 1; // track the 0th col

    // mark the rows and cols of 0 cell
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (matrix[i][j] == 0)
        {
          matrix[i][0] = 0;
          if (j != 0)
            matrix[0][j] = 0;
          else
            col0 = 0;
        }
      }
    }

    // make cell 0s for the marked rows and cols except the tracking keeping row and col
    for (int i = 1; i < n; i++)
    {
      for (int j = 1; j < m; j++)
      {
        if (matrix[i][j] != 0)
        {
          if (matrix[0][j] == 0 || matrix[i][0] == 0)
            matrix[i][j] = 0;
        }
      }
    }

    // checking for 0th row
    if (matrix[0][0] == 0)
    {
      for (int j = 0; j < m; j++)
        matrix[0][j] = 0;
    }

    // checking for 0th col
    if (col0 == 0)
    {
      for (int i = 0; i < n; i++)
        matrix[i][0] = 0;
    }
  }
};