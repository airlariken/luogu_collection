//
//  main.cpp
//  洛谷P3619 魔法
//
//  Created by 陈梓玮 on 2021/3/30.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct mission
{
    mission(int x, int y):ai(x),bi(y){}
    int ai = 0;
    int bi = 0;
};
bool comp1(const mission& obj1, const mission& obj2)//从小到大
{
    return obj1.ai < obj2.ai;
}
bool comp2(const mission& obj1, const mission& obj2)//从大到小排bi+ai
{
    return obj1.ai+obj1.bi > obj2.ai+obj2.bi;
}

bool solution(vector<mission>& v1, vector<mission>& v2, const int& time, const int& num)//num是任务个数
{
    sort(v1.begin(), v1.end(), comp1);//bi>=0的任务按照ai从小到大排序
    sort(v2.begin(), v2.end(), comp2);//bi<0的任务按照ai从大到小排序

    int remaining_time = time;
    for (int i = 0; i < v1.size(); ++i) {
        if (remaining_time > v1[i].ai) {
            remaining_time += v1[i].bi;
        }
        else
            return 0;
        
    }
    for (int i = 0; i < v2.size(); ++i) {
        if (remaining_time > v2[i].ai) {
            remaining_time += v2[i].bi;
        }
        else
            return 0;
    }
//    cout<<remaining_time<<endl;
    if (remaining_time>0) {
        return 1;
    }
    else
        return 0;

}
int main(int argc, const char * argv[]) {

    int n;  cin>>n;
    while (n--) {
        int cnt, time;    cin>>cnt>>time;
        int num = cnt;
        vector<mission>v1;//收集bi>=0的任务
        vector<mission>v2;//收集bi<0的任务
        while (cnt--) {

            int ai,bi;  cin>>ai>>bi;
            if (bi>=0) {
                v1.push_back(mission(ai,bi));
            }
            else
                v2.push_back(mission(ai,bi));
        }
        if(solution(v1, v2, time, num) == 1)
            cout<<"+1s"<<endl;
        else
            cout<<"-1s"<<endl;
    }
    

    return 0;
}
