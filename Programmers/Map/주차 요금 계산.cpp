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
        ss >> tmpTime >> tmpNum >> description; // �ð�, ������ȣ, �������� �߶� ����
        time = stoi(tmpTime.substr(0, 2)) * 60 + stoi(tmpTime.substr(3)); // ������ ����
        num = stoi(tmpNum); // �� ��ȣ
        if (description == "IN") {  // ����
            parking.insert({ num, time });
        }
        else {  // ����
            parkingTime = time - parking.at(num); // ���� �ð�
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
        parkingTime = 1439 - i.second; // ���� �ð�
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