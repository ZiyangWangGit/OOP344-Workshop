/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP345

* Date:Mar 15,2024

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/
#include "list.h"
#include "element.h"
#include "utilities.h"

using namespace std;

namespace seneca {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointer
        for (size_t i = 0; i < desc.size(); ++i) {
            for (size_t j = 0; j < price.size(); ++j) {
                if (desc[i].code == price[j].code) {
                    Product* product = new Product(desc[i].desc, price[j].price);
                    try {
                        product->validate();
                    }
                    catch(const std::string& msg){
                        delete product;
                        throw std::string ("*** Negative prices are invalid ***");
                    }
                    priceList += product;
                    delete product;
                }
            }
        }
        return priceList;
    }

    List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
        List<Product> priceList;
        // TODO: Add your code here to build a list of products
        //         using smart pointers
        for (size_t i = 0; i < desc.size(); ++i) {
            for (size_t j = 0; j < price.size(); ++j) {
                if (desc[i].code == price[j].code) {
                    std::unique_ptr<Product> product(new Product(desc[i].desc, price[j].price));
                    try {
                        product->validate();
                    }
                    catch (const std::string& msg) {
                        throw std::string("*** Negative prices are invalid ***");
                    }
                    priceList += product;
                }
            }
        }
        return priceList;
    }
}