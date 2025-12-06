// https://adventofcode.com/2025/day/6
// solved 12/6/25
// comments: wow this was quite good

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
    vector<vll> v;
    
    
    
    while(getline(cin,next)){ 
 	    stringstream ss(next);
 	    if (next == "end"){break;}
 	    ll next;
    	vll vin; 

 	    while (ss >> next) {
	     vin.push_back(next);
 	    }
 	    v.pb(vin);
    }

    vector<char> vc;    
    while(getline(cin,next)){ 
 	    stringstream ss(next);
 	    while (ss >> next) {
 	      vc.pb(next[0]);
 	     }
 	   }


 	   for (ll i=0; i<vc.size(); i++){
 	     char sign = vc[i];
 	     ll total = (sign == '*') ? 1 : 0;
 	     for (ll j=0; j<v.size(); j++){
 	       if (sign == '*'){
 	         total *= v[j][i];
 	       } else if (sign == '+'){
 	         total += v[j][i];
 	       } else {
 	         Out("sign parse error")
 	       }
 	     }
 	     ret += total;
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
