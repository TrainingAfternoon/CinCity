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

vector<double> create_possibilities(int N, int d, int s, int t, int fmin, int fmax) {
    vector<double> res;
    bool eyelets[2 * (N - 1)]; // excluding the first row because always the same
    stack<LaceStep> stack_;
    LaceStep curr = LaceStep();
    curr.currEyelets = eyelets;
    curr.totalLength = s; // I want do the whole distance
    curr.currNode = -2;
    stack_.push(curr);
    while (!stack_.empty()) {
        curr = stack_.top();
        stack_.pop();
        if (curr.currNode == 2 * (N - 1) - 1 || curr.currNode == 2 * (N - 1) - 2) {
            double tDistance = 2 * t;
            for (int i = 0; i < 2 * (N - 1); ++i) {
                if (curr.currEyelets[i]) tDistance += t;
            }
            res.emplace_back(curr.totalLength + tDistance);
            continue;
        }
        for (int i = 0; i < 2 * (N - 1); ++i) {
            if (!curr.currEyelets[i] && curr.currNode != i) {
                LaceStep step = LaceStep();
                bool *new_eyelets = new bool[2 * (N - 1)];
                copy(curr.currEyelets, curr.currEyelets + 2 * (N - 1), new_eyelets + 0);
                new_eyelets[2 * (i / 2)] = true;
                new_eyelets[2 * (i / 2) + 1] = true;
                step.currEyelets = new_eyelets;
                step.currNode = i;
                int changeLevel = abs(curr.currNode / 2 - i /2);
                if (i % 2 != abs(curr.currNode % 2) || changeLevel <= 1) { // checks for adjacent same column
                    step.totalLength = i % 2 == abs(curr.currNode % 2) ? 2 * changeLevel * d + curr.totalLength :
                                       2 * sqrt(pow(changeLevel * d, 2) + pow(s, 2)) + curr.totalLength;
                    stack_.push(step);
                }
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, d, s ,t ,fmin ,fmax;
    cin >> N >> d >> s >> t >> fmin >> fmax;
    vector<double> possible_ranges = create_possibilities(N, d, s, t, fmin, fmax);
    for (double d_: possible_ranges) {
        cout << d_ << nl;
    }
    double L;
    while (cin >> L) {
        int count = 0;
        for (double length: possible_ranges) {
            if (length + 2 * fmin <= L && L <= length + 2 * fmax) {
                count++;
            }
        }
        cout << count << nl;
    }
    return 0;
} // 8 10 25 3 125 175
