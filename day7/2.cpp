// https://adventofcode.com/2025/day/7#part2
// solved 12/7/25
// comments: YESSIR 

#include <bits/stdc++.h>
#include "../headers/all.hpp"

using namespace std;
using ll = long long;
//const ll MXN = 2e5 + 10;
using str = string;
using db = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;

#define endl "\n";
#define F first
#define S second
#define pb push_back
#define mp make_pair

#define Rep(i, x, y)   for (__typeof(x) i=x; i < y; i++)
#define Repi(i, x, y)  for (__typeof(x) i=x; i > y; i--)
#define vOut(v) Rep(i,0,v.size()){cout << v[i] << " ";} cout << endl;
#define Out(s)  cout << s << '\n';


void solve(){
   
    ll ret = 0;
    str next;
    ll startI = 0;
    map<ll,ll> above;
    while(getline(cin,next)){ 
      vll curr;
      Out(next);
      for (int i=0; i<next.size(); i++){
        if (next[i] == 'S'){
          startI = i;
          ++above[i];
        }
        if (next[i] == '^'){
          if (above.count(i) > 0){
            above[i-1] += above[i];
            above[i+1] += above[i];
            above.erase(i);
          }
        }
      }
    }
    for ( const auto &pair : above) {
        ret += pair.second;
    }
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    solve();
    return 0;
}



/*
 * tomorrow and
 *              tomorrow and
 *                            tomorrow
 *
 * creeps in this petty pace from day to day
 *      to the last syllable of recorded time
 *          and all our yesterdays have lighted fools the way to dusty death
 *
 *          out, out, brief candle!
 */
