// 1-mashq
#include <bits/stdc++.h>
using namespace std;

vector<int> p(5);

int find(int x){
    return p[x]==x?x:p[x]=find(p[x]);
}

void unite(int a,int b){
    p[find(a)] = find(b);
}

int main() {
    for(int i=0;i<5;i++) p[i]=i;
    unite(0,1);
    unite(1,2);

    cout<<find(2);
}
// 2-mashq
#include <bits/stdc++.h>
using namespace std;

int p[10];

int find(int x){
    return p[x]==x?x:p[x]=find(p[x]);
}

int main() {
    vector<tuple<int,int,int>> e={{1,2,1},{2,3,2},{1,3,3}};
    sort(e.begin(), e.end());

    for(int i=0;i<10;i++) p[i]=i;

    int res=0;
    for(auto [u,v,w]:e){
        if(find(u)!=find(v)){
            p[find(u)] = find(v);
            res += w;
        }
    }
    cout<<res;
}
