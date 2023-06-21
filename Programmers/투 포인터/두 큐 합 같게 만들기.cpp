#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1 = 0;
    long long sum2 = 0;
    for (int i = 0; i < queue1.size(); i++) { // sum1 : queue1 ���� ��
        sum1 += queue1[i];
    }
    for (int i = 0; i < queue2.size(); i++) { // sum2 : queue2 ���� ��
        sum2 += queue2[i];
    }
    long long sum = (sum1 + sum2) / 2;
    if ((sum1 + sum2) % 2 == 1) return -1; // sum1+sum2 Ȧ�� -> �� ť �� ���� ���� �� ����

    vector<int> connect; // queue1, queue2 ���ļ� �ϳ��� ���ͷ� ����
    connect.insert(connect.begin(), queue1.begin(), queue1.end());
    connect.insert(connect.end(), queue2.begin(), queue2.end());
    int len = connect.size();
    int startIdx = 0;
    int endIdx = queue1.size() - 1;

    // �������� -> startIdx~endIdx�� queue1�� ����ִ� ���ҵ�
    while (startIdx <= endIdx) {
        if (sum1 == sum) {
            return startIdx + (endIdx - queue1.size() + 1);
        }
        if (sum1 > sum) { // queue1 > queue2
            sum1 -= connect[startIdx];
            startIdx++;
        }
        else { // queue1 < queue2
            endIdx++;
            if (endIdx >= len) break;
            sum1 += connect[endIdx];
        }
    }

    return -1;
}