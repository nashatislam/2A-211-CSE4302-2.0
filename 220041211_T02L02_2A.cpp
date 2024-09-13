#include <iostream>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };


int main(void) {
    
    char type;
    etype employee;

    cout << "Enter employee type (first letter only) laborer, secretary, manager, accountant, executive, researcher): ";
    cin >> type;

    switch(type){
        case 'l': employee = laborer;
        break;
        case 's': employee = secretary;
        break;
        case 'm': employee = manager;
        break;
        case 'a': employee = accountant;
        break;
        case 'e': employee = executive;
        break;
        case 'r': employee = researcher;
        break;
        
    }

    cout << "Employee type is ";
    switch(employee){
        case laborer: cout << "laborer." << endl;
        break;
        case secretary: cout << "secretary." << endl;
        break;
        case manager: cout << "manager." << endl;
        break;
        case accountant: cout << "accountant." << endl;
        break;
        case executive: cout << "executive." << endl;
        break;
        case researcher: cout << "researcher." << endl;
        break;
       
    }


    
      
    return 0;
}