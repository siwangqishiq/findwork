

/**
 * @brief 
 * 
 * 最长公共子序列
 * 
 * longest common subsequence
 * 
 * 
 * 
 * 
 */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(vector<vector<int>> &data){
    for(auto &vec: data){
        for(auto &v : vec){
            cout << v << "\t";
        }
        cout << endl;
    }//end for each
}

int longestCommonSubsequence(string text1, string text2) {
    return 0;
}

const int DIR_LEFT = 1;
const int DIR_UP = 2;
const int DIR_LEFT_AND_UP = 3;

/**
 * @brief 
 * 
 * 
 *       '' t e x t 1 
 *          1 2 3 4 5
 *   ''   0 0 0 0 0 0
 *    t 1 0 1 1 1 1 1
 *    e 2 0 1 2 2 
 *    x 3 0
 *    t 4 0
 *    2 5 0
 * 
 * @param text1 
 * @param text2 
 * @return string 
 */
string lcs(string &text1 , string &text2){
    if(text1.empty() || text2.empty()){
        return "";
    }

    const int m = text1.size() + 1;
    const int n = text2.size() + 1;

    vector<vector<int>> dp(m , vector<int>(n));
    vector<vector<int>> memo = dp;

    for(int i = 0 ; i < n ;i++){
        dp[0][i] = 0;
        memo[0][i] = -1;
    }//end for i;

    for(int i = 0 ; i< m;i++){
        dp[i][0] = 0;
        memo[i][0] = -1;
    }//end for j
    
    for(int i = 1 ; i < m ; i++){
        for(int j = 1; j < n ; j++){
            if(text1[i - 1] == text2[j - 1]){ // 
                dp[i][j] = dp[i - 1][j - 1] + 1;
                memo[i][j] = DIR_LEFT_AND_UP;
            }else if(dp[i- 1][j] >= dp[i][j - 1]){
                dp[i][j] = dp[i- 1][j];
                memo[i][j] = DIR_UP;
            }else{
                dp[i][j] = dp[i][j - 1];
                memo[i][j] = DIR_LEFT;
            }
        }//end for j
    }//end for i

    //read from memo to a string 
    //this string is the longset common seq...
    
    // print(dp);
    print(memo);

    int x = m - 1;
    int y = n - 1;
    int memoValue = memo[x][y];
    vector<char> lcsVec;
    while(memoValue > 0){
        // cout << "x =" << x << "  y = " << y  << " memoValue = " << memoValue << endl;
        if(memoValue == DIR_LEFT){
            y = y - 1;
        }else if(memoValue == DIR_UP){
            x = x - 1;
        }else if(memoValue == DIR_LEFT_AND_UP){
            lcsVec.emplace_back(text1[x - 1]);

            x = x - 1;
            y = y - 1;
        }
        memoValue = memo[x][y];
    }//end while
    return string(lcsVec.begin() , lcsVec.end());
}

vector<string> findAllSubSeq(string &text){
    vector<string> result;
    result.push_back("");
    for(int i = 0 ; i < text.size() ; i++){
        auto ch = text[i];
        
        vector<string> subStrVector = result;
        for(auto &str : subStrVector){
            string addStr = str + (ch);
            result.push_back(addStr);
        }//end for each
    }//end for i
    return result;
}

int main(){
    // string str = "abcd";
    // auto result = findAllSubSeq(str);
    // for(auto &value : result){
    //     cout << value << endl;
    // }//end for 

    string text1 = "HelloWorld";
    string text2 = "lloAAAAl";
    cout << "lcs = " << lcs(text1 , text2) << endl;

    return 0;
}
