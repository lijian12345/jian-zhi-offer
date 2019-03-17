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

int RandomInRange(int start, int end)
{
    srand(time(NULL));
    return rand() % (end - start + 1) + start;
}

int Partition(int data[], int length, int start, int end)
{
    if (data == nullptr || length <= 0 || start < 0 || end >= length)
    {
        logic_error e("Invalid parameters.");
        throw new exception(e);
    }
    int index = RandomInRange(start, end);
    swap(data[index], data[start]);
    int temp = data[start];
    int i = start, j = end;
    while (i != j)
    {
        while (data[j] >= temp && i < j)
            j--;
        while (data[i] <= temp && i < j)
            i++;
        if (i < j)
            swap(data[i], data[j]);
    }
    data[start] = data[i];
    data[i] = temp;
    return i;
}

void quickSort(int data[], int length, int start, int end)
{
    if (start == end)
        return;
    int index = Partition(data, length, start, end);
    if (index > start)
        quickSort(data, length, start, index - 1);
    if (index < end)
        quickSort(data, length, index + 1, end);
}

int main()
{
    int data[] = {3, 6, 7, 9, 4, 2, 8, 0, 1, 5};
    quickSort(data, 10, 0, 9);
    for (auto i : data)
        printf("%d ", i);
    return 0;
}