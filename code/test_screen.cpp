

#include <iostream>

const int SCR_WIDTH = 80;

void printLine(){
    for(int i = 0 ; i < SCR_WIDTH;i++){
        std::cout << "*";
    }
    std::cout<< std::endl;
}


int main(){
    while(true){
        for(int i = 0 ; i < 10;i++){
            printLine();
        }
        system("cls");
    }//end while

    return 0;
}