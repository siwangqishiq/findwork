#include <iostream>
#include <vector>
#include <map>

using namespace std;

void test(){

}

int numSquare(int n){
    map<int , int> sqMap;
    test();

    for(int i = 1 ; i <= n; i++){
        const int squareValue = i * i;
        if(squareValue > n){
            break;
        }
        
        sqMap[squareValue] = i;
    }//end for each

    int minCount = 0;

    int value = n;
    while(value != 0){
        
    }//end while

    return minCount;
}

int main(){
    cout << numSquare(9) << endl;
    while(1){

    }

    test();
    return 0;
}

//decompose
//eigen特征

