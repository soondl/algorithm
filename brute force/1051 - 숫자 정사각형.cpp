///////////////////////////////////////////////////
// * date : 2018/08/10                           //
// * URL : https://www.acmicpc.net/problem/1051  //
///////////////////////////////////////////////////

#include <iostream> 
#include <algorithm> 
using namespace std;

int answer = 1;
int n, m;
int arr[51][51];

void check(int x, int y, int jump) {
	int nx = x + jump;
	int ny = y + jump;

	// 정사각형이 범위를 벗어나는 경우
	if (!(x >= 0 && nx < n && y >= 0 && ny < m))
		return;

	// 정사각형이 조건을 만족하는 경우
	if (arr[x][y] == arr[nx][y] && arr[x][y] == arr[x][ny] && arr[x][y] == arr[nx][ny]) {
		answer = max(answer,(jump + 1) * (jump + 1)); // 답들 중 최대값을 얻어 냄
	}

	check(x, y, jump + 1); // 한사이즈 큰 정사각형에 대해 검사
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check(i, j, 1);
		}
	}

	cout << answer << "\n";
	return 0;
}