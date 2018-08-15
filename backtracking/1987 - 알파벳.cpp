///////////////////////////////////////////////////
// * date : 2018/08/13                           //
// * URL : https://www.acmicpc.net/problem/1987  //
///////////////////////////////////////////////////

#include <iostream> 
#include <algorithm>
using namespace std;

int r, c;
char arr[21][21];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int result = 0;
bool alphabet[200]; // 해당 alphabet이 방문 한 alphabet인지 체크하는 용도

void backtracking(int x, int y, int cnt) {
	if (cnt > result) result = cnt; // 최대 cnt를 얻음

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
			if (alphabet[(int)arr[nx][ny]] == false) {
				alphabet[(int)arr[nx][ny]] = true;
				backtracking(nx, ny, cnt + 1);
				alphabet[(int)arr[nx][ny]] = false;
			}
		}
	}
}

int main() {
	cin >> r >> c;
	fill(alphabet, alphabet + 200, false);
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}

	alphabet[(int)arr[0][0]] = true;
	backtracking(0, 0, 1);
	alphabet[(int)arr[0][0]] = false;

	cout << result << "\n";
	return 0;
}