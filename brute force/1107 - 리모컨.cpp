///////////////////////////////////////////////////
// * date : 2018/08/09                           //
// * URL : https://www.acmicpc.net/problem/1107  //
///////////////////////////////////////////////////

#include <iostream> 
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int num, m;
	bool button[10];
	int flag = 0;
	int idx = 0;
	int result = 9999999;

	cin >> num >> m;
	fill(button, button + 10, false);

	// button이 false 인 것만 사용가능
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		button[a] = true;
	}

	int only_b = abs(num - 100);
	result = only_b;

	if (num == 100) {
		cout << "0" << "\n";
		return 0;
	}

    // 모든 경우의 수를 다 검사해 봄 (brute force)
	for (int i = 0; i<=888888; i++) {
		int temp = i;
		int flag = 0;
		int length;

        // i의 자리수를 length 에 저장
		if (i >= 100000) length = 6;
		else if (i >= 10000) length = 5;
		else if (i >= 1000) length = 4;
		else if (i >= 100) length = 3;
		else if (i >= 10) length = 2;
		else length = 1;

		if (i == 0) {
			if (button[i] == true) {
				flag = 1;
			}
		}

		// 해당 i 값이 
		// 입력 될 수 있는 값이면 flag == 0
		// 입력 될 수 없는 값이면 flag == 1
		while (temp > 0) {
			int temp2 = temp % 10;
			if (button[temp2] == true) {
				flag = 1;
				break;
			}
			temp /= 10;
		}

		if (flag == 0) 
			result = min(result, abs(num - i) + length);
            // 목표 값과 해당 값의 차이 + 해당 값 버튼 누르는 횟수
	}

	cout << result << "\n";
	return 0;
}