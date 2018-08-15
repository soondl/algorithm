///////////////////////////////////////////////////
// * date : 2018/08/13                           //
// * URL : https://www.acmicpc.net/problem/14502 //
///////////////////////////////////////////////////

#include <iostream> 
#include <algorithm>
#include <queue>
#pragma warning(disable: 4996)
using namespace std;

int n, m;
int arr[9][9];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int result = 0;

// 바이러스 퍼트리기 (bfs)
void spread_dfs() {
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 2) q.push(make_pair(i, j));
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (arr[nx][ny] == 0) {
					arr[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

// 벽 선택하기
void select_dfs(int x, int y, int cnt) {
	if (cnt == 3) { // 3가지 선택 함
		int temp_arr[9][9];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp_arr[i][j] = arr[i][j]; // 배열 복사
			}
		}

		spread_dfs(); // 바이러스 퍼뜨림

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0) cnt++; // 안전구역 개수 세기
			}
		}

		result = max(result, cnt); // cnt의 최대값을 얻어 냄

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = temp_arr[i][j]; // 배열 되돌림
			}
		}
		return;
	}

	for (int i = y + 1; i < m; i++) {
		if (arr[x][i] == 0) {
			arr[x][i] = 1;
			select_dfs(x, i, cnt + 1); // 선택을 했다.
			arr[x][i] = 0;
		}
	}
	for (int i = x + 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				select_dfs(i, j, cnt + 1); // 선택을 했다.
				arr[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;

	// arr 입력받음
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	// 벽 첫번 째 선택
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				select_dfs(i, j, 1);
				arr[i][j] = 0;
			}
		}
	}

	cout << result << "\n";
	return 0;
}


