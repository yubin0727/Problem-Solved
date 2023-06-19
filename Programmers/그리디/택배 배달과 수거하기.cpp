#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    // n:배달할 집, cap:상자 최대 개수
    long long answer = 0;
    int farDeliver = n - 1; // 가장 멀리 있는 배달할 집
    int farPickup = n - 1;  // 가장 멀리 있는 픽업할 집
    while (farDeliver >= 0 && deliveries[farDeliver] == 0) { farDeliver--; }
    while (farPickup >= 0 && pickups[farPickup] == 0) { farPickup--; }
    while (true) {
        answer += max(farDeliver, farPickup) + 1;
        int tmp = 0;
        while (farDeliver >= 0 && tmp < cap) {
            if (tmp + deliveries[farDeliver] > cap) {
                deliveries[farDeliver] -= (cap - tmp);
                break;
            }
            else {
                tmp += deliveries[farDeliver];
                do {
                    farDeliver--;
                } while (farDeliver >= 0 && deliveries[farDeliver] == 0);
            }
        }

        tmp = 0;
        while (farPickup >= 0 && tmp < cap) {
            if (tmp + pickups[farPickup] > cap) {
                pickups[farPickup] -= (cap - tmp);
                break;
            }
            else {
                tmp += pickups[farPickup];
                do {
                    farPickup--;
                } while (farPickup >= 0 && pickups[farPickup] == 0);
            }
        }
        if (farDeliver < 0 && farPickup < 0) break;
    }

    return answer * 2;
}