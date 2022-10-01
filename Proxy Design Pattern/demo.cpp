#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class IInternet{
    public:
        virtual void connectTo(string) = 0;
};

class RealInternet : public IInternet{
    public:
        void connectTo(string hostName){
            cout << "Connecting to "  << hostName << endl;
        }
}; 

class ProxyInternet : public IInternet{
    private:
        RealInternet* internet = new RealInternet();
        static unordered_set<string> bannedSites;
    
    public:
        void connectTo(string hostName){
            if(bannedSites.find(hostName) != bannedSites.end()){
                cout << "Access Denied for " << hostName << endl;
                return;
            }
            internet->connectTo(hostName);
        }
};

unordered_set<string> ProxyInternet::bannedSites = { "xyz.com" };

int main() {

    ProxyInternet* pInternet = new ProxyInternet();

    pInternet->connectTo("google.com");

    pInternet->connectTo("xyz.com");
    
    return 0;
}


