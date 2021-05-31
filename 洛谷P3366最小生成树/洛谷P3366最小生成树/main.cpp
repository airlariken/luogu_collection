//
//  main.cpp
//  洛谷P3366最小生成树
//
//  Created by 陈梓玮 on 2021/4/16.
//

#include <iostream>
using namespace std;


struct Edge{
    int cost = -1;
    int src = -1;
    int des = -1;
    Edge* link = nullptr;
    Edge(int c, int s, int d):cost(c), src(s), des(d){}
};
struct Vertex{
    int num = -1;
    Edge *next = nullptr;
};

Vertex* node_table[100001];

void insertEdge(int source, int dest, int dist)
{
    //出现重复插入边的问题。。。根据矩阵对称性只插入一条边。
    //头插法
    Edge *temp1 = node_table[source]->next->link;
    Edge *temp2 = node_table[dest]->next->link;
    node_table[source]->next->link = new Edge(source, dest, dist);
    node_table[dest]->next->link = new Edge(dest, source, dist);
    node_table[source]->next->link->link = temp1;
    node_table[dest]->next->link->link = temp2;
}


void Prim();
int main(int argc, const char * argv[]) {


    int N,M;    cin>>N>>M;
    for (int i = 0; i < M; ++i) {
        int e1, e2, cost;
        
    }
    return 0;
}
