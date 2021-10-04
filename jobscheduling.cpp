
struct Job{
    int x, y, p;
    Job(int start, int end, int profit){
        x = start;
        y = end;
        p = profit;
    }
};

class Solution {
public:

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector <Job> v;
        for(int i=0; i<n; i++)  v.push_back(Job(startTime[i], endTime[i], profit[i]));
        sort(v.begin(), v.end(), [&](Job a, Job b){return a.y <= b.y;}); //end time ke hisab se sort kiya
        vector <int> dp(n); // agr vector me i elements hoo then jo gain hoga woo dp[i] me stored hoga 
        for(int i=0; i<n; i++){
            int gain = v[i].p;
            int l = 0, r = i-1, j = -1;
            while(l<=r){ /// latest non conflicting Job find karne ke liye
                int m = (l+r)/2;
                if(v[m].y <= v[i].x){
                    l = m+1;
                    j = m;
                }
                else r = m-1;
            }
            if(j>=0) gain += dp[j];
            if(i>0) dp[i] = max(dp[i-1], gain);
            else dp[i] = gain;
        }
        return dp[n-1];
    }
};
