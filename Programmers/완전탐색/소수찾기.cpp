#include <string>
#include <vector>

using namespace std;

bool isVisited[6] = { 0, };
bool isMake[10000000] = { 0, };
string n;

bool isPrime() {
    int number = stoi(n);
    if (number < 2 || isMake[number]) return false;
    isMake[number] = true;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int makeN(string numbers, int ans) {
    for (int i = 0; i < numbers.size(); i++) {
        if (!isVisited[i]) {
            isVisited[i] = true;
            n = n + numbers[i];
            ans = makeN(numbers, ans);
            n = n.substr(0, n.size() - 1);
            isVisited[i] = false;
        }
    }
    if (n.size() > 0 && isPrime()) { ans++; }
    return ans;
}

int solution(string numbers) {
    int answer = makeN(numbers, 0);
    return answer;
}