#ifndef PRICE_H
#define PRICE_H

#include <iostream>
#include <string>
#include <sstream>

#include "defs.h"

using namespace std;



class Price {
	
		
	public:
		//constructor
		Price(double value);
		Price();

		bool operator<(const Price& p)const;
		bool operator==(const Price& p)const;	
		//bool operator>=(const Price& p)const;

		bool inRange(const Price& min, const Price& max);
		
		void print() const;

		double getValue()const{
        	return value;
    	}
		void setValue(double newValue) {
    		value = newValue;
		}
		
    friend ostream& operator<<(ostream& os, const Price& price);

   
    friend istream& operator>>(istream& is, const Price& price);
	
	private:
		double value;
	
};
#endif