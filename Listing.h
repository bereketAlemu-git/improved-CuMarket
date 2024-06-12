#ifndef LISTING_H
#define LISTING_H

#include "Price.h"
#include "Category.h"
#include "defs.h"

using namespace std;
using namespace cat;

#include <iostream>
#include <string>

class Listing{
    private:
        string user;
        string title;
        string description;
        Category category;
        Price price;
        int numUser;

    public:
        Listing(const string& user, const string& title, Category& category, 
         const string& description,  Price price);
        bool lessThan(Listing& listing);
        void print()const;
        string getUser() const;
        string getTitle() const;
        string getDescription() const;
        Category getCategory() const;
        Price getPrice() const;
        void toString();
        friend ostream& operator<<(ostream& os, const Listing& listing);
    

};



#endif

