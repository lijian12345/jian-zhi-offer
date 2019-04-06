#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution
{
  public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        vector<int> result;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int start = 0;
        while (rows > start * 2 && cols > start * 2)
        {
            appendMatrixInCircle(matrix, start, rows, cols, result);
            start++;
        }
        return result;
    }

    void appendMatrixInCircle(vector<vector<int>> matrix, int start, int rows, int cols, vector<int> &result)
    {
        int endX = cols - 1 - start;
        int endY = rows - 1 - start;
        for (int i = start; i <= endX; i++)
        {
            result.push_back(matrix[start][i]);
        }
        if (start < endY)
        {
            for (int i = start + 1; i <= endY; i++)
                result.push_back(matrix[i][endX]);
        }
        if (start < endX && start < endY)
        {
            for (int i = endX - 1; i >= start; i--)
                result.push_back(matrix[endY][i]);
        }
        if (start < endX && start < endY - 1)
        {
            for (int i = endY - 1; i >= start + 1; i--)
                result.push_back(matrix[i][start]);
        }
    }
};