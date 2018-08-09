///////////////////////////////////////////////////
// * date : 2018/08/09                            //
// * URL : https://www.acmicpc.net/problem/14501  //
///////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[17][2];
int result = 0;

void p(int idx, int profit) {
	if (idx > n + 1) return;

	result = max(result, profit);

	if (idx == n + 1) return;

	// 선택하지 않는 경우
	p(idx + 1, profit);
	
	// 선택하는 경우
	profit += arr[idx][1];
	p(idx + arr[idx][0], profit);
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0];
		cin >> arr[i][1];
	}

	p(1, 0);
	cout << result << "\n";
	return 0;
}