#include <bits/stdc++.h>
using namespace std;

struct Item { int p, w; double r; };
struct Node { int lvl, p, w; double b; vector<int> t; };

double bound(Node u, int n, int W, vector<Item>& it) {
    if (u.w >= W) return 0;
    double res = u.p; int wt = u.w;
    for (int i = u.lvl; i < n; i++) {
        if (wt + it[i].w <= W) wt += it[i].w, res += it[i].p;
        else { res += (W - wt) * it[i].r; break; }
    }
    return res;
}

struct cmp { bool operator()(Node a, Node b){ return a.b < b.b; } };

int main() {
    int W = 9; vector<Item> it = {{20,2},{30,5},{35,7},{12,3},{3,1}};
    for (auto &x: it) x.r = (double)x.p / x.w;
    sort(it.begin(), it.end(), [](Item a, Item b){ return a.r > b.r; });

    priority_queue<Node, vector<Node>, cmp> pq;
    Node u={0,0,0,0,{}}, v; u.b = bound(u,it.size(),W,it);
    pq.push(u); int maxP=0, exp=0, prn=0; vector<int> best;

    while(!pq.empty()){
        u=pq.top(); pq.pop(); exp++;
        if(u.b<=maxP){ prn++; continue; }
        if(u.lvl==it.size()){ if(u.p>maxP){ maxP=u.p; best=u.t; } continue; }

        v=u; v.lvl++; v.w+=it[u.lvl].w; v.p+=it[u.lvl].p; v.t.push_back(1);
        if(v.w<=W){ v.b=bound(v,it.size(),W,it); pq.push(v); } else prn++;

        v=u; v.lvl++; v.t.push_back(0); v.b=bound(v,it.size(),W,it);
        if(v.b>maxP) pq.push(v); else prn++;
    }
    cout<<"Max Profit="<<maxP<<"\nItems: "; for(int x:best)cout<<x<<" ";
    cout<<"\nExpanded="<<exp<<" Pruned="<<prn<<"\n";
}
