#include <bits/stdc++.h>

using namespace std;

const int inf = 1<<29;
const int maxn = 100;

int main(){

    int edge[maxn][maxn] = {};
    int distance[maxn][maxn] = {};

    edge[0][1] = 10;
    edge[1][2] = 25;
    edge[2][3] = 1;
    edge[0][2] = 200;

    for(int i = 0;i < maxn;i++){
        for(int j = 0;j < maxn;j++){
            if (i == j) distance[i][j] = 0;
            else if (edge[i][j]) distance[i][j] = edge[i][j];
            else distance[i][j] = inf;
        }
    }

    for(int k = 0;k < maxn;k++){
        for(int i = 0;i < maxn;i++){
            for(int j = 0;j < maxn;j++){
                distance[i][j] = min(distance[i][j], distance[i][k]+distance[k][j]);
            }
        }
    }

    cout << "The minimum distance from 0 to 2 is " << distance[0][2] << endl;

    return 0;
}
