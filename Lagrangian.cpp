//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using grid = vector<vi>;
 
template<class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, 
                         tree_order_statistics_node_update>; 
#define en "\n"
#define ln " \n"[i==n-1]
#define F first
#define S second
#define pb push_back
#define all(_O) _O.begin(), _O.end() 
#define rall(_O) _O.rbegin(), _O.rend() 
#define badret return void(cout<<-1<<en)
#define boolret(_O) return void(cout<<(_O? "Yes":"No")<<en) 
#define fir(_O) for(int i=0, ii=(_O)-1; i<(_O); ++i, --ii)
#define fjr(_O) for(int j=0, jj=(_O)-1; j<(_O); ++j, --jj)



// 一心不乱
ll const N = 2e6+6;
ll const inf = 1e18; //0x3f3f3f3f3f3f;
ll const mod = 998244353;
struct mint{
  ll v; 
  mint(ll _v=0) {v = (_v%mod +mod)%mod;}

  friend mint operator+(const mint& a, const mint& b){ return mint(a.v + b.v); }
  friend mint operator-(const mint& a, const mint& b){ return mint(a.v - b.v); }
  friend mint operator*(const mint& a, const mint& b){ return mint(a.v * b.v); }
  friend mint operator/(const mint& a, const mint& b){ return a*minv(b); }
  friend mint mpow(const mint& b, ll p){
    mint a=b, r=1; for( ; p; p>>=1, a=a*a) if(p&1) r=r*a; return r;
  }
  friend mint minv(const mint& a){ return mpow(a, mod-2); }
  friend ostream& operator<<(ostream &os, mint m){ return os<<m.v; }
  friend istream& operator>>(istream &is, mint &m){ ll x; is>>x; m=mint(x); return is; }
};

vector<double> X = {0, 1, 2, 3, 4, 5};
vector<double> Y = {0, 2, 2.5, 3, 3.3, 3.8};

void _(){
  double target_x = 2.5;
  int k = 4;

  auto get_k_closest = [&](double x, int k) {
    int n = X.size();
    vector<pair<double, double>> pts;
    fir(n) pts.pb({X[i], Y[i]});

    sort(all(pts), [&](const pair<double, double>& a, const pair<double, double>& b){
      return abs(a.F - x) < abs(b.F - x);
    });

    vector<double> sel_X, sel_Y;
    fir(min(n, k)){
      sel_X.pb(pts[i].F);
      sel_Y.pb(pts[i].S);
    }
    return make_pair(sel_X, sel_Y);
  };

  auto [x_pts, y_pts] = get_k_closest(target_x, k);
  int m = x_pts.size();

  double ans = 0.0;
  fir(m) {
    double term = 1.0;
    
    fjr(m) if(i-j) {
      term *= (target_x-x_pts[j])/(x_pts[i]-x_pts[j]);
    }
    ans += y_pts[i]*term;
  }

  cout<<setprecision(10)<<fixed;
  cout<<"Interpolated value at x = "<<target_x<<" using "<<m<<" points is: "<<ans<<en;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int tt = 1; //cin>>tt;
  fir(tt) _();
}























