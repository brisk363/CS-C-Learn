//835 Trie字符串统计
#include<iostream>
using namespace std;
const int N=100010;
int num[N][26],cnt[N],idx;
int n;
void insert(string str){//创建Trie树
    int p=0;
    for(int i=0;str[i];i++){
        int s=str[i]-'a';
        if(!num[p][s]){
            num[p][s]=++idx;
        }
        p=num[p][s];
    }
    cnt[p]++;
}
int query(string str){//查询
    int p=0;
    for(int i=0;str[i];i++){
        int s=str[i]-'a';
        if(!num[p][s]){
            return 0;
        }else{
            p=num[p][s];//若涉及到前缀问题，应该在这之后加一个pass[p]++
        }
    }
    return cnt[p];//记录在这个节点上结束的字符串有几个
}
int main(){
    cin>>n;
    while(n--){
        char request;
        cin>>request;
        getchar();
        if(request=='I'){
            string str;
            cin>>str;
            insert(str);
        }else{
            string str;
            cin>>str;
            cout<<query(str)<<endl;
        }
    }
    return 0;
}