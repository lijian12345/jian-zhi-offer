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

template <typename T>
class Solution
{
  public:
    void push(T node)
    {
        stack1.push(node);
    }

    T pop()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty())
        {
            logic_error e("queue is empty.");
            throw new exception(e);
        }
        T head = stack2.top();
        stack2.pop();
        return head;
    }

  private:
    stack<T> stack1;
    stack<T> stack2;
};