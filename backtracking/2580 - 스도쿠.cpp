///////////////////////////////////////////////////
// * date : 2018/08/09                           //
// * URL : https://www.acmicpc.net/problem/9663  //
///////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

bool solveUTil(vector<pair<int,int>> &pos, int arr[][9], int index);

bool isSafe(int x, int y, int val, int arr[][9]) {
	int a = x / 3;
	int b = y / 3;

	if (x >= 3*a + 0 && x <= 3*a + 2 && y >= 3*b + 0 && y <= 3*b + 2) {
		for (int i = 0; i <= 2; i++)
			for (int j = 0; j <= 2; j++) {
				if (arr[3*a+i][3*b+j] == val) return false;
			}
	}

	for (int i = 0; i < 9; i++) {
		if (arr[x][i] == val && i != y) return false;
	}

	for (int i = 0; i < 9; i++) {
		if (arr[i][y] == val && i != x) return false;
	}

	return true;
}

bool solve() {
	int arr[9][9];
	vector<pair<int, int>> pos;

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			if (arr[i][j] == 0) pos.push_back(pair<int, int>(i, j)); // pos에는 아직 입력하지 않은 위치의 좌표가 들어감
		}

	if (solveUTil(pos, arr, 0) == false) return false;
	else {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		return true;
	}
}

bool solveUTil(vector<pair<int,int>>&pos, int arr[][9], int index) {
	if ((int)pos.size() == index) return true;
	
	int x = pos[index].first;
	int y = pos[index].second;

	for (int i = 1; i <= 9; i++) {
		if (isSafe(x, y, i, arr) == true) { // arr[x][y]에 i가 들어가는것이 safe?
			arr[x][y] = i;

			if (solveUTil(pos, arr, index + 1) == true)
				return true;
			else arr[x][y] = 0;
		}
	}
	return false;
}

int main(void) {
	solve();
	return 0;
}