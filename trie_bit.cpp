//143 最大异或对
#include<iostream>
using namespace std;
const int N=100010,M=3000000;
int num[M][2],idx;
int n;
int a[N];
void insert(int x){
    int p=0;
    for(int i=30;i>=0;i--){
        int bit=x>>i&1;
        if(!num[p][bit]){
            num[p][bit]=++idx;
        }
        p=num[p][bit];
    }
}
int search(int x){
    int res=0;
    int p=0;
    for(int i=30;i>=0;i--){
        int bit=x>>i&1;
        if(num[p][!bit]){
            res+=(1<<i);
            p=num[p][!bit];//应该让p沿着反方向走 因为是异或对
        }else{
            p=num[p][bit];//如果没有相反方向 就按这个方向走
        }
    }
    return res;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        insert(a[i]);
    }
    int res=0;
    for(int i=0;i<n;i++){
        res=max(res,search(a[i]));
    }
    cout<<res<<endl;
    return 0;
}

