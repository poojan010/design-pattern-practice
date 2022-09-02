#include <iostream>
using namespace  std;

class DebitCard {
    public:
        void doTransaction(long amount){
            cout << "Paying using debit card";
        }
};
class CreditCard {
    public:
        void doTransaction(long amount){
            cout << "Paying using credit card";
        }
};

class ShopingMall{
    private:
        DebitCard debitCard;
    public:
        ShopingMall(DebitCard debitCard){
            this->debitCard = debitCard;
        }

        void purchaseSomething(long amount){
            debitCard.doTransaction(amount);
        }
};

int main(){
    DebitCard d;
    ShopingMall *s = new ShopingMall(d);
    s->purchaseSomething(100);
}


// problem here is that ShopingMall (High level module)
// depends directly on Debit Card (Low level module)
// What if i need to use Credit card
// then i have to change whole ShopingMall class
// that is why high level module should not depend directly on low level module
// instead it should depend on abstraction or interface

// Solution

class BankCard{
    public:
        virtual ~BankCard() = default;
        virtual void doTransaction(long amount) = 0;
};

class DebitCard : public BankCard{
    public:
        void doTransaction(long amount){
            cout << "Paying using debit card";
        }
};
class CreditCard : public BankCard {
    public:
        void doTransaction(long amount){
            cout << "Paying using credit card";
        }
};

class ShopingMall{
    private:
        BankCard &bankCard_;
    public:
        ShopingMall(BankCard &bankCard) : bankCard_{bankCard} {}

        void purchaseSomething(long amount){
            bankCard_.doTransaction(amount);
        }
};

int main(){
    DebitCard d;
    CreditCard c;
    ShopingMall *s = new ShopingMall(c);
    // now we can use any card from credit and debit ar run time
    s->purchaseSomething(100);
}
