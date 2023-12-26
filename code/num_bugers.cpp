


#include <iostream>
#include <vector>

using namespace std;


vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    vector<int> result;

    int x = tomatoSlices - 2 * cheeseSlices;
    if(x < 0 || x % 2 != 0){
        return result;
    }else{
        x = x / 2;
    }

    int y = 4 * cheeseSlices -  tomatoSlices;
    if(y < 0 || y % 2 != 0){
        return result;
    }else{
        y = y / 2;
    }
    result.emplace_back(x);
    result.emplace_back(y);
    return result;
}


int main(){
    return 0;
}