#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int, int>> truck;
    int sum = 0;
    int i = 0;
    while (i < truck_weights.size()) {
        answer++;
        if (!truck.empty() && answer - truck.front().second >= bridge_length) {
            sum -= truck.front().first;
            truck.pop();
        }
        if (sum + truck_weights[i] > weight) { continue; }
        truck.push({ truck_weights[i], answer });
        sum += truck_weights[i];
        i++;
    }
    while (!truck.empty()) {
        answer = truck.front().second + bridge_length;
        truck.pop();
    }
    return answer;
}