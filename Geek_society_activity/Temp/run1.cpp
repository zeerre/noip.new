#include <iostream> 

using namespace std; 

int n, k; 

int solve1() 
{ 
    int l = 0, r = n; 
    while (l <= r) {
        int mid = (l + r) / 2; 
        if (mid * mid <= n) l = mid + 1; 
        else r = mid - 1; 
    }
    return l - 1; 
} 

double solve2(double x) 
{ 
    if (x == 0) return x;
    for (int i = 0; i < k; i++) 
        x = (x + n / x) / 2;
    return x; 
} 

int main() 
{ 
    cin >> n >> k;
    double ans = solve2(solve1());
    cout << ans << ' ' << (ans * ans == n) << endl; 
    return 0;
}