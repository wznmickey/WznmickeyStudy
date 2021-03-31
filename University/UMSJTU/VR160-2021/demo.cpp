// written by Mickey to simulate comparative advantage model
#include <bits/stdc++.h>
using namespace std;
/*            Product 1       Product 2
    Country A       1,1             1,2
    Country B       2,1             2,2
*/
int ability[3][3];
int beforeSpecification[3][3];
int afterSpecification[3][3];
int afterTrade[3][3];
bool okay[300][300];
bool check(int a, int b, int c, int d)
{
    afterSpecification[1][1] = ability[1][1] * a;
    afterSpecification[1][2] = ability[1][2] * b;
    afterSpecification[2][1] = ability[2][1] * c;
    afterSpecification[2][2] = ability[2][2] * d;
    if ((afterSpecification[1][1] - beforeSpecification[1][1]) * (afterSpecification[2][1] - beforeSpecification[2][1]) < 0)
    {
        if (afterSpecification[1][1] - beforeSpecification[1][1] < 0)
        {
            afterTrade[1][1] = beforeSpecification[1][1];
            afterTrade[2][1] = afterSpecification[1][1] + afterSpecification[2][1] - afterTrade[1][1];
            afterTrade[2][2] = beforeSpecification[2][2];
            afterTrade[1][2] = afterSpecification[1][2] + afterSpecification[2][2] - afterTrade[2][2];
        }
        else
        {
            afterTrade[2][1] = beforeSpecification[2][1];
            afterTrade[1][1] = afterSpecification[1][1] + afterSpecification[2][1] - afterTrade[2][1];
            afterTrade[1][2] = beforeSpecification[1][2];
            afterTrade[2][2] = afterSpecification[1][2] + afterSpecification[2][2] - afterTrade[1][2];
        }
        if (afterTrade[1][1] >= beforeSpecification[1][1] && afterTrade[1][2] >= beforeSpecification[1][2] && afterTrade[2][1] >= beforeSpecification[2][1] && afterTrade[2][2] >= beforeSpecification[2][2])
            return true;
        else
            return false;
    }
    else
        return false;
}
int main()
{
    cin >> ability[1][1] >> ability[1][2] >> ability[2][1] >> ability[2][2];
    beforeSpecification[1][1] = ability[1][1] * 100;
    beforeSpecification[1][2] = ability[1][2] * 100;
    beforeSpecification[2][1] = ability[2][1] * 100;
    beforeSpecification[2][2] = ability[2][2] * 100;
    for (int i = 0; i <= 200; i++)
    {
        for (int j = 0; j <= 200; j++)
        {
            if (check(i, 200 - i, j, 200 - j) == true)
            {
                cout << i << " " << 200 - i << endl
                     << j << " " << 200 - j << endl
                     << endl;
                okay[i][j] = true;
            }
            else
            {
                okay[i][j] = false;
            }
        }
    }
    for (int i = 0; i <= 200; i++)
    {
        bool flag = true;
        for (int j = 0; j <= 200; j++)
        {
            if (okay[i][j] == false)
                flag = false;
        }
        if (flag == true)
            cout << "For any B's decision, A is okay" << i << endl;
    }
    for (int j = 0; j <= 200; j++)
    {
        bool flag = true;
        for (int i = 0; i <= 200; i++)
        {
            if (okay[i][j] == false)
                flag = false;
        }
        if (flag == true)
            cout << "For any A's decision, B is okay" << j << endl;
    }
    return 0;
}