// https://adventofcode.com/2025/day/8
// unsolved 
// comments: rip my cute adj matrix wtf is a kruskal

#include <bits/stdc++.h>
#include "../headers/all.hpp"

using namespace std;
using ll = long long;
const ll MXNUM = (ll)9e18;
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

bool step(vector<vll>& v){
    ll n = v.size();
    ll mn = MXNUM;
    ll mni = 0;
    ll mnj = 0;
    for (ll i=0; i<n; i++){
      for (ll j=0; j<n; j++){
        if (i==j) {continue;}
        if (v[i][j] < mn){
          mni = i;
          mnj = j;
          mn = v[i][j];
        }
      }
    }
    if (mn == MXNUM) return false; 

    if (v[mni][mni] == v[mnj][mnj]) {
        v[mni][mnj] = MXNUM;
        v[mnj][mni] = MXNUM;
        return false;
    }
    v[mni][mnj] = MXNUM;
    v[mnj][mni] = MXNUM;
    for (int i=0; i<n; i++){
      if (v[i][i] == v[mnj][mnj]){
        v[i][i] = v[mni][mni];
      }
    }
    return true;
}

void solve(){
    str next;
    vector<vll>v; //inside has length 3, outside is n
    while(getline(cin,next)){ 
 	    stringstream ss(next);
 	    vll vin;
 	    str sub;
 	    while (getline(ss, sub, ',')) {
 	      vin.pb(stoll(sub));
 	     }
 	     v.pb(vin);
    }
    ll n = v.size(); //number of boxes
    Out(v.size());

    //gen adjacency matrix
    // middle diagonal (i==j) will be for circuit group, each one starts in its own group
    
    vector<vll> matrix(n,vll (n, 0));
    for (int i=0; i<n; i++){
      for (int j=0; j<n; j++){
        if (i==j){matrix[i][j] = i;}
        else {
          ll dx = v[i][0]-v[j][0];
          ll dy = v[i][1]-v[j][1];
          ll dz = v[i][2]-v[j][2];
          ll dist = dx*dx+dy*dy+dz*dz;
          matrix[i][j] = dist;
        }
      }
    }


    ll epochs = 10;
    int steps = 0;
    while (steps<epochs){
      if (step(matrix)){
        steps++;
      }
    }

    //count total groups
    map<ll,ll> groups; //(group, count)
    for (int i=0; i<n; i++){ //going down middle diagonal
      groups[matrix[i][i]]++;
    }
    Out("groups size: " + to_string(groups.size()));

    vll groupSizes;
    for (auto &p : groups){
      groupSizes.pb(p.S);
    }

    sort(groupSizes.rbegin(), groupSizes.rend());
    Out(groupSizes[0]*groupSizes[1]*groupSizes[2]); 
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
