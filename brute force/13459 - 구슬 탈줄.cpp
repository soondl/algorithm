///////////////////////////////////////////////////
// * date : 2018/08/16                           //
// * URL : https://www.acmicpc.net/problem/13459 //
///////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
char arr[12][12];
bool visited[12][12][12][12];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int cnt = 0;

class pos {
public:
	int rx, ry, bx, by;
	pos(int rx, int ry, int bx, int by) {
		this->rx = rx;
		this->ry = ry;
		this->bx = bx;
		this->by = by;
	}
};

int main() {
	queue<pos> q;
	cin >> n >> m;

	int a, b, c, d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				a = i; b = j;
			}
			if (arr[i][j] == 'B') {
				c = i; d = j;
			}
		}
	}

	q.push(pos(a, b, c, d));
	visited[a][b][c][d] = true;

	while (!q.empty()) {
		int size = q.size();

		while (size--) {
			int rx = q.front().rx;
			int ry = q.front().ry;
			int bx = q.front().bx;
			int by = q.front().by;
			q.pop();
			
			if (arr[rx][ry] == 'O') {
				cout << 1 << "\n";
				return 0;
			}

			for (int i = 0; i < 4; i++) {
				int nrx = rx;
				int nry = ry;
				int nbx = bx;
				int nby = by;
				int bf = 0;

				while (arr[nrx + dx[i]][nry + dy[i]] != '#' && arr[nrx][nry] != 'O') {
					nrx += dx[i];
					nry += dy[i];
				}

				while (arr[nbx + dx[i]][nby + dy[i]] != '#' && arr[nbx][nby] != 'O') {
					nbx += dx[i];
					nby += dy[i];
					if (arr[nbx][nby] == 'O') bf = 1;
				}

				if (nrx == nbx && nry == nby) {
					switch (i) {
					case 0: // 서
						if (ry < by) nby++;
						else nry++;
						break;

					case 1: // 동
						if (ry < by) nry--;
						else nby--;
						break;

					case 2: // 북
						if (rx < bx) nbx++;
						else nrx++;
						break;

					case 3: // 남
						if (rx < bx) nrx--;
						else nbx--;
					}
				}
				if (bf == 1) continue;
				if (visited[nrx][nry][nbx][nby]) continue;
				q.push(pos(nrx, nry, nbx, nby));
				visited[nrx][nry][nbx][nby] = true;
			}
		}
		cnt++;
		if (cnt > 10) {
			cout << 0 << "\n";
			return 0;
		}
	}
	cout << 0 << "\n";
	return 0;
}