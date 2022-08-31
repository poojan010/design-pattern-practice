#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;

class Singleton{
    private:
        static Singleton* instance;
        Singleton(){};  // so user can not instantiate directly 
    public:
        static Singleton* getInstance();
};

Singleton* Singleton::getInstance(){
    if(instance == NULL){
        instance = new Singleton();
    }
    return instance;
}

Singleton* Singleton::instance = NULL;

int main() {
    Singleton *obj = Singleton::getInstance();
    cout << "Hello World!\n";
}


/** 
    NOT THREAD SAFE
    In the above code, the getInstance() method is not thread-safe. 
    Multiple threads can access it at the same time. For the first few threads when the instance variable is not initialized, multiple threads can enter the if loop and create multiple instances. It will break our singleton implementation.
*/
