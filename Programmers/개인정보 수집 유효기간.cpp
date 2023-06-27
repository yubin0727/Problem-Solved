#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<string, int> expire;

    int todayYear = stoi(today.substr(0, 4));
    int todayMonth = stoi(today.substr(5, 2));
    int todayDay = stoi(today.substr(8, 2));
    // 연도, 달 모두 계산해서 총 개월수로 바꿈
    int totalMonth = todayYear * 12 + todayMonth;

    for (int i = 0; i < terms.size(); i++) {
        stringstream ss(terms[i]);
        string type, duration;
        ss >> type >> duration;
        expire.insert({ type, stoi(duration) });
    }

    for (int i = 0; i < privacies.size(); i++) {
        stringstream ss(privacies[i]);
        string date, type;
        ss >> date >> type;
        int pYear = stoi(date.substr(0, 4));
        int pMonth = stoi(date.substr(5, 2));
        int pDay = stoi(date.substr(8, 2));
        int pExpire = expire[type];
        int pTotalMonth = pYear * 12 + pMonth + pExpire; // 총 개월 수 + 유효기간
        if (pTotalMonth < totalMonth) answer.push_back(i + 1);
        else if (pTotalMonth == totalMonth && pDay <= todayDay) answer.push_back(i + 1);
    }

    return answer;
}