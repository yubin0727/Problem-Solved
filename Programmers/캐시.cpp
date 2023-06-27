#include <string>
#include <vector>

using namespace std;

// 문자열 모두 소문자로 바꾸기
string tolowerString(string s) {
    string tmp;
    for (int i = 0; i < s.size(); i++) tmp += tolower(s[i]);
    return tmp;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache(cacheSize, ""); // cache[0] -> 사용된지 가장 오래 됨

    for (int i = 0; i < cities.size(); i++) {
        string curCity = tolowerString(cities[i]);
        bool isHit = false; // cache hit인지 아닌지

        for (int j = 0; j < cacheSize; j++) { // cache에 도시 이름이 있는지 검색
            // cache hit
            if (curCity == cache[j]) {
                cache.erase(cache.begin() + j);
                isHit = true;
                answer += 1;
                break;
            }
        }
        if (!isHit) { // cache miss라면
            answer += 5;
            if (cache.size() != 0) {
                cache.erase(cache.begin());
            }
        }

        // 마지막 원소 뒤에 도시 삽입
        cache.push_back(curCity);
    }
    return answer;
}