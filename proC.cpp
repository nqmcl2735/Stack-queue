//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo INT_MAX
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define maxn 100005
#define MOD
#define Pi 3.141592653589793238
#define cosdo(x) cos(x/180 * Pi)
#define sindo(x) sin(x/180 * Pi)
#define tando(x) tan(x/180 * Pi)
#define cotdo(x) 1/tando(x)
#define Task "proC"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, d;
pii a[maxn];
deque <int> dq;
bool ok[maxn];
int main() {
    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    fi >> n >> d;
    for (int i = 1; i <= n; i ++) fi >> a[i].F >> a[i].S;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++)
    {
        while(!dq.empty() && a[i].S >= a[dq.back()].S) dq.pop_back();
        dq.PB(i);
        while (a[dq.front()].F < a[i].F - d) dq.pop_front();
        if (a[dq.front()].S >= 2 * a[i].S) ok[i] = 1;
    }
    while (!dq.empty()) dq.pop_front();
    int res = 0;
    for (int i = n; i >= 1; i --)
    {
        while(!dq.empty() && a[i].S >= a[dq.back()].S) dq.pop_back();
        dq.PB(i);
        while (a[dq.front()].F > a[i].F + d) dq.pop_front();
        if (a[dq.front()].S >= 2 * a[i].S ) res += ok[i];
    }
    fo << res;
}
