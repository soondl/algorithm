///////////////////////////////////////////////////
// * date : 2018/08/14                           //
// * URL : https://www.acmicpc.net/problem/10448 //
///////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[101];

bool dfs(int start, int cnt, int sum) {
	if (sum == n && cnt == 3) {
		return true;
	}

	if (cnt >= 3) return false;

	for (int i = start; i <= 100; i++) {
		if (arr[i] > n) break;

		if (sum + arr[i] <= n) {
			if (dfs(i, cnt + 1, sum + arr[i])) return true;
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= 100; i++) {
		arr[i] = i * (i + 1) / 2;
	}

	for (int i = 0; i < t; i++){
		cin >> n;
		int flag = 0;

		for (int i = 1; i <= 100; i++) {
			if (dfs(i, 1, arr[i])) {
				flag = 1;
			}
		}
		if (flag == 1) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}



