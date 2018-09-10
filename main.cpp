#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>

using  namespace std;

//拡張ユークリッドの互除法
//ax + by = cとなるようなc=gcd(a,b)をxをペアにして返す
//firstがx,secondがc
template <typename number>
pair<number, number> extended_euclid(number a, number b)
{
    number r0, r1, a0, a1, b0, b1;
    r0 = a; r1 = b;
    a0 = 1; a1 = 0;
    b0 = 0; b1 = 1;
    while (r1>0) {
        number q1 = r0 / r1;
        number r2 = r0 % r1;
        number a2 = a0 - q1 * a1;
        number b2 = b0 - q1 * b1;
        r0 = r1 ; r1 = r2;
        a0 = a1 ; a1 = a2;
        b0 = b1 ; b1 = b2;
    }
    number c = r0;
    a = a0; //x
    b = b0; //y
    return  {a, c};
}

void c()
{
    int n, x;
    cin >> n >> x;
    vector<int> city(n);
    for (int i = 0; i < n; ++i) {
        cin >> city[i];
    }
    for (int i = 0; i < n; ++i) {
        city[i] = abs(x - city[i]);
    }
    if(n < 2)
    {
        cout << city[0] << endl;
    }else {
        pair<int, int> temp = extended_euclid(city[0], city[1]);
        for (int i = 3; i < n; ++i) {
            temp = extended_euclid(city[i], temp.second);
        }
        cout << temp.second << endl;
    }
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            grid[i][j] = grid[i][j] % 2;
        }
    }
    bool flag = false;
    vector<string> op;
    for (int i = 0; i < h; ++i) {
        if(i % 2 == 0)
        {
            for (int j = 0; j < w; ++j) {
                if(flag)
                {
                    if(j == 0)
                    {
                        string t = to_string(i - 1 + 1) + " " + to_string(j + 1) + " " +
                                to_string(i + 1) + " " + to_string(j + 1);
                        op.push_back(t);
                    } else{
                        string t = to_string(i + 1) + " " + to_string(j - 1 + 1) + " " +
                                   to_string(i + 1) + " " + to_string(j + 1);
                        op.push_back(t);
                    }
                    if(grid[i][j] == 1){
                        flag = false;
                    }
                }else{
                    if(grid[i][j] == 1)
                    {
                        flag = true;
                    }
                }
            }
        }else{
            for (int j = w - 1; j >= 0; --j) {
                if(flag)
                {
                    if(j == w - 1)
                    {
                        string t = to_string(i  - 1 + 1) + " " + to_string(j + 1) + " " +
                                   to_string(i + 1) + " " + to_string(j + 1);
                        op.push_back(t);
                    }else{
                        string t = to_string(i + 1) + " " + to_string(j + 1 + 1) + " " +
                                   to_string(i + 1) + " " + to_string(j + 1);
                        op.push_back(t);
                    }
                    if(grid[i][j] == 1)
                    {
                        flag = false;
                    }
                }else{
                    if(grid[i][j] == 1)
                    {
                        flag = true;
                    }
                }
            }
        }
    }
    cout << op.size() << endl;
    for(auto e: op)
    {
        cout << e << endl;
    }
    return 0;
}