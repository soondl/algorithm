///////////////////////////////////////////////////
// * date : 2018/08/15                           //
// * URL : https://www.acmicpc.net/problem/14889 //
///////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int l;
int arr[22][22];
bool selected[22]; // visited 배열
int result = 9999999;

// 조합 선택
void select_team(int num, int cnt) {
	if (cnt == l/2) { // 선택 완료
		vector<int> a;
		vector<int> b;

		for (int i = 1; i <= l; i++) 
			(selected[i] == true) ? a.push_back(i) : b.push_back(i);
        // a팀 b인 구성원을 나눠서 저장

        // sum1 -> a팀의 stat
        // sum2 -> b팀의 stat
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < (int)a.size() - 1; i++) {
			for (int j = i+1; j < (int)a.size(); j++) {
				sum1 += (arr[a[i]][a[j]] + arr[a[j]][a[i]]);
				sum2 += (arr[b[i]][b[j]] + arr[b[j]][b[i]]);
			}
		}

		result = min(result, abs(sum1 - sum2));
		return;
	}

	for (int i = num + 1; i <= l; i++) {
		selected[i] = true;
		select_team(i, cnt + 1);
		selected[i] = false;
	}
}

int main() {
	cin >> l;

	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= l; j++) {
			cin >> arr[i][j];
		}
	}
		
	fill(selected, selected + 22, false);

	for (int i = 1; i <= l; i++) {
		selected[i] = true;
		select_team(i, 1);
		selected[i] = false;
	}

	cout << result << "\n";
	return 0;
}
