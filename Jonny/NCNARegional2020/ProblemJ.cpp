//
// Created by Jonny Keane on 2/27/21.
//
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back

#define V vector
#define vi V<int>
#define vll V<ll>
#define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>
#define graph V<vi>

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

using namespace std;

struct LaceStep {
    double totalLength;
    bool *currEyelets; // just want to wait for one of the chosen eyelets to be in the last row
    int currNode;
};

vector<pair<int, int>> create_possibilities(int N, int d, int s, int t, int fmin, int fmax) {
    vector<pair<int, int>> res;
    bool eyelets[2 * (N - 1)]; // excluding the first row because always the same
    stack<LaceStep> stack_;
    LaceStep curr = LaceStep();
    curr.currEyelets = eyelets;
    curr.totalLength = s; // I want do the whole distance
    curr.currNode = -1;
    stack_.push(curr);
    while (!stack_.empty()) {
        curr = stack_.top();
        stack_.pop();
        if (curr.currNode == 2 * (N - 1) - 1 || curr.currNode == 2 * (N - 1) - 2) {
            res.push_back(make_pair(curr.totalLength + fmin, curr.totalLength + fmax));
            continue;
        }
        for (int i = 0; i < 2 * (N - 1); ++i) {
            if (!curr.currEyelets[i] && curr.currNode != i) {
                LaceStep step = LaceStep();
                bool new_eyelets[2 * (N - 1)];
                copy(curr.currEyelets, curr.currEyelets + 2 * (N - 1), new_eyelets + 0);
                new_eyelets[i] = true;
                if (i % 2 == 0) {
                    new_eyelets[i + 1] = true;
                } else  {
                    new_eyelets[i - 1] = true;
                }
                step.currEyelets = new_eyelets;
                step.currNode = i;
                // step.totalLength = some implementation for distancep
                if (curr.currNode == -1) {
                    step.totalLength = i % 2 == 0 ? 2 * (i + 1) * d + curr.totalLength :
                            2 * sqrt(pow((double)((i + 1) * d), 2) + pow((double)(s + t), 2)) + curr.totalLength;
                } else {
                    int separation = abs(d - i);
                    step.totalLength = separation % 2 == 0 ? 2 * separation * d + curr.totalLength :
                            2 * sqrt(pow((double)(separation * d), 2) + pow((double)(s + t), 2)) + curr.totalLength;
                }
                stack_.push(step);
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // code here
    int N,d,s,t,fmin,fmax;
    cin >> N >> d >> s >> t >> fmin >> fmax;
    vector<pair<int, int>> possible_ranges = create_possibilities(N, d, s, t, fmin, fmax);
    for (auto a: possible_ranges)
    {
        cout << a.first << " " << a.second << nl;
    }
    int L;
    while (cin >> L) {
        int count = 0;
        for (auto p: possible_ranges) {
            if (p.first < L && L < p.second) {
                count++;
            }
        }
        cout << count << nl;
    }
    return 0;
}
