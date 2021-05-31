//
//  main.cpp
//  洛谷P2240 【深基12.例1】部分背包问题
//
//  Created by 陈梓玮 on 2021/3/30.
//

#include <iostream>
using namespace std;
#include <vector>
#include <iomanip>
#include <algorithm>


struct Gold
{
    Gold(int x, int y):weight(x), value(y){}
    int weight = 0;
    int value = 0;
    double nice = ((double)value)/weight;
};
bool comp(const Gold& obj1, const Gold& obj2)
{
    return obj1.nice < obj2.nice ? 0 : 1;
}
double solution(vector<Gold> x, bool(*comp)(const Gold&, const Gold&), const int& n, int Packge_cap)
{
    sort(x.begin(), x.end(), comp);
//    for (int i = 0; i < x.size(); ++i) {
//        cout<<x[i].nice<<'\t';
//    }
    int cnt = 0;
    double total_val = 0;
    while (x[cnt].weight < Packge_cap && cnt <= n) {
        Packge_cap-=x[cnt].weight;
        total_val+=x[cnt].value;
        cnt++;
    }
    if(Packge_cap != 0)//还差一点没满
    {
        if (x[cnt].weight < Packge_cap) {
            total_val += x[cnt].value;
        }
        else
            total_val += x[cnt].nice*Packge_cap;
    }
    return total_val;
    
}


int main(int argc, const char * argv[]) {

    int n,Packge_Cap;    cin>>n>>Packge_Cap;
    int cnt = 0;
    vector<Gold> x;
//    x.push_back(Gold(8,60));
//    x.push_back(Gold(20,100));
//    x.push_back(Gold(10,40));
//    x.push_back(Gold(10,10));
    
    while (cnt < n) {
        int weight,val;
        cin>>weight>>val;
        x.push_back(Gold(weight,val));
        cnt++;
    }
    cout<<fixed<<setprecision(2)<<solution(x, comp, n, Packge_Cap);
    return 0;
}
