#include "Listing.h"
#include "Price.h"
#include "Category.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
using namespace cat;

/// @brief Construct a new Listing:: Listing object
/// @param user, title, category, description, price
Listing::Listing(const string& user, const string& title, Category& category, const string& description,
 Price price): 
 user(user), title(title), category(category), description(description), price(price) {}

/// @brief check if the title of the listing is less than the title of the listing passed in 
/// @param listing
/// @return bool
bool Listing::lessThan(Listing& listing){
    return (this->title < listing.title);
}

/// @brief print the listing
void Listing::print()const{
    cout << "User:        " << this->user << endl;
    cout << "Title:       " << this->title << endl;
    cout << "Category:    " << categoryToString(this->category) << endl;
    cout << "Description: " << this->description << endl;
    cout << "Price:       " << "$"<<fixed<<setprecision(2)<<this->price.getValue() <<endl;
}

/// @brief get the user of the listing
/// @return user
string Listing::getUser() const{
    return this->user;
}
/// @brief get the title of the listing
/// @return title
string Listing::getTitle() const{
    return this->title;
}

/// @brief get the description of the listing
/// @return description
string Listing::getDescription()const{
    return this->description;
}

/// @brief get the category of the listing
/// @return category
Category Listing::getCategory()const{
    return this->category;
}

/// @brief get the price of the listing
/// @return price
Price Listing::getPrice() const{
    return price;
}


ostream& operator<<(ostream& os, const Listing& listing){
    os << "User:        " << listing.user << endl;
    os << "Title:       " << listing.title << endl;
    os << "Category:    " << categoryToString(listing.category) << endl;
    os << "Description: " << listing.description << endl;
    os << "Price:       " <<fixed<<setprecision(2)<<listing.price <<endl;
    return os;
}


