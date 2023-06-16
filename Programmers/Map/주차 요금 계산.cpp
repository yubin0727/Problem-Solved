#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int baseTime = fees[0];
    int baseFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];
    int time, num, parkingTime;
    unordered_map<int, int> parking;
    unordered_map<int, int> out;
    string tmpTime, tmpNum, description;

    for (int i = 0; i < records.size(); i++) {
        stringstream ss(records[i]);
        ss.str(records[i]);
        ss >> tmpTime >> tmpNum >> description; // 시각, 차량번호, 내역으로 잘라 저장
        time = stoi(tmpTime.substr(0, 2)) * 60 + stoi(tmpTime.substr(3)); // 분으로 저장
        num = stoi(tmpNum); // 차 번호
        if (description == "IN") {  // 입차
            parking.insert({ num, time });
        }
        else {  // 출차
            parkingTime = time - parking.at(num); // 주차 시간
            parking.erase(num);
            if (out.find(num) != out.end()) {
                out[num] += parkingTime;
            }
            else {
                out.insert({ num, parkingTime });
            }
        }
    }
    for (auto& i : parking) {
        num = i.first;
        parkingTime = 1439 - i.second; // 주차 시간
        if (out.find(num) != out.end()) {
            out[num] += parkingTime;
        }
        else {
            out.insert({ num, parkingTime });
        }
    }
    vector<pair<int, int>> v;
    int totalFee, extra;
    for (auto& i : out) {
        num = i.first;
        parkingTime = i.second;
        totalFee = baseFee;
        extra = parkingTime - baseTime;
        if (extra > 0) {
            totalFee += (extra / unitTime) * unitFee;
            if (extra % unitTime != 0) { totalFee += unitFee; }
        }
        v.push_back({ num, totalFee });
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        answer.push_back(v[i].second);
    }

    return answer;
}