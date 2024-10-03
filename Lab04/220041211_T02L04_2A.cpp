#include <iostream>
#include <string>
using namespace std;

class BankAccount{
    private:
        int accountnumber;
        string holdername;
        string type;
        double current;
        const double min = 500;
        const double afterinterest = 1.027;

    public:
        void set(int a, string b, string c){
            accountnumber = a;
            holdername = b;
            type = c;
            current = min;
        }
        void showBalance(){
            cout << "Current balance of account no: " << accountnumber << " under the name " << holdername <<" is BDT: " << current << endl;
        }
        void deposit(double amount){
            if (amount > 0){
                current += amount;
                showBalance();
            }
            else{
                cout << "Invalid amount" << endl;
            }
        }
        void withdrawal(double amount){
            if(current - amount  >= min){
                current -= amount;
                showBalance();
            }
            else{
                cout << "Insufficient balance" << endl;
            }

        }
        void giveInterest(){
            current = current * afterinterest;
            cout << "Current balance of account no: " << accountnumber << " under the name " << holdername << " after interest is BDT: "<< current << endl;

        }
        ~BankAccount(){
        cout <<  "Account of " <<  holdername << " with account no: "<<  accountnumber << " is destroyed with a balance BDT: "<< current << endl;



        }



};

int main(void){
    { BankAccount acc1, acc2;

    acc1.set(22005, "Nashat", "Savings");
    acc2.set(21127, "Redita", "Savings");

    acc1.deposit(1200.50);
    acc1.withdrawal(500.00);
    acc1.giveInterest();

    acc2.withdrawal(400.00);
    acc2.deposit(8000.00);
    acc2.giveInterest();

    }

    return 0;
}