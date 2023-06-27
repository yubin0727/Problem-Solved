#include <string>
#include <vector>

using namespace std;

// ���ڿ� �и�
string splitString(string p) {
    string answer = "";
    bool isRight = true;

    if (p == "") return answer;
    if (p[0] == ')') isRight = false;
    string u, v;
    int n1 = 0; // "(" ����
    int n2 = 0; // ")" ����
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') n1++;
        else n2++;
        if (n1 == n2) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }

    // u�� �ùٸ� ���ڿ��̶��
    if (isRight) {
        answer += u;
        answer += splitString(v);
    }

    // u�� �ùٸ� ���ڿ��� �ƴ϶��
    else {
        answer += '(';
        answer += splitString(v);
        answer += ')';
        for (int i = 1; i < u.size() - 1; i++) {
            if (u[i] == '(') answer += ')';
            else answer += '(';
        }
    }

    return answer;
}

string solution(string p) {
    string answer = splitString(p);
    return answer;
}