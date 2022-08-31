
/** Solution 1 */

Singleton* Singleton::getInstance(){
    // Lock Mutex
    if(instance == NULL){
        instance = new Singleton();
    }
    // Unlock Mutex
    return instance;
}

/**
    Cons 
    Performance is not good
*/




/** Solution 2 */

Singleton* Singleton::getInstance(){
    if(instance == NULL){
        instance = new Singleton();
    }
    return instance;
}

int main(){
    // instantiare at start
    Singleton *obj = Singleton::getInstance();
    // instance == NULL will never call after this

    /** 
        rest of your code 
        for starting threads
    */

    return 0;
}

/**
    Cons 
    Lazy instantiation is not there.
    Lazy instantiation -> create object only when needed
*/



/** Solution 3 */
// check even before locking mutex
Singleton* Singleton::getInstance(){
   if(instance == NULL)){
        // Lock Mutex
        if(instance == NULL){
            instance = new Singleton();
        }
        // Unlock Mutex
    }
    return instance;
}

