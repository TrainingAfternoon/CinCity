//
// Created by Jonny Keane on 5/23/21.
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
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    double r, dx, dy, x, y, p;
    cin >> r >> dx >> dy >> x >> y >> p;
    double maxSlice = 0.0;
    double topLeftX = x;
    double topLeftY = y;
    while (!(topLeftX <= -r && topLeftX + dx >= -r)) {
        if (topLeftX > -r) {
            topLeftX -= dx;
        } else {
            topLeftX += dx;
        }
    }
    while (!(topLeftY >= r && topLeftY - dy <= r)) {
        if (topLeftY < r) {
            topLeftY += dy;
        } else {
            topLeftY -= dy;
        }
    }
    vector<double> slices;
    for (double currY = topLeftY; currY > -r; currY -= dy) {
        cout << currY << endl;
        for (double currX = topLeftX; currX < r; currX += dx) {
            double sliceArea = 0.0;
            double hardBegin = currX, hardEnd = currX + dx;
            double begin = currX, end = currX + dx;
            double upperIntersect = sqrt(r * r - currY * currY);
            double lowerIntersect = sqrt(r * r - (currY - dy) * (currY - dy));
            if (hardBegin < -r) {
                hardBegin = -r;
                begin = -r;
            } else if (hardEnd > r) {
                hardEnd = r;
                end = r;
            } else {
                if (lowerIntersect > currX && lowerIntersect < currX + dx) {
                    end = lowerIntersect;
                    hardEnd = lowerIntersect;
                } else if (-lowerIntersect > currX && -lowerIntersect < currX + dx) {
                    begin = -lowerIntersect;
                    hardBegin = -lowerIntersect;
                }
            }
            if (end != r && upperIntersect > currX && upperIntersect < currX + dx) {
                end = -upperIntersect;
            } else if (begin != -r && -upperIntersect > currX && -upperIntersect < currX + dx) {
                begin = -upperIntersect;
            }
            cout << "\t" << hardBegin << " [" << begin << " " << end << "] " << hardEnd << endl;
            if ((currX < 0 && sqrt(r * r - hardEnd * hardEnd) < currY - dy) ||
                    (currX > 0 && sqrt(r * r - hardBegin * hardBegin) < currY - dy)) {
                sliceArea = 0;
            }
            if (currY > dy) {
                sliceArea = 0.5 * r * r *
                        ((asin(end/r) + 0.5 * sin(2 * asin(end/r))) -
                        (asin(begin/r) + 0.5 * sin(2 * asin(begin/r)))) -
                                (currY - dy) * dx +
                                dy * (dx - (end - begin));
            }
            cout << sliceArea << endl;

//            sliceArea +=
        }
    }
    int validSlices = 0;
    for (double slice: slices) {
        if (abs(slice/maxSlice - p) <= 1E-6) {
            ++validSlices;
        }
    }
    cout << validSlices << endl;
    return 0;
}