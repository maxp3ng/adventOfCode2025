// https://adventofcode.com/2025/day/2
// solved 12/2/25
// comments: this might be some of THE worst code i've ever written but it works lololol
 
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

ll recur(str s,str run){
  int j = 0;
  if (s.size() % run.size() != 0) {return 0;}
  for (int i=0;i<s.size(); i++){
    if (j == run.size()) {j = 0;}
    if (s[i] != run[j]) {return 0;}
    j++;
  }
  return stoll(s);
}

ll retadd(ll a, ll b){
  ll count = 0;
  for (ll i = a; i<=b; i++){
    str s = to_string(i);
    char firstC = s[0];
    str run;
    ll last;
    run.pb(firstC);
    for (int j=1; j<s.size(); j++){
      if (s[j] == firstC) {
        ll re = recur(s, run);
        if (re != last) {
          count += re;
        }
        if (re != 0) {last = re;}
      }
      run.pb(s[j]);
    }
  }

  return count;
}

void solve(){
   
    ll ret = 0;
    str next;
    while(getline(cin,next)){ 
 	    stringstream ss(next);
 	    str input;
 	    ss >> input;

 	    bool firstHalf = true;
 	    str s1 = "";
 	    str s2 = "";
      for (int i=0; i<input.size(); i++){
        char c = input[i];
        if ( c == ','){
          ret += retadd(stoll(s1),stoll(s2));
          s1 = "";
          s2 = "";
          firstHalf = true;
        }
        else if (c == '-') {firstHalf = false;}
        else {
          if (firstHalf) {s1 += c;}
          else {s2 += c;}
        }
      }

      ret += retadd(stoll(s1),stoll(s2));
      s1 = "";
      s2 = "";
      firstHalf = true;
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
