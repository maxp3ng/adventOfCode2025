// https://adventofcode.com/2025/day/2
// solved 12/2/25
// comments: spent too long trying to avoid looping b-a for each pair just to completely spam anything in part 2

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

ll retadd(ll a, ll b){
  ll count = 0;
      //cout << a << endl;
      //cout << b << endl;

  for (ll i = a; i<=b; i++){
    str s = to_string(i);
    if (s.size()%2==1) {continue;}
    str a1 = s.substr(0,s.size()/2);
    str a2 = s.substr(s.size()/2,s.size()/2);
    //cout << a1 << endl;
    //cout << a2 << endl;
    if (a1 == a2){
      count += i;
      //cout << i << endl;
    }
  }

  //ll mod = 11;
  //if (a % mod == 0) {++count;}
  //count += (b-a)%mod;

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
