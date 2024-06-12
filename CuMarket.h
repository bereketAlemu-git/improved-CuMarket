#ifndef CUMARKET_H
#define CUMARKET_H

#include <iostream>
#include "Listing.h" 
#include "defs.h"
#include "List.h"
#include "Filter.h"



class CuMarket {
    public:
        CuMarket();
        ~CuMarket();
        void addListing(const std::string& user, 
        const std::string& title, Category category, const std::string& description, Price price);
        void removeListing(const std::string& title) ;
        void searchListings(const Filter& filter, List<Listing*>& searchList);
        
    private:
        List<Listing*> listings;
};

#endif
