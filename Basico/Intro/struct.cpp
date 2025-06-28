#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#define MAX_ARRAY_SIZE 10
// struct Person {
//     char name[50]; 
//     int age;       
//     int array[MAX_ARRAY_SIZE]; // Array of integers with a maximum size
//     std::string address; 
// };

struct Point {
    int x; // X coordinate
    int y; // Y coordinate
    char label[20]; // Label for the point
};


void byValue(int a){
    a = a + 10;
}
void byReference(int& a){
    a = a + 10;
}
void byPointer(int* a){
    *a = *a + 10;
}
void distance(Point p1, Point p2){
    // Calculate the distance between two points
    double dist = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    std::cout << "Distance between points: " << dist << std::endl;
}
int main(){
    int a = 5; // Initialize an integer variable
    Point x1, x2;
    x1.x = 10;
    x1.y = 20;

    x2.x = 30;
    x2.y = 40;

    distance(x1, x2);

    byValue(a);
    std::cout << "Value of a after byValue: " << a << std::endl;

    byReference(a);
    std::cout << "Value of a after byReference: " << a << std::endl; 

    byPointer(&a);
    std::cout << "Value of a after byPointer: " << a << std::endl;

    return 0;
}