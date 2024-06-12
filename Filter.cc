#include "Filter.h"

//******************************************************************Filter*********************************************//



/// @brief check if the listing matches the filter
/// @param listing 
/// @return 
bool Filter::matches(const Listing& listing) const{
    return true;
}

/// @brief print the filter
/// @param ost 
void Filter::print(ostream& ost) const{
    ost << "Filter will select everything";
}



//***************************************************Price_Filter***********************************************************************************//



/// @brief constructor for the price filter
/// @param min,max
Price_Filter::Price_Filter(const Price& min, const Price& max) : 
min(min), max(max){}


/// @brief check if the price of the listing is in the range of the min and max price
/// @param listing 
/// @return 
bool Price_Filter::matches(const Listing& listing) const{
    cout<<" min: "<<min<<" ,max:  "<<max<<endl;
    return listing.getPrice().inRange(min, max);
}

/// @brief print the min and max price
/// @param ost 
void Price_Filter::print(ostream& ost) const{
    ost<<" min: "<<min<<" ,max:  "<<max;
}



//******************************************Cat_filter*********************************************************//


/// @brief  constructor for the category filter
/// @param category 
Cat_Filter::Cat_Filter(const Category& category) : 
category(category){}


/// @brief here we are checking if the category of the 
/// listing is equal to the category we are searching for
/// @param listing 
/// @return 
bool Cat_Filter::matches(const Listing& listing) const{
    return listing.getCategory() ==  category;
}


/// @brief print the category we are searching for
/// @param ost 
void Cat_Filter::print(ostream& ost) const{
    ost << category << "  =  "<< categoryToString(category);
}





//*************************************************PriceAndCat_Filter**********************************************************//





/// @brief constructor for the price and category filter
/// @param min,max,category
PriceAndCat_Filter::PriceAndCat_Filter(const Price& min, const Price& max, const Category& category) : 
Price_Filter(min, max), Cat_Filter(category) {}



/// @brief checking if the category of the product is equal to the category we are searching for
/// @param listing 
/// @return 
bool PriceAndCat_Filter::matches(const Listing& listing) const{
    return Price_Filter::matches(listing) && Cat_Filter::matches(listing);
}


/// @brief print the category and price we are searching for
/// @param ost 
void PriceAndCat_Filter::print(ostream& ost) const{
    ost << "Search by Category and Price: ";
    Price_Filter::print(ost);
    ost << ", ";
    Cat_Filter::print(ost);
}

/// @brief display the filter
/// @param ost,filter
/// @return 
ostream& operator<<(ostream& ost, const Filter& filter) {
    filter.print(ost);
    return ost;
}