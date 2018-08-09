///////////////////////////////////////////////////
// * date : 2018/08/09                           //
// * URL : https://www.acmicpc.net/problem/2293  //
///////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	int arr[100];
	int dp[10001];
	int ele;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	fill(dp, dp + k + 1, 0);
	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		ele = arr[i];

		for (int j = ele; j <= k; j++) {
			dp[j] += dp[j - ele];
		}
	}

	cout << dp[k] << "\n";
	return 0;
}