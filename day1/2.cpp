// https://adventofcode.com/2025/day/1
// solved 12/1/25
// comments: i'm really really really really rusty

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
   
    ll ret = 50;
    ll n = 0;
    str nxt;
    while(getline(cin,nxt)){ 
 	    stringstream ss(nxt);
 	    str next;
 	    while (ss >> next) {
 	      if (next[0] == 'R'){
 	       n += (ret+stoi(next.substr(1, next.size()-1)))/100;
 	       ret = (ret+stoi(next.substr(1, next.size()-1))+100)%100;
 	       }
  	     else {
 	       if (ret != 0) {n += (100-ret+stoi(next.substr(1, next.size()-1)))/100;}
 	       else {n += ret+stoi(next.substr(1, next.size()-1))/100;}
  	      ret = (ret-stoi(next.substr(1, next.size()-1))%100+100)%100;
  	     }
 	    }
    }
    cout << n;
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
