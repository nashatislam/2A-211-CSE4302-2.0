#include <iostream>
using namespace std;

//enum fueltype { Petrol, Diesel, Electric, Hybrid };

struct specs {

    string brand;
    string model;
    int year;
    string fuel;
    float mileage;
    string buffer;
    
};


int main(void) {
    
    int i, n;
    specs carspecs;

    cout << "Number of cars: ";
    cin >> n;

    for(i=1; i<=n; i++){
        cout << "Car: " <<  i << endl;
        cout << "Brand: ";
        cin >>  carspecs.brand;
        cout << "Model: ";
        cin >> carspecs.model;
        cout <<  "Year: ";
        cin  >> carspecs.year;
        cout << "Fuel Type: ";
        cin >> carspecs.fuel;
        cout  << "Mileage: ";
        cin >> carspecs.mileage >>  carspecs.buffer;

        if(carspecs.fuel == "Electric"){
            cout << "This car is electric, efficiency measured in km/charge." << endl;
            if(carspecs.mileage > 15){
                cout << "This car is fuel-efficient." << endl;
            }
            else{
                cout << "This car is not fuel-efficient." << endl;
            }
        }
        else{
            if(carspecs.mileage > 15){
                cout << "This car is fuel-efficient."<< endl;
            }
            else{
                cout << "This car is not fuel-efficient."<< endl;
            }
            
            cout << "Estimated fuel cost for 100 km: $";
            if(carspecs.fuel == "Petrol"){
                cout << 100*0.89/carspecs.mileage << endl;
            }
            else if(carspecs.fuel == "Diesel"){
                cout << 100*3.24/carspecs.mileage << endl;
            }
            else{
                cout << 100*2.45/carspecs.mileage << endl;
            }
            
        }
            
        
    }
    

    return 0;
}