#ifndef FILTER_H
#define FILTER_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Category.h"
#include "Price.h"
#include "Listing.h"


using namespace std;
using namespace cat;

class Filter{
    friend ostream& operator<<(ostream& ost, const Filter& filter);
    public:
        virtual bool matches(const Listing& listing) const;
        virtual void print(ostream& ost) const;
        virtual ~Filter(){}   

};


 
class Price_Filter: virtual public Filter{
    public:
        Price_Filter(const Price& min, const Price& max);
        bool matches(const Listing& listing) const override;
        void print(ostream& ost) const override;
    private: 
        Price min;
        Price max;
};


class Cat_Filter: virtual public Filter{
    public:
        Cat_Filter(const Category& category);
        bool matches(const Listing& listing) const override;
        void print(ostream& ost) const override;
    private:
        Category category;

};

class PriceAndCat_Filter: public Price_Filter, public Cat_Filter{
    public:       
        PriceAndCat_Filter(const Price& min, const Price& max, const Category& c); 
        bool matches(const Listing& l) const override;
        void print(ostream& ost) const override;

};




#endif