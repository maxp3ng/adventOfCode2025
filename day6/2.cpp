// https://adventofcode.com/2025/day/6
// solved 12/6/25
// comments: yay good enough time i can feel myself improving

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
    vector<str> v;
       
    
    while(getline(cin,next)){ 
 	      v.pb(next);
 	      Out(next.size());
    }

     ll lastRow = v.size()-1;
     char sign = 'X';
     ll signTot = 0;
 	   for (ll i=0; i<v[lastRow].size(); i++){
 	     char in = v[lastRow][i];
       str running = "";
 	     if (in != ' ') {
 	       ret += signTot;
 	       sign = in;
 	       signTot = (sign == '*') ? 1 : 0;
 	     }

       for (int j=0; j<v.size()-1; j++){
         if (v[j][i] != ' ') {
           running += string(1,v[j][i]);
         }
       }
       if (!running.empty()){ 
         if (sign == '+'){
           signTot += stoi(running);
         } else if (sign == '*'){
           signTot *= stoi(running);
         }
         }
 	   }
 	   ret += signTot;

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
