#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

// auto intersect(auto line1, auto line2){
//     // int a1= line1[0];
//     // int b1 = line1[1];
//     // int c1 = line1[2];
//     // int a2 = line2[0];
//     // int b2 = line2[1];
//     // int c2 = line2[2];
    
//     auto [a1, b1, c1] = line1;
//     auto [a2 ,b2, c2] = line2;
//     int den =a1*b2 - a2*b1;
//     int x = 0; 
//     int y = 0;
//     // cout<<den<<endl;
//     if(den!=0){
//     x = (c1*b2 - c2*b1)/den;
//     y = (a1*c2 - a2*c1)/den;
//     }
 
//     // cout<<"working"<<endl;
//     return make_tuple(x, y, den);
//     }


int32_t main()
{
    ll TC;
    cin >> TC;
    while (TC--)
    {
        ll n; cin >> n;
        vector<pair<int, int>> pt(n);
        map<tuple<int, int, int>, int> m[4];
        for (int i = 0; i < n; i++)cin >> pt[i].first;
        for (int i = 0; i < n; i++)cin >> pt[i].second;
        for (int i = 0; i < n; i++) {
            auto [xi, yi] = pt[i];
            m[0][ {1, 0, -xi}]++; // stores vertical lines
            m[1][ {0, 1, -yi}]++; // stores horizontal lines
            m[2][ {1, -1, -xi + yi}]++; // stores / lines
            m[3][ {1, 1, -xi - yi}]++; // stores \ lines
        }

        auto intersect = [&](auto line1 , auto line2) {
            auto [a1, b1, c1] = line1;
            auto [a2, b2, c2] = line2;
            int den = a1 * b2 - b1 * a2, x = 2e18, y = 0;
            if (den != 0) {
                x = b1 * c2 - b2 * c1; y = a2 * c1 - a1 * c2;
            }
            if (den < 0) {
                den = -den;
                x = -x;
                y = -y;
            }
            return make_tuple(x, y, den);
        };

        auto moves = [&](tuple<ll, ll, ll> point) {
            auto [x, y, den] = point;
            int cur = 2 * n;
            if (x == 2e18) return cur;
            for (int i = 0; i < n; i++) {
                auto [xi, yi] = pt[i];
                int ax = xi * den, ay = yi * den;
                if (ax == x && ay == y) cur -= 2;
                else if (ax == x || ay == y || (ax - ay) == (x - y) || (ax + ay) == (x + y)) cur--;
            }
            return cur;
        };

        int ans = 2 * n;
        //If final intersection point is one of the initial points
        for (int i = 0; i < n; i++) {
            auto [x, y] = pt[i];
            ans = min(ans, moves({x , y, 1}));
        }

        /*If final point is intersection of given lines (considering all pair of lines with different slopes)
        NOTE - Lines with same slopes never intersect */
        // for (int i = 0; i < 4; i++) {
        //     for (int j = i + 1; j < 4; j++) {
        //         for (auto [line1 , cnt1] : m[i]) {
        //             for (auto [line2 , cnt2] : m[j]){
        //                 auto point = intersect(line1, line2);
        //                 ans = min(ans , moves(point));
        //             }
        //         }
        //     }
        // }


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
                        auto point = intersect(line1, line2);
                        ans = min(ans , moves(point));
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}