///////////////////////////////////////////////////
// * date : 2018/08/09                           //
// * URL : https://www.acmicpc.net/problem/1504  //
///////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <functional>
#include <queue>
#pragma warning(disable : 4996)
using namespace std;
#define INT_MAX 999999
vector<pair<int, int>> vt[802];
bool visited[802];
long long dist[802];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

int main() {
	int n, e;
	int v1, v2;
	long long int one_to_v1, one_to_v2;
	long long int v1_to_v2, v1_to_n; 
	long long int v2_to_v1, v2_to_n;
	cin >> n >> e;

	// 그래프를 만드는 과정
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vt[a].push_back(make_pair(b, c));
		vt[b].push_back(make_pair(a, c));
	}

	// 거치는 vertex
	cin >> v1 >> v2;

	for (int i = 0; i < 3; i++) {
		// dist, visited 초기화
		fill(dist, dist + n + 1, INT_MAX);
		fill(visited, visited + n + 1, false);

		if (i == 0) {
			dist[1] = 0;
			visited[1] = true;
		}
		else if (i == 1) {
			dist[v1] = 0;
			visited[v1] = true;
		}
		else if (i == 2) {
			dist[v2] = 0;
			visited[v2] = true;
		}

		while (!pq.empty())pq.pop();
		for (int i = 1; i <= n; i++) pq.push(make_pair(dist[i], i));

		while (!pq.empty()) {
			int vertex = pq.top().second;
			int distance = pq.top().first;
			visited[vertex] = true;
			pq.pop();

			// next.first -> next vertex
			// next.second -> distance
			for (auto next : vt[vertex]) {
				if (visited[next.first] == false && dist[next.first] > dist[vertex] + next.second) {
					dist[next.first] = dist[vertex] + next.second;
					pq.push(make_pair(dist[next.first], next.first));
				}
			}
		}

		if (i == 0) {
			one_to_v1 = dist[v1];
			one_to_v2 = dist[v2];
		}
		else if (i == 1) {
			v1_to_v2 = dist[v2];
			v1_to_n = dist[n];
		}
		else {
			v2_to_v1 = dist[v1];
			v2_to_n = dist[n];
		}
	}

	long long int result;
	result = min(one_to_v1 + v1_to_v2 + v2_to_n, one_to_v2 + v2_to_v1 + v1_to_n);
	
	if (result >= INT_MAX) {
		cout << -1 << "\n";
	}
	else cout << result << "\n";

	return 0;
}
