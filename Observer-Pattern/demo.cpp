#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ISubscriber{
    public:
        virtual void notify(string) = 0;
};

class User : public ISubscriber{
    private:
        int userId;
    public:
        User(int userId){
            this->userId = userId;
        }
        void notify(string msg){
            cout << "User " << userId << " got the message " << msg << endl;
        }
};

class Group{
    private:
        list<ISubscriber*> users;
    public:
        void subscribe(ISubscriber* user){
            users.push_back(user);
        }
        void unsubscribe(ISubscriber* user){
            users.remove(user);
        }
        void notify(string msg){
            for(auto user : users){
                user->notify(msg);
            }
        }
};

int main() {
    Group *group = new Group();

    User* u1 = new User(1);
    User* u2 = new User(2);
    User* u3 = new User(3);

    group->subscribe(u1);
    group->subscribe(u2);
    group->subscribe(u3);
    
    group->notify("New Message");

    group->unsubscribe(u2);

    group->notify("New Message");

    return 0;
}