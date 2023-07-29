#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// optimal solution 1
vector<int> findMissingRepeatingNumbers1(vector<int> a)
{
  // Write your code here
  int n = a.size();
  int i = 0;
  while (i < n)
  {
    int index = a[i] - 1;
    if (a[i] != a[index])
      swap(a[i], a[index]);
    else
      i++;
  }

  for (int i = 0; i < n; i++)
  {
    if (a[i] != i + 1)
      return {a[i], i + 1};
  }
}

// optimal solution 2
vector<int> findMissingRepeatingNumbers2(vector<int> a)
{
  // Write your code here
  long long n = a.size();
  long long Sn = (n * (n + 1)) / 2;
  long long S2n = (n * (n + 1) * (2 * n + 1)) / 6;
  long long S1, S2;
  S1 = S2 = 0;

  for (int i = 0; i < n; i++)
  {
    S1 += a[i];
    S2 += (long long)a[i] * (long long)a[i];
  }

  long long val1 = S1 - Sn;
  long long val2 = S2 - S2n;
  val2 = val2 / val1;
  long long x = (val1 + val2) / 2;
  long long y = x - val1;

  return {(int)x, (int)y};
}

// optimal solution 3

int main()
{
  return 0;
}