//
//  main.cpp
//  洛谷P1908 逆序对
//
//  Created by 陈梓玮 on 2021/3/30.
//https://www.luogu.com.cn/problem/P1908
//暴力解决方法：冒泡排序交换的次数就是逆序对的个数
//参考题解做法
#include <iostream>
#include <cstring>
using namespace std;

long long int my_mergeSort(int *arr, const int& left_start,const int& right_end)
{
    static int *temp = new int[right_end-left_start];
    static long long int cnt = 0;
    if (right_end<=left_start)
        return -1;
    
    int mid = (left_start+right_end)/2;
    //divide
    my_mergeSort(arr, left_start, mid);
    my_mergeSort(arr, mid+1, right_end);
    
    //merge two array
    int t_pos = 0;
    int l_cur = left_start, r_cur = mid+1;
    while (l_cur <= mid && r_cur <= right_end) {
        if (arr[l_cur]>arr[r_cur]) {
//            cnt+=right_end - r_cur;
            cnt+=mid-l_cur+1;
            temp[t_pos++] = arr[r_cur++];
        }
        else{
            temp[t_pos++] = arr[l_cur++];
        }
    }
    while (l_cur <= mid)
        temp[t_pos++] = arr[l_cur++];
    while (r_cur <= right_end)
        temp[t_pos++] = arr[r_cur++];
    
    //test
//    for (int i = 0; i < t_pos; ++i)
//        cout<<temp[i]<<'\t';
//    cout<<endl;
    //copy
    memcpy(&arr[0]+left_start, temp, sizeof(int)*t_pos);
    
    return cnt;
    
    
}
int main(int argc, const char * argv[]) {
    //test
//    int arr[]{5,4,2,6,3,1};
    
//    cout<<my_mergeSort(arr, 0, 5)<<endl
//    for (int i = 0; i < 6; ++i)
//        cout<<arr[i]<<'\t';
    
    int n,cnt = 0;  cin>>n;
    int *arr = new int[n];
    while (cnt<n)
        cin>>arr[cnt++];
    

    long long int ans = my_mergeSort(arr, 0, n-1);
//    for (int i = 0; i < n; ++i)
//        cout<<arr[i]<<'\t';
    cout<<ans;
    return 0;
}
