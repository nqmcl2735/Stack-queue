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
#define maxn 1000005
#define MOD
#define Pi 3.141592653589793238
#define cosdo(x) cos(x/180 * Pi)
#define sindo(x) sin(x/180 * Pi)
#define tando(x) tan(x/180 * Pi)
#define cotdo(x) 1/tando(x)
#define Task "proB"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
pii res[maxn];
stack<int> st;
int a[maxn];
int n;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
    {
        while(!st.empty() && a[i] >= a[st.top()])
            st.pop();
        res[i].F = 0;
        if (!st.empty()) res[i].F = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for (int i = n; i >= 1; i --)
    {
        while(!st.empty() && a[i] > a[st.top()])
            st.pop();
        res[i].S = 0;
        if (!st.empty()) res[i].S = st.top();
        st.push(i);
    }
    a[0] = oo;
    ll sum = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (!res[i].F && !res[i].S) continue;
        sum += min(a[res[i].F], a[res[i].S]);
    }
    cout << sum;

}
