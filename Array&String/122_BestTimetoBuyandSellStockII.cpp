/*
    You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

    On each day, you may decide to buy and/or sell the stock. You can only hold at most one 
    share of the stock at any time. However, you can buy it then immediately sell it on the same day.

    Find and return the maximum profit you can achieve.
*/

// Greedy 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        int start = prices[0];
        for(int i=1;i<n;i++){
            if(start<prices[i]) profit+=prices[i]-start;
            start = prices[i];
        }
        return profit;
    }
};

// DP
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            vector<int>ahead(2,0),curr(2,0);
            ahead[0]=0;
            ahead[1]=0;
            for(int i = n-1;i>=0;i--){
                for(int buy=0;buy<2;buy++){
                    int profit=0;
                    if(buy){
                        profit = max((-prices[i]+ahead[0]),(0+ahead[1]));
                    }
                    else{
                        profit = max((prices[i]+ahead[1]),(0+ahead[0]));
                    }
                    curr[buy] = profit;
                }
                ahead=curr;
            }
    
            return ahead[1];
        }
    };

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            vector<vector<int>>dp(n+1,vector<int>(2,0));
            dp[n][0]=0;
            dp[n][1]=0;
            for(int i = n-1;i>=0;i--){
                for(int buy=0;buy<2;buy++){
                    int profit=0;
                    if(buy){
                        profit = max((-prices[i]+dp[i+1][0]),(0+dp[i+1][1]));
                    }
                    else{
                        profit = max((prices[i]+dp[i+1][1]),(0+dp[i+1][0]));
                    }
                    dp[i][buy] = profit;
                }
            }
    
            return dp[0][1];
        }
    };

class Solution {
    public:
        int recursion(int i,int buyorsell,vector<int>& prices,vector<vector<int>>&dp){
            if(i==prices.size()){
                return 0;
            }
            int profit=0;
            if(dp[i][buyorsell]!=-1) return dp[i][buyorsell];
            if(buyorsell){
                profit = max((-prices[i]+recursion(i+1,0,prices,dp)),(0+recursion(i+1,1,prices,dp)));
            }
            else{
                profit = max((prices[i]+recursion(i+1,1,prices,dp)),(0+recursion(i+1,0,prices,dp)));
            }
            return dp[i][buyorsell] = profit;
        }
        int maxProfit(vector<int>& prices) {
            vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
            return recursion(0,1,prices,dp);
        }
    };

// Recursion
class Solution {
public:
    int recursion(int i,int sellorbuy,vector<int>& prices){
        if(i==prices.size()){
            return 0;
        }
        int profit=0;
        if(sellorbuy){
            profit = max((-prices[i]+recursion(i+1,0,prices)),(0+recursion(i+1,1,prices)));
        }
        else{
            profit = max((prices[i]+recursion(i+1,1,prices)),(0+recursion(i+1,0,prices)));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return recursion(0,1,prices);
    }
};