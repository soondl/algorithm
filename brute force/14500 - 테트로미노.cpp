#include <iostream> 
#include <algorithm> 
using namespace std;

int arr[501][501];
int visited[501][501];
int n, m;

// 방문 순서는 왼쪽부터 시계방향
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

// shape1, 2, 3, 4로 부터의 최대값을 얻어 냄
int dfs(int x, int y, int cnt) {
	if (cnt >= 5)
		return 0;

	visited[x][y] = true;

	int ans = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!(nx >= 0 && nx < n && ny >= 0 && ny < m))
			continue;

		if (visited[nx][ny] == false) 
			ans = max(ans, dfs(nx, ny, cnt + 1) + arr[x][y]);
	}

	// 길이 4를 완성시키는 경우 여기에 내려옴 visited 되돌림.
	// 원하는 answer 값을 얻어내고 난 후에는 visited값을 되돌린다.
	visited[x][y] = false;
	return ans;
}

// shape 5의 최대값
int get_finger_shape(int i, int j) {
	int sum[4] = { 0, };
	int max_sum = 0;

	if (!(i + 1 < n && j + 1 < m && j - 1 >= 0)) sum[0] = 0;
	else sum[0] = arr[i][j] + arr[i][j - 1] + arr[i][j + 1] + arr[i + 1][j];

	if (!(i - 1 >= 0 && j + 1 < m && j - 1 >= 0)) sum[1] = 0;
	else sum[1] = arr[i][j] + arr[i][j -1] + arr[i][j + 1] + arr[i - 1][j];

	if (!(i - 1 >= 0 && i + 1 < n && j + 1 < m)) sum[2] = 0;
	else sum[2] = arr[i][j] + arr[i - 1][j] + arr[i + 1][j] + arr[i][j + 1];

	if (!(i - 1 >= 0 && i + 1 < n && j - 1 >= 0)) sum[3] = 0;
	else sum[3] = arr[i][j] + arr[i][j - 1] + arr[i - 1][j] + arr[i + 1][j];

	for (int i = 0; i < 4; i++) max_sum = max(max_sum, sum[i]);
	return max_sum;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	// visited 값 false로 초기화
	for (int i = 0; i < n; i++)
		fill(visited[i], visited[i] + m, false);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = max(ans, dfs(i, j, 1));
			ans = max(ans, get_finger_shape(i, j));
		}
	}

	cout << ans << "\n";
	return 0;
}