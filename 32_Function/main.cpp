#include <iostream>

using namespace std;

const double pi{3.14159};

double calc_area_circle(double radius)
{
    return pi * radius * radius;
}

double calc_volume_cylinder(double radius, double height)
{
    // return pi * radius * radius * height;
    return calc_area_circle(radius) * height;
}

void area_circle()
{
    double radius{};
    cout << "\nEnter the radius of te circle ";
    cin >> radius;
    cout << "The area of the circle with radius " << radius << " is " << calc_area_circle(radius) << endl;
}

void volume_cylinder()
{
    double radius{};
    double height{};
    cout << "\nEnter the radius of the cylinder ";
    cin >> radius;
    cout << "\nEnter the height of the cylinder ";
    cin >> height;

    cout << "The volume of cylinder with radius " << radius << " and height " << height << " is " << calc_volume_cylinder(radius, height) << endl;
}

int main()
{

    area_circle();
    volume_cylinder();
}