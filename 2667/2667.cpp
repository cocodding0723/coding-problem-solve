#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char arr[26][26];
vector<pair<int, int>> graph[26][26];
vector<int> apartment_complexes;
bool visit[26][26];

int total = 0;

void dfs(int startX, int startY, int& count){
    if (!visit[startX][startY]){
        visit[startX][startY] = true;
        count++;
        for (int i = 0; i < graph[startX][startY].size(); i++){
            dfs(graph[startX][startY][i].first, graph[startX][startY][i].second, count);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (arr[i][j] == '1'){
                if (i + 1 < N && arr[i + 1][j] == '1') 
                    graph[i][j].push_back(make_pair(i + 1, j));
                if (i - 1 >= 0 && arr[i - 1][j] == '1') 
                    graph[i][j].push_back(make_pair(i - 1, j));
                if (j + 1 < N && arr[i][j + 1] == '1') 
                    graph[i][j].push_back(make_pair(i, j + 1));
                if (j - 1 >= 0 && arr[i][j - 1] == '1') 
                    graph[i][j].push_back(make_pair(i, j - 1));
            }
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (!visit[i][j] && arr[i][j] == '1'){
                int count = 0;
                dfs(i, j, count);
                total++;
                apartment_complexes.push_back(count);
            }
        }
    }

    sort(apartment_complexes.begin(), apartment_complexes.end());

    cout << total << endl;

    for (int i = 0; i < apartment_complexes.size(); i++){
        cout << apartment_complexes.at(i) << endl;
    }

    return 0;
}