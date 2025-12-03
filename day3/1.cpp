// https://adventofcode.com/2025/day/3
// solved 12/3
// comments: lol

#include <bits/stdc++.h>
#include <string>
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
    while(getline(cin,next)){ 
 	    stringstream ss(next);
 	    str s;

 	    while (ss >> s) {
 	     int retadd = 0;
 	     for (int n=1; n<=9; ++n){
          for (int i=0; i<s.size()-1; i++){
   	        str chr;
   	        chr.pb(s[i]);
            if (stoi(chr) == n){
              for (int j=i+1; j<s.size(); j++){
                str chr2;
                chr2.pb(s[j]);
                retadd = max(retadd,stoi(chr + chr2));
              }
            }
          }
 	     }
      ret += retadd;
    }

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
