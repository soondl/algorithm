///////////////////////////////////////////////////
// * date : 2018/08/09                           //
// * URL : https://www.acmicpc.net/problem/10844 //
///////////////////////////////////////////////////

#include<iostream>
using namespace std;
#define VAL 1000000000;

int main(){
	int N;
	cin >> N;
	unsigned long long dp[101][10];
	unsigned long long result = 0;

	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;

	for(int i=2; i<=N; i++) 
		for (int j = 0; j <= 9; j++) {
			if (j == 0) { 
                dp[i][j] = dp[i-1][j + 1] % VAL; 
            }
			else if (j == 9) { 
                dp[i][j] = dp[i-1][j - 1] % VAL;
             }
			else { dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % VAL; }
		}

	for (int i = 1; i <= 9; i++) {
		result = (result+dp[N][i]) % VAL;
	}
	
	cout << result << endl;
}