#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<pair<int, int>> q;
    q.push({ numbers[0], 1 });
    q.push({ -1 * numbers[0], 1 });
    while (!q.empty()) {
        int n = q.front().first;
        int c = q.front().second;
        q.pop();
        if (c == numbers.size()) {
            if (n == target) answer++;
            continue;
        }
        q.push({ n + numbers[c], c + 1 });
        q.push({ n - numbers[c], c + 1 });
    }

    return answer;
}
