// coinchange.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>   

using namespace std;

int coinchange(int coins[], int n, int value,vector<int>& dp)
{
    
    if (value == 0) {
        return 0;
    }
    if (dp[value] != -1) {
        return dp[value];
    }

    
    int maxsofar = INT_MAX;
   
    
    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= value)
        {
            int count = coinchange(coins, n, value - coins[i],dp);
            

            //maxsofar = min(maxsofar, (count + 1));
            if (count != INT_MAX && count + 1 < maxsofar) {
                maxsofar = count + 1;
            }
        }
    }
    dp[value] = maxsofar;
    return maxsofar;
}

int print(int coins[], int n, int value) {
    vector<int>dp(value + 1,-1);
    return coinchange(coins, n, value, dp);
}
int main()
{
    int coins[] = { 3,2,7,5,10,8 };
    int n = sizeof(coins) / sizeof(coins[0]);
    int value = 10;
    
    //for (int i = 0; i < p.size(); i++) {
    //    cout << p[i] << " ";
    int d = print(coins, n, value);
    if (d == INT_MAX) {
        d = -1;
    }
    cout << "min" << d;
    return 0;
 }
    


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
