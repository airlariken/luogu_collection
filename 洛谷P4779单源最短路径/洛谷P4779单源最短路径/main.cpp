//
//  main.cpp
//  洛谷P4779单源最短路径
//
//  Created by 陈梓玮 on 2021/4/16.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <string>
#include <fstream>
#include <cstring>
#include <climits>
using namespace std;

//mlx！！！！！应该用邻接表……………………稀疏矩阵
struct vertex_cost{
    int num = -1;   //到达该顶点的顶点下标
    int src = -1;
    int cost = -1;  //到达该顶点的距离
    vertex_cost(int n, int s, int c):num(n),src(s),cost(c){}
};

struct pri_q_comp{
    bool operator()(vertex_cost& obj1, vertex_cost& obj2)
    {
        return obj1.cost < obj2.cost;
    }
};

void Dijkstra(int** matrix, int start_pos, int num)
{
    bool* visited = new bool[num];
    memset(visited, 0, sizeof(bool)*num);
    priority_queue<vertex_cost, vector<vertex_cost>, pri_q_comp> q;
    
    
    
    int *dis = new int[num];
    for (int i = 0; i < num; ++i)
        dis[i] = INT_MAX;
//    int *pre = new int[num];
    dis[start_pos] = 0;
    
    
    int cur = start_pos;
    for (int i = 0; i < num-1; ++i) {
        visited[cur] = true;
        for (int j = 0; j < num; ++j) {
            if (matrix[cur][j] == -1)
                continue;
            
            if (matrix[cur][j]+dis[cur] < dis[j]) {
                dis[j] = matrix[cur][j]+dis[cur];
                q.push(vertex_cost(j, cur, dis[j]));
            }
            while (visited[cur] != false) {
                cur = q.top().num;
            }
//            pre[cur] = q.top().src;
            q.pop();
        }
    }
    
    for (int i = 0; i < num; ++i) {
        cout<<dis[i]<<' ';
    }
}

int main()
{
    
    
    int n, m,start_pos;
    cin>>n>>m>>start_pos;
    int **dis_matrix = new int*[n];         //dis_matirx[1][2]表示从1到2有一条有向边
    for (int i = 0; i < n; ++i)
        dis_matrix[i] = new int[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n ; ++j) {
            dis_matrix[i][j] = -1;
        }
    }
    
    for (int i = 0; i < m; ++i) {   //m条边
        int e1,e2,dis;
        cin>>e1>>e2>>dis;
        dis_matrix[e1-1][e2-1] = dis;
    }
    
    Dijkstra(dis_matrix, start_pos-1, n);
    
}

