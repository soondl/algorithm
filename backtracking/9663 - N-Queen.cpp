///////////////////////////////////////////////////
// * date : 2018/08/09                           //
// * URL : https://www.acmicpc.net/problem/9663  //
///////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
using namespace std;

bool board[16][16];
int n;
int total;

bool isSafe(int row, int col) { // 해당 퀸을 둘 수 있는지 확인
	for (int i = 0; i < row; i++) 
		if (board[i][col] == true) return false;

	for (int i = 1; row - i >= 0 && col + i < n; i++)
		if (board[row - i][col + i] == true) return false;

	for (int i = 1; row - i >= 0 && col - i >= 0; i++)
		if (board[row - i][col - i] == true) return false;

	return true;
}

void dfs(int row, int col) {
	if (row+1 == n) {
		total++;
		return;
	}

	board[row][col] = 1;

	for (int i = 0; i < n; i++) {
		if (isSafe(row+1, i)) // 다음 퀸을 둘 수 있다면 한 단계 깊게 들어 감
			dfs(row+1, i);
	}

	// 현재 위치에 퀸을 두었을 경우에 대한 볼 일은 다 봤으므로 원래대로 되돌림
	board[row][col] = 0;
	return; 
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		fill(board[i], board[i] + n, false);
	}

	for (int i = 0; i < n; i++) dfs(0, i);
	
	cout << total << "\n";
	return 0;
}
