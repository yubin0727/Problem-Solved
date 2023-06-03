#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> tmp;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            tmp.push('(');
        else {
            if (tmp.size() == 0 || tmp.top() == ')') return false;
            else tmp.pop();
        }
    }
    if (tmp.size() > 0) answer = false;
    return answer;
}