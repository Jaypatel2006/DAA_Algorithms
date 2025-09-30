#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minCut(string s)
{
    int n = s.size();
    vector<vector<bool>> pal(n, vector<bool>(n, false));
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        int cut = i;
        for (int j = 0; j <= i; j++)
        {
            if (s[i] == s[j] && (i - j < 2 || pal[j + 1][i - 1]))
            {
                pal[j][i] = true;
                cut = (j == 0) ? 0 : min(cut, dp[j - 1] + 1);
            }
        }
        dp[i] = cut;
    }
    return dp[n - 1];
}

int main()
{
    string s = "aab";
    cout << minCut(s) << endl;
    return 0;
}