#include <string>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> users;
vector<int> emoticons;
vector<int> answer;

void calPrice(vector<int> salePercent) {
    int service = 0;
    int totalSale = 0;
    for (int i = 0; i < N; i++) {
        int rate = users[i][0];
        int price = users[i][1]; // 이모티콘 플러스 가입 기준 가격
        int total = 0;           // 이모티콘을 개별로 구매했을 때 누적 가격
        for (int j = 0; j < M; j++) {
            if (salePercent[j] >= rate) { // 구매한다면
                total += emoticons[j] * (100 - salePercent[j]) / 100;
            }
        }
        if (total >= price) {
            service++;
        }
        else {
            totalSale += total;
        }
    }
    if (service > answer[0]) {
        answer[0] = service;
        answer[1] = totalSale;
    }
    else if (service == answer[0] && totalSale > answer[1]) { answer[1] = totalSale; }
}

void bruteForce(vector<int> salePercent, int num) {
    if (num == M) {
        calPrice(salePercent);
        return;
    }
    salePercent[num] = 40;
    bruteForce(salePercent, num + 1);
    salePercent[num] = 30;
    bruteForce(salePercent, num + 1);
    salePercent[num] = 20;
    bruteForce(salePercent, num + 1);
    salePercent[num] = 10;
    bruteForce(salePercent, num + 1);
}

vector<int> solution(vector<vector<int>> userstmp, vector<int> emoticonstmp) {
    users = userstmp;
    emoticons = emoticonstmp;
    N = users.size();
    M = emoticons.size();
    answer.resize(2, 0);
    vector<int> salePercent(M);
    bruteForce(salePercent, 0);

    return answer;
}