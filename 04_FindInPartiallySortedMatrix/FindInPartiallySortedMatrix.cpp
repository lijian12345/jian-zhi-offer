#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

bool Find(int *matrix, int rows, int columns, int number)
{
    int row = 0;
    int column = columns - 1;
    while (row < rows && column >= 0)
    {
        if (matrix[row * column + column] == number)
        {
            return true;
        }
        else if (matrix[row * column + column] > number)
        {
            column--;
        }
        else
        {
            row++;
        }
    }
    return false;
}

bool Find(int target, vector<vector<int>> array)
{
    int rows = array.size(), columns = array[0].size();
    int row = 0, column = columns - 1;
    while (row < rows && column >= 0)
    {
        if (array[row][column] == target)
        {
            return true;
        }
        else if (array[row][column] > target)
        {
            column--;
        }
        else
        {
            row++;
        }
    }
    return false;
}