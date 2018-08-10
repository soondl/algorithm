///////////////////////////////////////////////////
// * date : 2018/08/10                           //
// * URL : https://www.acmicpc.net/problem/6603  //
///////////////////////////////////////////////////

#include <iostream> 
#include <algorithm> 
using namespace std;

int k;
int s[51];
int ans[6];

void dfs(int start, int depth) {
	ans[depth] = s[start];

	if (depth == 5) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start + 1; i < k; i++) 
		dfs(i, depth + 1);
}

int main() {
	while (cin >> k && k){
		for (int i = 0; i < k; i++)
			cin >> s[i];

		for (int i = 0; i <= k - 6; i++) 
			dfs(i, 0);
	
		cout << "\n";
	}
}