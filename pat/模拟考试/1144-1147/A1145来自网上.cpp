#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 1e4+10; 
int res[maxn];
int msize, n, m, num;
double tot = 0;
bool isPrime(int x){
    if(x < 2) return false;
    for(int i = 2; i<=sqrt(x); i++)
        if(x % i == 0) return false;
    return true;
}
bool insert(int x){
    int idx = x%msize, cnt = 0;
    while(cnt < msize){
        int key = idx+cnt*cnt;
        key %= msize;
        if(res[key] == 0){
            res[key] = x;
            return true;
        }
        cnt++;
    }
    return false;
}
void search(int x){
    int idx = x%msize, cnt = 0;
    while(cnt < msize){
        int key = idx+cnt*cnt;
        key %= msize;
        tot++;
        if(res[key] == 0) return ;//???????????????????? 
        if(res[key] != x){
            cnt++;
        }
        else {
            return;
        }
    }
    tot++;
}
int main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> msize >> n >> m; 
    while(!isPrime(msize)){
        msize++;
    }
    for(int i = 0; i<n; i++){
        cin >> num;
        if(!insert(num))
            printf("%d cannot be inserted.\n", num);
    }
    for(int i = 0; i<m; i++){
        cin >> num;
        search(num);
        printf("tot: %d\n",(int)tot); 
    }
    printf("%.1f", tot/m);
    return 0;
}

/*
4 5 4
10 6 4 15 11
11 4 15 2
*/
