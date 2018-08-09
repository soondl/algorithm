///////////////////////////////////////////////////
// * date : 2018/08/09                           //
// * URL : https://www.acmicpc.net/problem/1753  //
///////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#define MAXVAL 9999999
using namespace std;

vector< pair<int, int> > vt[20001];
bool visited[20001];
int dist[20001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int V, E;
	int start_v;
	int u, v, w;
	int distance, vertex;

	cin >> V >> E;
	cin >> start_v;

	fill(visited, visited + V+1, false);
	fill(dist, dist + V + 1, MAXVAL);

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		vt[u].push_back(pair<int,int>(v, w));
	}

	visited[start_v] = true;
	dist[start_v] = 0;

	priority_queue < pair<int, int>, vector< pair<int, int> >, greater<pair<int,int>> > pq;

	pq.push(pair<int, int>(dist[start_v], start_v));

	while (!pq.empty()) {
		distance = pq.top().first;
		vertex = pq.top().second;
		pq.pop();
		visited[vertex] = true;
		for (auto itr = vt[vertex].begin(); itr != vt[vertex].end(); itr++) {
			if (visited[itr->first] == false) {
				if (dist[itr->first] > dist[vertex] + itr->second) {
					dist[itr->first] = min(dist[itr->first], dist[vertex] + itr->second);
					pq.push(pair<int, int>(dist[itr->first], itr->first));
				}
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (visited[i] == true) cout << dist[i] << "\n";
		else cout << "INF" << "\n";
	}
	
	return 0;
 } 