#include <iostream>
#include <string>
using namespace std;

class product{
    private:
        string name;
        int id;
        double price;
        int quantity;
        int capacity;
    public:
        void set(string a, int b, double c, int d, int e){
            name = a;
            id = b;
            price = c;
            quantity = d;
            capacity = e;
        }
        void addToInventory(int addedquantity){
            if((addedquantity + quantity) > capacity){
                cout <<  "Overflow !!!" << endl;
            }
            else{
                quantity += addedquantity;
                cout  << "Added " << addedquantity << " to the inventory of " << name << endl;

            }
        }
        int isAvailable(){
            if(quantity > 0){
                return 1;
            }
            return 0;
        }
        void purchase(int purchasedQuantity){
            if(quantity >= purchasedQuantity){
                quantity -= purchasedQuantity;
                cout << "Purchased " << purchasedQuantity << " of " << name << endl;
            }
            else{
                cout << "Not enough quantity in the inventory" << endl;
            }

        }
        void updatePrice(int percentage){
            if(percentage >= 0 &&  percentage <= 100){
                price = (double)(price - (price * (percentage / 100.00)));
                cout << "Updated price of "<< name << " to " << price << endl;
            }
            else{
                cout  << "Invalid percentage" << endl;

            }
        }
        double displayInventoryValue(){
            return  price * quantity;
        }
        void  displayProductDetails(){
            cout  << "Product Name: " << name << endl;
            cout  << "Product ID: " << id << endl;
            cout  << "Product Price: " << price << endl;
            cout  <<  "Product Quantity: " << quantity << endl;
            if(isAvailable()){
                cout << "Product is available" << endl;
            }
            else{
                cout << "Product is not available" << endl;
            }
            cout << "\n";
        }

};    

int main(void){
    product product1, product2, product3;

    product1.set("Notebook", 11, 9.99, 50, 200);
    product1.addToInventory(100);
    product1.purchase(5);
    product1.updatePrice(5);
    product1.displayInventoryValue();
    product1.displayProductDetails();

    product2.set("Pencil", 36, 1.99, 200, 500);
    product2.displayProductDetails();
    product3.set("Eraser", 54, 2.49, 150, 500);
    product3.displayProductDetails();

    cout << "Total Inventory Value:  " << product1.displayInventoryValue() + product2.displayInventoryValue() + product3.displayInventoryValue() <<endl;
   
    return 0;
}