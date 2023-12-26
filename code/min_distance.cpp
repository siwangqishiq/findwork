/**
 * https://leetcode.cn/problems/edit-distance/description
 * 
 * 
 * 
 * 给你两个单词 word1 和 word2， 
 * 
 * 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：

插入一个字符 insert
删除一个字符 delete
替换一个字符 replace
  r o s
h 1 2 3
o 2 1 2
r 2 2 2
s 3 3 2
e 4 4 3

  r o s
h 1 2 3
o 2 1 2
r 2 2 2
s 3 3 2
e 4 4 3

示例 1：

  a b
c 1 2
b 2 1 

输入：
    word1 = "horse", 
    word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：
  e x e c u t i o n
i 1 2 3 4 5 6 6 7 8
n 2 2 3 4 5 6 7 7 7
t 3 3 3 4 5 5 6 7 8
e 3 4 3 4 5 6 6 7 8
n 4 4 4 4 5 6 7 7 7
t 5 5 5 5 5 5 6 7 8
i 6 6 6 6 6 6 5 6 7
o 7 7 7 7 7 7 6 5 6
n 8 8 8 8 8 8 7 6 5

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
 * 
 */


#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(vector<vector<int>> &data){
    for(auto &vec: data){
        for(auto &v : vec){
            cout << v << "\t";
        }
        cout << endl;
    }//end for each
}

/**
 * @brief 
 * 
 * 
 *    '' r o s
 *  '' 0 1 2 3
 *   h 1 1 2 3
 *   o 2 2 1 2
 *   r 3 2 2 2
 *   s 4 3 3 2
 *   e 5 4 4 3
 * 
 * @param word1 
 * @param word2 
 * @return int 
 */
int minDistance(string word1, string word2){
    const int m = word1.size();
    const int n = word2.size();

    if(m * n == 0){
        return m + n;
    }

    vector<vector<int>> dp(m + 1 , vector<int>(n + 1));
    for(int i = 0 ;  i < m + 1 ; i++){
        dp[i][0] = i;
    }//end for i
    for(int j = 0; j < n + 1 ; j++){
        dp[0][j] = j;
    }//end for j

    for(int i = 1 ; i < m + 1 ; i++){
        for(int j = 1 ; j < n + 1 ; j++){
            int leftDpValue = dp[i][j - 1] + 1;
            int topDpValue = dp[i - 1][j] + 1;
            int leftTopDpValue = dp[i - 1][j - 1];

            if(word1[i - 1] != word2[j - 1]){
                leftTopDpValue = leftTopDpValue + 1;
            }//end if

            dp[i][j] = min(leftDpValue , min(topDpValue , leftTopDpValue));
        }//end for j
    }//end for i

    // print(dp);
    return dp[m][n];
}

// int minDistance(string word1, string word2) {
//     if(word1.empty() || word2.empty()){
//         return word1.size() + word2.size();
//     }

//     const int m = word1.size();
//     const int n = word2.size();

//     vector<vector<int>> dp(m , vector<int>(n , 0));

//     for(int i = 0 ; i < m ;i++){
//         for(int j = 0 ; j < n; j++){
//             const int step = (word1[i] == word2[j])?0:1;

//             if(i == 0 && j == 0){
//                 dp[i][j] += step;
//             }else if(i == 0){
//                 dp[i][j] = dp[i][j - 1] + 1;
//             }else if(j == 0){
//                 dp[i][j] = dp[i - 1][j] + 1;
//             }else{
//                 const int topMinValue = dp[i - 1][j];
//                 const int leftMinValue = dp[i][j - 1];
//                 const int leftTopMinValue = dp[i - 1][j - 1];

//                 if(topMinValue < leftMinValue && topMinValue < leftTopMinValue){ //top is least
//                     dp[i][j] = dp[i - 1][j] + step;
//                 }else if(leftMinValue < topMinValue && leftMinValue < leftTopMinValue){ // left is least
//                     dp[i][j] = dp[i][j - 1] + step;
//                 }else{// topleft is least
//                     dp[i][j] = dp[i - 1][j - 1] + step;
//                 }
//             }
//         }//end for j
//     }//end for i

//     print(dp);
//     return dp[m - 1][n - 1];
// }

/**
 * @brief 
 * 
 * 
 * 
 * 
 * @return int 
 */

int main(){
    string word1 = "zoologicoarchaeologist";
    string word2 = "zoogeologist";

    cout << minDistance(word1 , word2) << endl;
    return 0;
}