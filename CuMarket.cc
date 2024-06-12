#include "CuMarket.h"
#include <iostream>

/// @brief Construct a new CuMarket:: CuMarket object
CuMarket::CuMarket() {}

/// @brief Destroy the CuMarket:: CuMarket object
CuMarket::~CuMarket() {
    for (int i = 0; i < listings.getSize(); ++i) {
        delete listings[i];
    }
}

/// @brief add a listing to the list
/// @param user, title, category, description, price
void CuMarket::addListing(const string& user, const string& title, Category category, 
const string& description, Price price) {
    if (listings.isFull()) {
        cout << "ERROR: CuMarket is full. Cannot add new listing." << endl;
        return;
    }
    Listing* newListing = new Listing(user, title, category, description, price);
    listings += newListing;
}

/// @brief remove a listing from the list
/// @param title 
void CuMarket::removeListing(const string& title) { 
    for (int i = 0; i < listings.getSize(); ++i) {
        if (listings[i]->getTitle() == title) {
            listings.remove(listings[i]);
            delete listings[i];
            return;
        }
    }
    cout << "Listing with Title not found to remove" << endl;  
    
}

/// @brief filter the listings based on the filter and add to searchList
/// @param filter, searchList 
/// @return void
void CuMarket::searchListings(const Filter& filter, List<Listing*>& searchList) {
    for (int i = 0; i < listings.getSize(); ++i) {
        if (filter.matches(*listings[i])) { 
            searchList += listings[i];
        }
    }
}