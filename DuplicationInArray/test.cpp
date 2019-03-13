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

class Solution
{
  public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    static bool duplicate(int numbers[], int length, int *duplication)
    {
        if (numbers == nullptr || length <= 0)
        {
            return false;
        }
        for (int i = 0; i < length; i++)
        {
            if (numbers[i] >= length || numbers[i] < 0)
            {
                return false;
            }
        }
        for (int i = 0; i < length; i++)
        {
            while (numbers[i] != i)
            {
                if (numbers[i] == numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;
                }
                else
                {
                    // #include <algorithm>
                    // using namespace std;
                    swap(numbers[i], numbers[numbers[i]]);
                }
            }
        }
        return false;
    }
};

int main()
{
    int a[] = {2, 3, 1, 0, 2, 5, 3};
    int b;
    cout << Solution::duplicate(a, sizeof(a) / sizeof(a[0]), &b);
    cout << b;
    return 0;
}