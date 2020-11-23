#include "assignment.h"
#include <bits/stdc++.h>
using namespace std;
void ex1( )
{
    int x, y, z;
    scanf( "%d", &x );
    cin >> y >> z;
    int ans = z - x + y;
    cout << ans << endl;
    return;
}
#ifdef JOJ
int main(){
    ex1();
    return 0;
}
#endif