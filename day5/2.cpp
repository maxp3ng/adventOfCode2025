// https://adventofcode.com/2025/day/5
// unsolved 
// comments: calling it quits for today ik what the solution is but it's kinda late to rewrite :(
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

vector<pll> genArray(){
  
    ll ret = 0;
    str next;

    	vector<pair<ll,ll>> v;
    	bool firstFlag = false;
    while(getline(cin,next)){ 
 	    stringstream ss(next);
 	    str next;
      if (ss >> next){
 	        ll dashLoc = next.find("-");
 	        ll b1 = stoll(next.substr(0,dashLoc));
 	        ll b2 = stoll(next.substr(dashLoc+1, next.size()-dashLoc));
 	        pair<ll,ll> in = mp(b1,b2);

          if (!firstFlag) {
            v.pb(in);
            firstFlag = true;
          }
          bool merged = false;

          for (int i=0; i<v.size(); i++){
                auto &key = v[i];

            if (!(in.S < key.F || key.S < in.F)) {
                key.F = min(key.F, in.F);
                key.S = max(key.S, in.S);
                merged = true;
                break;
            }
        }
 	       if (!merged) {
            v.pb(in);
          }
        }
 	     
    } 	    

          for (int i=0; i<v.size(); i++){
            ret += v[i].S-v[i].F+1;
            }




    cout << ret;
    return v;
}

ll solve(vector<pll>& vOld, bool print){
    ll ret = 0;
    str next;

    	vector<pair<ll,ll>> v;
    	bool firstFlag = false;
      for (int j=0; j<vOld.size(); j++){
          //Out(v.size());
          pll in = vOld[j];  
      
          if (!firstFlag) {
            v.pb(in);
            firstFlag = true;
          }
          bool merged = false;
          for (int i=0; i<v.size(); i++){
                auto &key = v[i];

            if (!(in.S < key.F || key.S < in.F)) {
                key.F = min(key.F, in.F);
                key.S = max(key.S, in.S);
                merged = true;
                break;
            }
        }
 	       if (!merged) {
            v.pb(in);
          }
        }
 	     
     	    

 	    Out("read2");
          for (int i=0; i<v.size(); i++){
            if (v[i].F == v[i].S){continue;}
            Out(v[i].F);
            Out(v[i].S);
            Out("");
            ret += v[i].S-v[i].F+1;
            }




    if (print) {
      Out(" ");
      Out(" ");
      Out(" ");
      Out(ret);}
    vOld = v;
    return v.size();
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    vector<pll> v = genArray();
    solve(v, false);
    ll last = -1;
    while (solve(v, false) != last) {
      last = solve(v, false);
    }
    solve(v, true);
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
