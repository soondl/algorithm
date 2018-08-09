///////////////////////////////////////////////////
// * date : 2018/08/09                           //
// * URL : https://www.acmicpc.net/problem/1463  //
///////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_INT 99999;

int main() {
	int n;
	cin >> n;
	
	int **dp = new int* [n+1];
	for (int i = 0; i < n+1; i++) {
		dp[i] = new int[3];
	}

	dp[1][0] = 0;
	dp[1][1] = 0;
	dp[1][2] = 0;

	int less = 0;
	for (int i = 2; i < n+1; i++) {
		if (i % 3 == 0) {
			less = min(dp[i / 3][0], dp[i / 3][1]);
			dp[i][0] = min(less, dp[i / 3][2]) + 1;
		}
		else dp[i][0] = MAX_INT;
		
		if (i % 2 == 0) {
			less = min(dp[i / 2][0], dp[i / 2][1]);
			dp[i][1] = min(less, dp[i / 2][2]) + 1;
		}
		else dp[i][1] = MAX_INT;

		less = min(dp[i-1][0], dp[i-1][1]);
		dp[i][2] = min(less, dp[i-1][2]) + 1;
	}

	less = min(dp[n][0], dp[n][1]);
	cout << min(less, dp[n][2]) << endl;
}