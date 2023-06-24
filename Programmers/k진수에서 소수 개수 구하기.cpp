#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

bool isPrime(long long num) {
    if (num == 1) return false;
    int mid = sqrt(num);
    for (int i = 2; i <= mid; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    int powN = 0;
    long long num = 0; // 0이 나올때까지 누적합누하기
    while (n != 0) {
        if (n % k != 0) {
            num += ((n % k) * pow(10, powN));
            powN++;
        }
        else {
            if (num != 0 && isPrime(num)) {
                answer++;
            }
            num = 0;
            powN = 0;
        }
        n /= k;
    }
    if (num != 0 && isPrime(num)) answer++;
    return answer;
}