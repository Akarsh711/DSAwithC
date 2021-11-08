#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

// these are the different functions use to find the possible movement of knights
tuple<int, int, int> left(int x, int y)
{
    // left
    // cout << "left" << endl;
    int r = x - 2;
    int var1 = y + 1;
    int var2 = y - 1;
    return make_tuple(r, var1, var2);
}

tuple<int, int, int> right(int x, int y)
{
    // right
    // cout << "right" << endl;
    int r = x + 2;
    int var1 = y + 1;
    int var2 = y - 1;
    return make_tuple(r, var1, var2);
}

tuple<int, int, int> up(int x, int y)
{
    // up
    // cout << "up" << endl;
    int c = y + 2;
    int var1 = x + 1;
    int var2 = x - 1;
    return make_tuple(c, var1, var2);
}

tuple<int, int, int> down(int x, int y)
{
    // down
    // cout << "down" << endl;
    int c = y - 2;
    int var1 = x + 1;
    int var2 = x - 1;
    return make_tuple(c, var1, var2);
}

vector<pair<int, int>> movements(int x, int y)
{ //row, column respectively
    tuple<int, int, int> temp;
    vector<pair<int, int>> pos;

    temp = left(x, y);
    pos.push_back({get<0>(temp), get<1>(temp)});
    pos.push_back({get<0>(temp), get<2>(temp)});

    temp = right(x, y);
    pos.push_back({get<0>(temp), get<1>(temp)});
    pos.push_back({get<0>(temp), get<2>(temp)});

    temp = up(x, y);
    pos.push_back({get<1>(temp), get<0>(temp)});
    pos.push_back({get<2>(temp), get<0>(temp)});

    temp = down(x, y);
    pos.push_back({get<1>(temp), get<0>(temp)});
    pos.push_back({get<2>(temp), get<0>(temp)});

    return pos;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    for(int val=1; val<=t; val++){
        
        // int val = t;
        int n = val;
        int grid = n * n;
        vector<pair<int, int>> pos;

        // map<pair<int, int>, int> m;
        int count = 0;
        int no_of_positions = 0;
        int danger = 0;
        int flg = 1;
        for (int i = 0; i < val; i++)
        {
            if(flg!=1) break;
            for (int j = 0; j < val; j++)
            {
                if(flg != 1){
                    break;
                }
                pos = movements(i, j);

                for (auto k : pos)
                {
                    if ((k.first >= 0 && k.second >= 0) && (k.first < n && k.second < n))
                    {
                        danger++;
                    }
                }


                if (n % 2 == 0)
                {
                    int half = (grid - (danger + 1)) / 2;

                    if (count == ceil((grid) / 2))
                    {
                        cout << no_of_positions << "\n";
                        flg =  0;
                    }
                    no_of_positions += grid-(danger+1);
                    danger = 0;
                }

                if (n % 2 != 0)
                {
                    int half = (grid - (danger + 1)) / 2;
                    no_of_positions += grid - (danger + 1);

                    if (count == ceil((grid) / 2))
                    {
                        cout << no_of_positions-half<< "\n";
                        flg =  0;
                    }
                    danger = 0;
                }
                count++;
            }
        }
    }

    return 0;
}