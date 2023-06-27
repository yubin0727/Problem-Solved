#include <string>
#include <vector>

using namespace std;

// ���ڿ� ��� �ҹ��ڷ� �ٲٱ�
string tolowerString(string s) {
    string tmp;
    for (int i = 0; i < s.size(); i++) tmp += tolower(s[i]);
    return tmp;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache(cacheSize, ""); // cache[0] -> ������ ���� ���� ��

    for (int i = 0; i < cities.size(); i++) {
        string curCity = tolowerString(cities[i]);
        bool isHit = false; // cache hit���� �ƴ���

        for (int j = 0; j < cacheSize; j++) { // cache�� ���� �̸��� �ִ��� �˻�
            // cache hit
            if (curCity == cache[j]) {
                cache.erase(cache.begin() + j);
                isHit = true;
                answer += 1;
                break;
            }
        }
        if (!isHit) { // cache miss���
            answer += 5;
            if (cache.size() != 0) {
                cache.erase(cache.begin());
            }
        }

        // ������ ���� �ڿ� ���� ����
        cache.push_back(curCity);
    }
    return answer;
}