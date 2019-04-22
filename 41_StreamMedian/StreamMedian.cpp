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
    priority_queue<int, vector<int>, less<int>> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;
    void Insert(int num)
    {
        if (maxQ.empty() || num < maxQ.top())
            maxQ.push(num);
        else
            minQ.push(num);
        if (maxQ.size() == minQ.size() + 2)
        {
            minQ.push(maxQ.top());
            maxQ.pop();
        }
        if (maxQ.size() == minQ.size() - 1)
        {
            maxQ.push(minQ.top());
            minQ.pop();
        }
    }

    double GetMedian()
    {
        return maxQ.size() == minQ.size() ? (maxQ.top() + minQ.top()) / 2.0 : maxQ.top();
    }
};