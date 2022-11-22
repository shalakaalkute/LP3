#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
	// making and initializing dp array
	int dp[W + 1];
    for(int i=0; i<W+1; i++){
        dp[i]=0;
    }
	for (int i = 1; i < n + 1; i++) {
		for (int w = W; w >= 0; w--) {

			if (wt[i - 1] <= w)
				// finding the maximum value
				dp[w] = max(dp[w],dp[w - wt[i - 1]] + val[i - 1]);
		}
	}
	return dp[W]; // returning the maximum value of knapsack
}
int main()
{
    int n;
    cout<<"\tEnter total number of items: ";
    cin>>n;
	int val[n];
    for(int i=0; i<n; i++){
        cout<<"\nEnter Price of item "<<(i+1)<<": ";
        cin>>val[i];
    }
	int wt[n];
    for(int i=0; i<n; i++){
        cout<<"\nEnter weight of item "<<(i+1)<<": ";
        cin>>wt[i];
    }
	int Capacity;
    cout<<"\n\tEnter capacity of knapsack: ";
    cin>>Capacity;
	cout <<"Total Profit: " <<knapSack(Capacity, wt, val, n);
	return 0;
}
