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

// -------------------SOLUTION--------------------//
int solve(){

    int x1, x2;
    cin>>x1>>x2;

    bool f1 = x1 > x2;
    if(x1 < x2) x1 += 4;
    else x2 += 4;

    bool m1 = false, m2 = false;
    int n1;
    cin>>n1;

    vi t1(n1);

    int t;
    for(int i = 0; i < n1; i++){
        cin>>t;
        t1[i] = t;
    }

    int n2;
    cin>>n2;

    vi t2(n2);
    for(int i = 0 ; i < n2; i++){
        cin>>t;
        t2[i] = t;
    }

    int time = 0;

    int diff;
    int i1 = 0;
    int i2 = 0;
    while(i1 < n1 && i2 < n2){
//        cout<<"time: "<<time<<" "<<x1<<" "<<x2<<nn;
        diff = min(t1[i1], t2[i2]) - time;
        if(m1) x1 += diff;
        if(m2) x2 += diff;
        diff = abs(x1-x2);

        time = min(t1[i1], t2[i2]);
        if(f1){
            if(x2 >= x1){
                cout<<"bumper tap at time "<<(time-diff);
                return 0;
            }
        } else {
            if(x1 >= x2){
                cout<<"bumper tap at time "<<(time-diff);
                return 0;
            }
        }

        if(t1[i1] == t2[i2]){
            i1++;
            i2++;
            m1 = !m1;
            m2 = !m2;
        } else if (t1[i1] > t2[i2]){
            i2++;
            m2 = !m2;
        } else {
            i1++;
            m1 = !m1;
        }
    }
//    cout<<"done"<<nn;
//    cout<<"time: "<<time<<" "<<x1<<" "<<x2<<nn;
//    cout<<"problem"<<nn;
    while(i1 < n1){
        if(m1) x1 += t1[i1] - time;
        if(m2) x2 += t1[i1] - time;

        m1 = !m1;
        time = t1[i1++];
        diff = abs(x1-x2);

        if(f1){
            if(x2 >= x1){
                cout<<"bumper tap at time "<<(time-diff);
                return 0;
            }
        } else {
            if(x1 >= x2){
                cout<<"bumper tap at time "<<(time-diff);
                return 0;
            }
        }
    }
    while(i2 < n2){
        if(m1) x1 += t2[i2] - time;
        if(m2) x2 += t2[i2] - time;

        m2 = !m2;
        time = t2[i2++];
        diff = abs(x1-x2);

        if(f1){
            if(x2 >= x1){
                cout<<"bumper tap at time "<<(time-diff);
                return 0;
            }
        } else {
            if(x1 >= x2){
                cout<<"bumper tap at time "<<(time-diff);
                return 0;
            }
        }

    }

//    for(; i < n2; i++){
//        cin>>t;
//        m2 = ! m2;
//        while(t > 0){
//            diff = p > n1 ? t : abs(t-t1[p]);
//            time += diff;
//            if(m1) x1 +=diff;
//            if(m2) x2 +=diff;
//            if(p > n1){
//                if(t == t1[p]){
//                    t = 0;
//                    p++;
//                    m1 = !m1;
//                } else if(t > t1[p]){
//                    t-=t1[p];
//                    p++;
//                    m1 = !m1;
//                } else {
//                    t1[p] -= t;
//                    t = 0;
//                }
//            } else {
//                t = 0;
//            }
//
//            diff = abs(x1-x2);
//            if(f1){
//                if(x2 >= x1){
//                    cout<<"bumper tap at time "<<(time-diff);
//                    return 0;
//                }
//            } else {
//                if(x1 >= x2){
//                    cout<<"bumper tap at time "<<(time-diff);
//                    return 0;
//                }
//            }
//        }
//    }
//    while(p < n1){
//        if(m1) x1 += t1[p];
//        time += t1[p++]; 
//        m1 = !m1;
//
//        diff = abs(x1-x2);
//        if(f1){
//            if(x2 >= x1){
//                cout<<"bumper tap at time "<<(time-diff);
//                return 0;
//            }
//        } else {
//            if(x1 >= x2){
//                cout<<"bumper tap at time "<<(time-diff);
//                return 0;
//            }
//        }
//    }

    if((m1 && m2) || (!m1 && !m2)){
        cout<<"safe and sound";
        return 0;
    } else if((m1 && f1 ) || (m2 && !f1)){
        cout<<"safe and sound";
        return 0;
    }
    diff = abs(x1-x2);
    cout<<"bumper tap at time "<<(time+diff);

    return 0;
}

// -------------------MAIN CODE-------------------//
int main(){
    solve();
    return 0;
}

