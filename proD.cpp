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
#define Task "proD"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, k;
int a[maxn];
ll suf[maxn];
deque <int> dq;
ll res = -oo;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> k;
    int l = k;
    int r = n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        suf[i] = a[i] + suf[i - 1];
    }
    for (int i = 0; i <= n - l; i ++)
    {
        while(!dq.empty() && suf[i] <= suf[dq.back()]) dq.pop_back();
        dq.PB(i);
        while (i - dq.front() > r - l) dq.pop_front();
        res = max(res, suf[i + l] - suf[dq.front()]);
    }
    cout << res;
}
