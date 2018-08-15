///////////////////////////////////////////////////
// * date : 2018/08/14                           //
// * URL : https://www.acmicpc.net/problem/1759  //
///////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int l, c;
char arr[16];
int vowel = 0;
int not_vowel = 0;
int cnt = 0;
bool alphabet[200];
string letter;

void backtracking(int idx, int vowel, int not_vowel, int cnt) {
	if (arr[idx] == 'a' || arr[idx] == 'e' || arr[idx] == 'i'
		|| arr[idx] == 'o' || arr[idx] == 'u') {
		vowel++;
	}
	else
		not_vowel++;

	if (cnt == l && vowel >= 1 && not_vowel >= 2) {
		cout << letter << "\n";
		return;
	}

	for (int i = idx + 1; i < c; i++) {
		letter.push_back(arr[i]);
		backtracking(i, vowel, not_vowel, cnt + 1);
		letter.pop_back();
	}
}

int main() {
	fill(alphabet, alphabet + 200, false);
	cin >> l >> c;

	for (int i = 0; i < c; i++) 
		cin >> arr[i];

	sort(arr, arr + c);

	for (int i = 0; i < c - 3; i++) {
		letter.push_back(arr[i]);
		backtracking(i, 0, 0, 1);
		letter.pop_back();
	}
	return 0;
}