


#include <iostream>

using namespace std;

class Bean{
private:
    int age;
public:
    void test() const{
        cout << "test begin" << endl;
        // age++;
        cout << "test end" << endl;
    }
    static void Haha(){
        cout << "haha" << endl;
    }
};

int main(){
    Bean bean;
    bean.test();
    Bean::Haha();
    return 0;
}