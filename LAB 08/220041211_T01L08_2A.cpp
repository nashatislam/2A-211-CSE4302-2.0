#include <iostream>
#include <string>

using namespace std;

class Person{
    protected:

        string name;

    public:

        Person(string a) : name(a)
        {}

        virtual void display() const{
            cout << "Name: " << name << endl;
        }
};

class Employee : public Person {
    private:

        int employeeID;

    protected:

        float salary;

    public:

        Employee(string a, int b, float c) : Person(a), employeeID(b), salary(c)
        {}

        void display() const{
            Person :: display();
            cout << "Employee ID: " << employeeID << endl;
            cout << "Salary: BDT " << salary << endl;
        }
};

class Intern : public Employee{
    private:

        string schoolName;

    public:

        Intern(string a, int b, float c, string d) : Employee(a, b, c), schoolName(d)
        {}

        void display() const{
            Employee::display();
            cout << "School Name: " << schoolName << endl;
        }
};

class Manager : protected Employee {
    private:

        string department;

    public:

        Manager(string a, int b, float c, string d) : Employee(a, b, c), department(d)
        {}

        void display() const{
            Person::display();
            cout << "Salary: BDT " << salary << endl;
            cout << "Department: " << department << endl;
        }
};

class Director : public Manager {
    private:

        float bonus;

    public:

        Director(string a, int b, float c, string d, float e) : Manager(a, b, c, d), bonus(e)
        {}

        void display() const{
            Manager::display();
            cout << "Bonus: BDT " << bonus << endl;
        }
};



int main(){
    Intern intern1("Nashat", 211, 5000.00, "IUT");
    Manager manager1("Samiha", 195, 25000.50, "Pharmacy");
    Director director1("Nilufar", 127, 80000.25, "Peace and Conflict Studies", 40000.125);

    cout << "Intern Info:" << endl;
    intern1.display();
    cout << endl;

    cout << "Manager Info:" << endl;
    manager1.display();
    cout << endl;

    cout << "Director Info:" << endl;
    director1.display();
    cout << endl;

    return 0;
}
