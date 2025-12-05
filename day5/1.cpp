// https://adventofcode.com/2025/day/5
// solved 12/5/25
// comments: actually really good time on this shame part 2 bombed

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

    	vector<str> key; 
    	vector<str> v; 
    	str temp;
 	    bool flagKey = 0;
    while(getline(cin,next)){ 
 	    stringstream ss(next);
 	    str next;
 	    while (ss >> next) {

 	      if(next.find("-") == str::npos){
 	        flagKey = 1;
 	      }
 	      if (!flagKey){
 	        key.push_back(next);
 	       } else {
 	         v.push_back(next);
 	       }
 	    }
    } 	    


 	    Out("read");
 	    Out("");
 	    vOut(key);
 	    Out("");
 	    vOut(v);
 	    Out("");

 	    for (int i=0; i<v.size(); i++){
 	      for (int j=0;j<key.size(); j++){
 	        ll dashLoc = key[j].find("-");
 	        ll b1 = stoll(key[j].substr(0,dashLoc));
 	        ll b2 = stoll(key[j].substr(dashLoc+1, key[j].size()-dashLoc));
 	        ll val = stoll(v[i]);
 	        //Out(b1);
 	        //Out(b2);
 	        if (val <= b2 && val >= b1){
 	          ret++;
 	          Out(val);
 	          break;
 	        }
 	     
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
