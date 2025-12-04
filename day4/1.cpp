// https://adventofcode.com/2025/day/4
// solved 12/4/25
// comments: yay had some technical difficulties need to LEARN what cpp actually is i'm just spamming

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
    	vector<string> v;
    while(getline(cin,next)){ 
 	    stringstream ss(next);
 	    str next = ss.str();

	     v.push_back("Z" + next + "Z");
 	    }
 	   str bufferline(v[0].size(), 'Z');
 	   Out("pass");
 	    v.insert(v.begin(), bufferline);  
 	    v.push_back(bufferline);

      vector<str> v2 = v;
 	    for (int i=1; i<v.size()-1; i++){
 	      for (int j=1; j<v[0].size()-1; j++){
 	        if (v[i][j] != '@') {continue;}
 	        int adjCount = (int)(v[i-1][j]=='@') + (int)(v[i-1][j+1] =='@') + (int)(v[i-1][j-1] =='@') + (int)(v[i][j+1] =='@') + (int)(v[i][j-1] =='@') + (int)(v[i+1][j] =='@') + (int)(v[i+1][j-1] =='@') + (int)(v[i+1][j+1]=='@');
 	        if (adjCount < 4){
 	          ret++;
 	          v2[i][j] = 'X';
 	        }
 	      }
 	    }
 	    vOut(v2);

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
