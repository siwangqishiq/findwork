

#include <iostream>
#include <vector>

using namespace std;


/**
 * @brief https://leetcode.cn/problems/unique-paths/description
 * 
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？
 * 
 * @return int 
 * 
 * 1 1 1
 * 1 2 3
 * 1 3 6
 * 
 * 
 * 1 1 1
 * 1 2 3
 * 1 3 6
 * 1 4 10
 * 1 5 15
 * 1 6 21
 * 1 7 28
 */


int uniquePaths(int m, int n) {
    if(m == 1 && n == 1){
        return 1;
    }

    // start[0 , 0] -> end[m - 1 , n - 1]
    vector<vector<int>> dp(m , vector<int>(n));

    for(int i = 0 ; i < m ; i++){
        for(int j = 0; j < n ; j++){
            if(i == 0 && j == 0){
                    dp[i][j] = 1;
            }else{
                if(i - 1 < 0){
                    dp[i][j] = dp[i][j - 1];
                } else if(j - 1 < 0){
                    dp[i][j] = dp[i - 1][j];
                } else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }//end for j
    }//end for i


    // for(auto &vec : dp){
    //     for(auto &v : vec){
    //         cout << v << "\t";
    //     }
    //     cout << endl;
    // }
    return dp[m - 1][ n - 1];
}

int main(){
    auto  result = uniquePaths(7 , 3);
    cout << "unique path = " << result << endl;
    return 0;
}