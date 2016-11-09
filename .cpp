//
//  main.cpp
//  Cutting Rod Problem DP
//
//  Created by Zijian Xie on 2016/11/8.
//  Copyright © 2016年 Jason Xie. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class CuttingRoad{
private:
    int len;
    vector<int> value;
public:
    CuttingRoad(int lens, vector<int> t){
        value = t;
        len = lens;
    }
    
    int DP(){
        vector<vector<int>> dp(len+1,vector<int>(len+1,0));
        for(int i = 0; i <= len; ++i){
            dp[1][i] = value[0] * i;
        }
        
        for(int i = 1; i <= len; i++){//sublength = 1, 2, 3, ````, len-1
            for(int j = 1; j <= len; j++){//sub-total length = 1,2,3,```,length
                if(i > j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = max(dp[i-1][j], value[i-1] + (j - i > i ? dp[i][j-i] : dp[j-i][j-i]));
                }
            }
        }
        
        cout<<"The max value is "<< dp[len][len]<<endl;
        return dp[len][len];
    }
};

int main(int argc, const char * argv[]) {
    int lens = 5;
    vector<int> val = {2,5,7,8};
    CuttingRoad* test = new CuttingRoad(lens, val);
    test->DP();
    return 0;
}
