#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for (int i = 1; i <= s.size() / 2; i++) {
        string tmp = "";
        int same = 1; // ���� ���ڿ��� ���� ����
        string curString = s.substr(0, i); // curString - ���� �ֱٿ� �߶��� ���ڿ� ����
        int j = i;
        for (; j + i <= s.size(); j += i) {
            if (curString.compare(s.substr(j, i)) == 0) { // ���� ���ڿ��� ���ٸ�
                same++;
            }
            else { // ���� ���ڿ��� �ٸ��ٸ�
                if (same == 1) {
                    tmp += curString;
                }
                else {
                    tmp = tmp + to_string(same) + curString;
                    same = 1;
                }
                curString = s.substr(j, i);
            }
        }
        if (same == 1) {
            tmp += curString;
        }
        else {
            tmp += to_string(same) + curString;
            same = 1;
        }
        tmp += s.substr(j); // ���� �κ��� �߸��� ũ��(i)���� �۴ٸ� ���� �Ұ��� -> ���� �κ� �ٿ���
        if (answer > tmp.size()) answer = tmp.size();
    }
    return answer;
}