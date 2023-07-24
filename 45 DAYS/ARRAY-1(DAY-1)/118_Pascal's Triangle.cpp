class Solution
{
public:
  vector<int> generateRow(int rowNum)
  {
    int element = 1;
    vector<int> row;
    row.push_back(element);
    for (int col = 1; col < rowNum; col++)
    {
      element *= (rowNum - col);
      element /= col;
      row.push_back(element);
    }
    return row;
  }
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> pasTriangle;
    for (int i = 1; i <= numRows; i++)
    {
      pasTriangle.push_back(generateRow(i));
    }
    return pasTriangle;
  }
};