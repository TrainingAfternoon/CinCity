#include <bits/stdc++.h>

// var types
#define ll long long
#define ld long double
#define nn '\n'
#define pb push_back
#define mp make_pair

// collection shorthand
#define V vector
#define vi V<int>
#define vll V<ll> #define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>

// loops
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())
#define in_map(m,e) (m.find(e) == m.end())
#define findchar(s,c) s.find(c)==string::npos?-1:s.find(c);

using namespace std;
// constants
const double PI = 3.1415926585323;
const int MOD = 1e9 + 7;

int _size;
int total;

struct node {
   V<int> wins;
   V<int> score;
   bool searched;
   char letter;

   node(char l){
       wins.clear();
       score.resize(_size);
       searched = false;
       letter = l;
   }

   void winAgainst(int i, int count){
       score[i]+=count;
   }

   void simplify(){
       for(int i = 0; i < score.size(); i++){
           if(score[i] > total/2) {
               wins.pb(i);
           }
       }
   }
};

V<node> nodes;

//bool canWin(int index, int i){ 
//    if(nodes[index].wins.size() == 0) return false;
//    if(i == 0){
//        return true;
//    }
//    nodes[index].searched = true;
//    vi current;
//    for(int w : nodes[index].wins){
//        if(!nodes[w].searched){
//            i--;
//            if(i == 0){
//                nodes[index].searched = false;
//                for(int t : current) nodes[t].searched = false;
//                return true;
//            }
//            nodes[w].searched = true;
//            current.pb(w);
//        }
//    }
//    for(int w : current){
//        if(canWin(w, i)){
//            nodes[index].searched = false;
//            for(int t : current) nodes[t].searched = false;
//            return true;
//        }
//    }
//    nodes[index].searched = false;
//    for(int t : current) nodes[t].searched = false;
//    return false;
//}

int canWin(int index, int i){

    nodes[index].searched = true;
    for(int w : nodes[index].wins){
        if(!nodes[w].searched){
            i--;
            if(i==0){
                return 0;
            }
            i = canWin(w, i);
            if(i==0){
                return 0;
            }
        }
    }
    return i;
}


//bool canWin(int index, int i){
//       nodes[index].searched = true;
//       if(i == 0){
//           nodes[index].searched = false;
//           return true;
//       }
//       int c=0;
//       for(int w : nodes[index].wins){
//           if(!nodes[w].searched){
//               c++;
//               if(c==i || canWin(w, i-1)){
//                   nodes[index].searched = false;
//                   return true;
//               }
//           }
//       }
//       return false;
//}


//bool canWin(int index, int i){
//       nodes[index].searched = true;
//       if(i == 0){
//           nodes[index].searched = false;
//           return true;
//       }
//       vi current;
//       for(int w : nodes[index].wins){
//           if(!nodes[w].searched){
//               i--;
//               if(i == 0){
//                   nodes[index].searched = false;
//                   for(int w2 : current) nodes[w2].searched = false; 
//                   return true;
//               }
//               nodes[w].searched = true;
//               current.pb(w);
//           }
//       }
//       for(int j = 0; j < current.size(); j++){
//           if(canWin(current[j], i)){
//               nodes[index].searched = false;
//               for(int k = 0; k < current.size(); k++) nodes[current[k]].searched = false; 
//               return true;
//           }
//       }
//       nodes[index].searched = false;
//       for(int k = 0; k < current.size(); k++) nodes[current[k]].searched = false; 
//       return false;
//}

// -------------------SOLUTION--------------------//
int solve(){
    int n, m, p;
    string ballot;

    cin>>n>>m;
    _size = n;
    total = 0;

    nodes.clear();
    for(int i = 0; i < n; i++){
        node temp((char)('A'+i));
        nodes.pb(temp);
    }

    while(m--){
        cin>>p>>ballot;
        total += p;
        for(int i = 0; i < n-1; i++){
            int w = ballot[i]-'A';
            for(int j = i+1; j < n;  j++){
                int l = ballot[j]-'A';
                nodes[w].winAgainst(l, p);
            }
        }
    }

    for(int i = 0; i < n; i++){
        nodes[i].simplify();
    }
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n; j++){
//            if(nodes[i].score[j] > n/2){
//                nodes[i].wins.pb(nodes[j]);
//                cout<<(char)('A'+i)<<"wins against"<<(char)('A'+j)<<nn;
//            }
//        }
//    }
//
//    for(int i = 0; i < n; i++){
//        cout<<(char)('A'+i)<<" can win against ";
//        for(int w : nodes[i].wins){
//            cout<<(char)(nodes[w].letter)<<", ";
//        }
//        cout<<nn;
//    }
    for(int i = 0; i < n; i++){
        cout<<(char)('A'+i)<<": ";
        int s = nodes[i].wins.size();
        nodes[i].searched = true;
        if(s == n-1) cout<<"can win"<<nn;
        else if (s == 0) cout<<"can't win"<<nn;
        else cout<<(canWin(i,n-1)==0 ? "can win": "can't win")<<nn;
        for(int i = 0; i < n; i++) nodes[i].searched = false;
    }

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

