//
//  temp.cpp
//  C++
//
//  Created by 전효재 on 2020/06/08.
//  Copyright © 2020 전효재. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const ll mod=9999991;
ll nCm[22][22];
int n,root,depth[22],d[22],childSize[22];
struct node{
    int l,r;
    node(){}
    node(int l,int r):
        l(l),r(r){}
};
vector<node> v;
void go2(int &root,int now) {
    if ( root == 0 ) {
        root = now;
        childSize[root] = 1;
        return ;
    }
    childSize[root]++;
    if ( root > now ) go2(v[root].l,now);
    else go2(v[root].r,now);
}
ll go(int now) {
    if ( now == 0 ) return 1ll;
    ll now1,now2;
    now1 = go(v[now].l);
    now2 = go(v[now].r);
    d[now] = (now1*now2*abs(nCm[childSize[now]-1][childSize[v[now].l]]))%mod;
    return d[now];
}
int main()
{
    memset(nCm,-1,sizeof(nCm));
    
    for ( int i = 1 ; i < 22 ; i++ )
        nCm[i][0]=nCm[i][i]=1;
    for ( int i = 2 ; i < 22 ; i++ )
        for ( int j = 1 ; j < i ; j++ )
            nCm[i][j] = nCm[i-1][j-1]+nCm[i-1][j];
    
    int tc;
    
    printf("수항할 횟수: ");
    scanf("%d",&tc);
    while ( tc-- ) {
        v.clear();
        printf("입력할 배열 크기: ");
        scanf("%d",&n);
        v.resize(n+1);
        for ( int i = 0 ; i <= n ; i++ )
            v[i].l = v[i].r =childSize[i]= 0;
        root =0;
        for ( int i = 0 ; i < n ; i++ ) {
            int t;

            scanf("%d",&t);
            go2(root,t);
        }
        printf("%lld\n",go(root));
    }
    return 0;
}
