#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Price.h"
using namespace std;

/// @brief constructor for price
/// @param value 
Price::Price(double value){
    this->value = value;
}

/// @brief empty constructor
Price::Price(){
    this->value = 0.0;
}

/// @brief check if the price is less than the price passed in
/// @param p 
/// @return bool
bool Price::operator<(const Price& p)const{
    cout<<"Price::operator< called"<<endl;
    if(this->value < p.value) return true;
    return false;
    //return ;
}

/// @brief check if the price is equal the price passed in
/// @param p 
/// @return 
bool Price::operator==(const Price& p)const{
    cout<<"Price::operator= called"<<endl;  
    cout<<"this->value: "<<this->value<<endl;
    cout<<"p.value: "<<p.value<<endl;
    if(this->value == p.value)return true;
    return false;
    //return (this->value == p.value);
}
/// @brief checks if the price is greater than the price passed in
/// @param min,max 
/// @return 
bool Price::inRange(const Price& min, const Price& max){
    cout<<"Price::inRange called"<<endl;
    cout<<min<< "   "<< max<<endl;
    if(this->value >= min.value && this->value <= max.value) return true; 
    return false;
}

/// @brief prints the price
void Price::print()const{
    
    cout<<"$"<<fixed<<setprecision(2)<<this->getValue()<<endl;
}

/// @brief “print” the Price on the given ostream
/// @param os,price 
/// @return 
ostream& operator<<(ostream& os, const Price &price) {
    os << "$" << fixed << setprecision(2) << price.value;
    return os;
}
/// @brief "read" the Price from the given istream
/// @param is, price 
/// @return 
istream& operator>>(istream& is, const Price& price) {
    is >> price.getValue();
    return is;
}