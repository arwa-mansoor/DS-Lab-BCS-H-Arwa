#include <iostream>
using namespace std;

class BankAccount{
    private:
        float balance;

    public:
        BankAccount(){
            balance = 0.0;
        }
        BankAccount(float balance) : balance(balance){}

        void printBalance(){
            cout << "Current Balance is $" << balance << endl;
        }
        void withdraw(float amount){
            balance -= amount;
        }
};

int main(){
    BankAccount account1;
    cout << "Account 1\n";
    account1.printBalance();

    cout << "Account 2\n";
    BankAccount account2(1000);
    account2.printBalance();

    cout << "Account 3\n";
    BankAccount account3(account2);
    account3.withdraw(200);
    account3.printBalance();

    cout << "Account 2\n";
    account2.printBalance();
}
