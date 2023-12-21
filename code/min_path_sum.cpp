/**
 * @file min_path_sum.cpp
 * 
 * https://leetcode.cn/problems/minimum-path-sum
 * 
 * 
 * 给定一个包含非负整数的 m x n 网格 grid ，
 * 
 * 请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

输入：grid =[[1,3,1],    1,4,5
            [1,5,1],     2,7,6
            [4,2,1]]     6,8,7
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。
示例 2：

输入：grid = [[1,2,3],[4,5,6]]
输出：12

1,2,3
4,5,6

1,3,6
5,8,12

 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void print(vector<vector<int>> &data){
    for(auto &vec: data){
        for(auto &v : vec){
            cout << v << "\t";
        }
        cout << endl;
    }//end for each
}

int minPathSum(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<int>> minPathGrid(m , vector<int>(n));

    // print(minPathGrid);

    for(int i = 0 ; i < m ;i++){
        for(int j = 0 ; j < n; j++){
            if(i == 0 && j == 0){
                minPathGrid[i][j] = grid[i][j];
            }else{
                if(i - 1 < 0){ 
                    minPathGrid[i][j] = grid[i][j] + minPathGrid[i][j-1];
                }else if(j - 1 < 0){
                    minPathGrid[i][j] = grid[i][j] + minPathGrid[i-1][j];
                }else{
                    minPathGrid[i][j] = grid[i][j] + min(minPathGrid[i-1][j] , minPathGrid[i][j-1]);
                }
            }
        }//end for j
    }//end for i

    return minPathGrid[m - 1][n - 1];
}

int main(){
    // vector<vector<int>> grid = {
    //     {1,2,3},
    //     {4,5,6}
    // };

    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    auto result = minPathSum(grid);
    cout << "minPathSum = " << result << endl;
    return 0;
}