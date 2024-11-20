#include <iostream>
#include <string>
#include <cmath>

#define pi 3.1416

using namespace std;



class Shape{
    public:

        virtual void whoAmI() const = 0;
};

class TwoDimensionalShape : public Shape{
    public:

        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        void whoAmI() const = 0;

};

class ThreeDimensionalShape : public Shape{
    public:

        virtual double surfaceArea() const = 0;
        virtual double volume() const = 0;
        void whoAmI() const = 0;


};

class Square : public TwoDimensionalShape{
    private:

        double sidelength;

    public:

        Square(double s) : sidelength(s)
        {}

        double area() const{
            return sidelength * sidelength;
        }

        double perimeter() const{
            return 4 * sidelength;
        }

        void whoAmI() const{
            cout << "I am a Square. I am a two-dimensional shape." << endl;
        }
};

class Circle : public TwoDimensionalShape{
    private:

        double radius;

    public:

        Circle(double r) : radius(r)
        {}

        double area() const{
            return pi * radius * radius;
        }

        double perimeter() const{
            return 2 * pi * radius;
        }

        void whoAmI() const{
            cout << "I am a Circle. I am a two-dimensional shape." << endl;
        }
};

class Cube : public ThreeDimensionalShape {
    private:

        double sidelength;

    public:

        Cube(double s) : sidelength(s) {}

        double surfaceArea() const{
            return 6 * sidelength * sidelength;
        }

        double volume() const{
            return sidelength * sidelength * sidelength;
        }

        void whoAmI() const{
            cout << "I am a Cube. I am a three-dimensional shape." << endl;
        }
};

class Sphere : public ThreeDimensionalShape{
private:

    double radius;

public:
    Sphere(double r) : radius(r)
    {}

    double surfaceArea() const{
        return 4 * pi * radius * radius;
    }

    double volume() const{
        return (4.0 / 3.0) * pi * pow(radius, 3);
    }

    void whoAmI() const{
        cout << "I am a Sphere. I am a three-dimensional shape." << endl;
    }
};


int main() {

    Square square(3);
    square.whoAmI();
    cout << "Area: " << square.area() << endl;
    cout << "Perimeter: " << square.perimeter() << endl;
    cout << endl;

    Circle circle(4);
    circle.whoAmI();
    cout << "Area: " << circle.area() << endl;
    cout << "Perimeter (Circumference): " << circle.perimeter() << endl;
    cout << endl;


    Cube cube(5);
    cube.whoAmI();
    cout << "Surface Area: " << cube.surfaceArea() << endl;
    cout << "Volume: " << cube.volume() << endl;
    cout << endl;

    Sphere sphere(2);
    sphere.whoAmI();
    cout << "Surface Area: " << sphere.surfaceArea() << endl;
    cout << "Volume: " << sphere.volume() << endl;
    cout << endl;

    return 0;
}


