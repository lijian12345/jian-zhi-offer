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
    vector<int> GetLeastNumbers_Solution(vector<int> &input, int k)
    {
        if (k == 0 || input.empty() || k > input.size())
            return vector<int>();
        if (k == input.size())
            return input;

        int low = 0;
        int high = input.size() - 1;
        int index = partition(input, low, high);
        while (index != k - 1)
        {
            if (index > k - 1)
                high = index - 1;
            else
                low = index + 1;
            index = partition(input, low, high);
        }
        vector<int> v;
        for (int i = 0; i < k; ++i)
            v.push_back(input[i]);
        return v;
    }

    int partition(vector<int> &input, int low, int high)
    {
        if (low < high)
        {
            int pivot = input[low];
            while (low < high)
            {
                while (low < high && input[high] >= pivot)
                    --high;
                input[low] = input[high];
                while (low < high && input[low] <= pivot)
                    ++low;
                input[high] = input[low];
            }
            input[low] = pivot;
        }
        return low;
    }
};

class Solution1
{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        int len = input.size();
        if (len <= 0 || k > len)
            return vector<int>();

        //仿函数中的greater<T>模板，从大到小排序
        multiset<int, greater<int>> leastNums;
        for (auto vec_it = input.begin(); vec_it != input.end(); vec_it++)
        {
            //将前k个元素插入集合
            if (leastNums.size() < k)
                leastNums.insert(*vec_it);
            else
            {
                //第一个元素是最大值
                multiset<int, greater<int>>::iterator greatest_it = leastNums.begin();
                //如果后续元素<第一个元素，删除第一个，加入当前元素
                if (*vec_it < *(leastNums.begin()))
                {
                    leastNums.erase(greatest_it);
                    leastNums.insert(*vec_it);
                }
            }
        }

        return vector<int>(leastNums.begin(), leastNums.end());
    }
};

int main()
{
    Solution1 s = Solution1();
    vector<int> v{4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> v2 = s.GetLeastNumbers_Solution(v, 4);
    for (int i = 0; i < v2.size(); ++i)
        cout << v2[i] << " ";
    // cout << "\n";
    // for (int i = 0; i < v.size(); ++i)
    //     cout << v[i] << " ";
}