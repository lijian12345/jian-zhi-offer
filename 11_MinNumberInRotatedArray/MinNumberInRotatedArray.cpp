#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <ctime>
using namespace std;

int MinInOrder(int *numbers, int index1, int index2)
{
    int result = numbers[index1];
    for (int i = index1 + 1; i <= index2; i++)
    {
        if (result > numbers[i])
            result = numbers[i];
    }
    return result;
}

int Min(int *numbers, int length)
{
    if (numbers == nullptr || length <= 0)
    {
        logic_error e("Invalid parameters.");
        throw new exception(e);
    }
    int i = 0, j = length - 1;
    int mid = i;
    while (numbers[i] >= numbers[j])
    {
        if (j - i == 1)
        {
            mid = j;
            break;
        }

        mid = (j - i) / 2 + i;
        if (numbers[i] == numbers[j] && numbers[mid] == numbers[i])
            return MinInOrder(numbers, i, j);
        if (numbers[mid] >= numbers[i])
            i = mid;
        if (numbers[mid] <= numbers[j])
            j = mid;
    }
    return numbers[mid];
}

int MinInOrder(vector<int> numbers, int index1, int index2)
{
    int result = numbers[index1];
    for (int i = index1 + 1; i <= index2; i++)
    {
        if (result > numbers[i])
            result = numbers[i];
    }
    return result;
}
int minNumberInRotateArray(vector<int> rotateArray)
{
    int i = 0, j = rotateArray.size() - 1;
    int mid = 0;
    while (rotateArray[i] >= rotateArray[j])
    {
        if (j - i == 1)
        {
            mid = j;
            break;
        }
        mid = (j - i) / 2 + i;
        if (rotateArray[i] == rotateArray[j] && rotateArray[mid] == rotateArray[i])
            return MinInOrder(rotateArray, i, j);
        if (rotateArray[mid] >= rotateArray[i])
            i = mid;
        if (rotateArray[mid] <= rotateArray[j])
            j = mid;
    }
    return rotateArray[mid];
}

int main()
{
    return 0;
}