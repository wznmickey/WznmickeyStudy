#include <bits/stdc++.h>
using namespace std;
void print(int x)
{
    if (x >= 27)
        print((x - 1) / 26);
    cout << (char)((x - 1) % 26 + 'A');
    return;
}
struct node
{
    int colum = 0;
    int roll = 0;
    void printnumber()
    {
        cout << 'R' << roll << 'C' << colum << endl;
        return;
    }
    void printletter()
    {
        if (colum >= 27)
            print((colum - 1) / 26);
        cout << (char)((colum - 1) % 26 + 'A');
        cout << roll << endl;
        return;
    }
};
void solve1(string &str)
{
    node ans;
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            ans.colum = ans.colum * 26 + str[i] - 'A' + 1;
        }
        else
        {
            ans.roll = ans.roll * 10 + str[i] - '0';
        }
    }
    ans.printnumber();
    return;
}
void solve2(string &str)
{
    node ans;
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            ans.roll = ans.roll * 10 + str[i] - '0';
        }
        if (str[i] == 'C')
        {
            for (; i < len; i++)
            {
                if (str[i] >= '0' && str[i] <= '9')
                {
                    ans.colum = ans.colum * 10 + str[i] - '0';
                }
            }
            ans.printletter();
            return;
        }
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        bool kind = true; //true-letter-colum  false-number-colum
        bool num = false;
        int len = str.size();
        for (int j = 0; j < len; j++)
        {
            if (str[j] >= '0' && str[j] <= '9')
                num = true;
            if (num == true && str[j] >= 'A' && str[j] <= 'Z')
            {
                kind = false;
                break;
            }
        }
        if (kind == true)
            solve1(str);
        else
            solve2(str);
    }
    return 0;
}