///////////////////////////////////////////////////
// * date : 2018/08/09                           //
// * URL : https://www.acmicpc.net/problem/14888 //
///////////////////////////////////////////////////

#include <iostream> 
#include <algorithm> 
using namespace std;

int n;
int arr[13];
int ops[4];
int max_ans = -1000000000;
int min_ans = 1000000000;

// 모든 경우의 수를 탐색
// 연산 값은 sum에 축적 됨
void dfs(int idx, int sum) {
	// 배열 범위를 벗어남 == n-1개의 연산자를 다 쓴 상황
	if (idx == n) {		
		max_ans = max(max_ans, sum); // 모든 가능한 값 중 최대 값
		min_ans = min(min_ans, sum); // 모든 가능한 값 중 최소 값
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (ops[i] > 0) {
			ops[i]--;
			switch (i) {
				case 0:
					dfs(idx + 1, sum + arr[idx]);
					break;
				case 1:
					dfs(idx + 1, sum - arr[idx]);
					break;
				case 2:
					dfs(idx + 1, sum * arr[idx]);
					break;
				case 3:
					dfs(idx + 1, sum / arr[idx]);
			}
			ops[i]++; 
			// 다른 연산에 영향을 주지 않기 위해
			// ops를 원래대로 되돌림
		}
	}
	return;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	for (int i = 0; i < 4; i++) 
		cin >> ops[i];

	dfs(1, arr[0]);
	cout << max_ans << "\n";
	cout << min_ans << "\n";
	return 0;
}



	


