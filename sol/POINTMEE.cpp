#include <bits/stdc++.h>
using namespace std;
// typedef map<pair<int, int>, vector<vector<int>>> tdvecmap;

auto moves(tuple<int, int, int> point, int n, vector<pair<int, int>> p)
{
    auto [x, y, den] = point;
    int cur = 2 * n;
    if (x == INT_MAX)
        return cur;
    for (int i = 0; i < n; i++)
    {
        auto [xi, yi] = p[i];
        int ax = xi * den, ay = yi * den;
        if (ax == x && ay == y)
            cur -= 2;
        else if (ax == x || ay == y || (ax - ay) == (x - y) || (ax + ay) == (x + y))
            cur--;
            
    }
    return cur;
}

auto intersect(auto line1, auto line2){
    int a1= line1[0];
    int b1 = line1[1];
    int c1 = line1[2];
    int a2 = line2[0];
    int b2 = line2[1];
    int c2 = line2[2];

    // auto [a2 ,b2, c2] = line2;
    int den =a1*b2 - a2*b1;
    int x = INT_MAX;
    int y = 0;
    // cout<<den<<endl;
    if(den!=0){
        x = b1 * c2 - b2 * c1;
        y = a2 * c1 - a1 * c2;
    }

// //Not know why
// if (den < 0) {
//             den = -den;
//             x = -x;
//             y = -y;
//         }

// // cout<<"working"<<endl;
return make_tuple(x, y, den);
}

int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        int N;
        cin >> N;

        vector<pair<int, int>> p(N); //points
        map<pair<int, int>, vector<vector<int>>> eqs;
        vector<pair<int, int>> ip; //intersecting points;

        for (int i = 0; i < N; i++)
            cin >> p[i].first;
        for (int i = 0; i < N; i++)
            cin >> p[i].second;

        // Line Equation
        for (int i = 0; i < N; i++)
        {
            /*
                1, 0, -xi ++
                0, 1, -yi ++
                1, -1, -xi+yi ++
                1, 1 , -xi-yi ++
            */

            // [a, b, c]4

            /*
                Type of lines    x      y
                -----------------------------
                90 deg          0         1
                135 deg         1         1
                180 deg         1         0
            */

            eqs[{p[i].first, p[i].second}].push_back({1,0,-p[i].first});
            eqs[{p[i].first, p[i].second}].push_back({0,1, -p[i].second});
            eqs[{p[i].first, p[i].second}].push_back({1, -1, (-p[i].first + p[i].second)});
            eqs[{p[i].first, p[i].second}].push_back({1, 1, (-p[i].first - p[i].second)});
        }

        // Finding intersection points
        /*auto intersect = [&](auto line1, auto line2)
        {
            int a1 = line1[0];
            int b1 = line1[1];
            int c1 = line1[2];
            int a2 = line2[0];
            int b2 = line2[1];
            int c2 = line2[2];

            int den = a1 * b2 - b1 * a2, x = 2e18, y = 0;
            if (den != 0)
            {
                x = b1 * c2 - b2 * c1;
                y = a2 * c1 - a1 * c2;
            }
            if (den < 0)
            {
                den = -den;
                x = -x;
                y = -y;
            }
            return make_tuple(x, y, den);
        };*/

        int ans = 2 * N;

        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                //loop for lines for point A.
                for (int k = 0; k < 4; k++)
                {
                    // loop for lines for point B.
                    for (int l = 0; l < 4; l++)
                    {
                        pair<int, int> pointa = {p[i].first, p[i].second};
                        pair<int, int> pointb = {p[j].first, p[j].second};

                        vector<int> line1 = eqs[pointa][k];
                        vector<int> line2 = eqs[pointb][l];

                        auto point = intersect(line1, line2);
                        ans = min(ans, moves(point, N, p));
                    }
                }
            }
        }

        cout << ans << endl;
        // void min()
    }
    return 0;
}