#include<iostream>
#include"rectangle_utils.h"

int main(){

    double length, width;

    std::cout<<"Enter the length and width of the rectangle\n";
    std::cin>>length>>width;

    std::cout<<"The area is : "<<calculateArea(length,width)<<"\n";
    std::cout<<"The perimeter is : "<<calculatePerimeter(length,width);

    return 0;

}
