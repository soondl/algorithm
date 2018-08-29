///////////////////////////////////////////////////
// * date : 2018/08/29                           //
// * URL : https://www.acmicpc.net/problem/7562  //
///////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2 ,1, -1, -2};

int main() {
    int t, l;
    int cnt;
    int flag;
    pair<int, int> start, fin;
    queue<pair<pair<int, int>, int>> q;
    bool visited[301][301];

    cin >> t;

    // t 횟수만큼 반복
    for(int i=0; i<t; i++){
        cin >> l;
        cin >> start.first >> start.second;
        cin >> fin.first >> fin.second;
        cnt = 0; flag = 0;

        while(!q.empty()) q.pop(); // q를 비워 줌

        for(int i=0; i<301; i++)
            fill(visited[i], visited[i]+301, false);
        // visited 를 false로 초기화

        q.push(make_pair(start, cnt));
        visited[start.first][start.second] = true;

        // 시작과 끝이 같은 경우 예외처리
        if(start.first == fin.first && start.second == fin.second){
            cout << 0 << "\n";
            continue;
        }

        //BFS 구현
        while(!q.empty()){
            int pos_x = q.front().first.first;
            int pos_y = q.front().first.second;
            int count = q.front().second;
            q.pop();

            for(int i=0; i<8; i++){
                int next_x = pos_x + dx[i];
                int next_y = pos_y + dy[i];

                if(next_x >= 0 && next_x < l && next_y >= 0 && next_y < l){
                    if(visited[next_x][next_y] == false){
                        q.push(make_pair(make_pair(next_x, next_y), count + 1));
                        visited[next_x][next_y] = true;

                        // 조건을 만족하는 경우
                        if(next_x ==  fin.first && next_y == fin.second){
                            cout << count + 1 << "\n";
                            flag = 1;
                            break;
                        }
                    }
                }

                if(flag == 1) break;
            }
            if(flag == 1) break; // 조건을 만족하는 경우 탈출
        }

    }
    return 0;
}
