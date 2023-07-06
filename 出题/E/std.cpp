#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
    if (x.first.first * y.first.second != x.first.second * y.first.first)
        return x.first.first * y.first.second < x.first.second * y.first.first;
    return x.second < y.second;
}

int n, a, w[2003], x[2003], v[2003], ans;

int main() {
    cin >> n >> a;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> x[i] >> v[i];
    for (int i = 0; i < n; i++) {
        int sum = 0;
        vector<pair<pair<int, int>, int> > V;
        for (int j = 0; j < n; j++) {
            if (v[i] == v[j])
                if (x[i] <= x[j] && x[j] <= x[i] + a)
                    sum += w[j];
            if (v[i] < v[j]) {
                V.push_back({{x[i] - x[j], v[j] - v[i]}, j});
                V.push_back({{x[i] + a - x[j], v[j] - v[i]}, j + n});
            }
            if (v[i] > v[j]) {
                V.push_back({{x[j] - x[i] - a, v[i] - v[j]}, j});
                V.push_back({{x[j] - x[i], v[i] - v[j]}, j + n});
            }
        }
        sort(V.begin(), V.end(), cmp);
        int j;
        for (j = 0; j < V.size(); j++)
            if (V[j].first.first < 0)
                if (V[j].second < n)
                    sum += w[V[j].second];
                else
                    sum -= w[V[j].second - n];
            else
                break;
        ans = max(ans, sum);
        for (j; j < V.size(); j++) {
            if (V[j].second < n)
                sum += w[V[j].second];
            else
                sum -= w[V[j].second - n];
            ans = max(ans, sum);
        }
    }
    cout << ans;
}