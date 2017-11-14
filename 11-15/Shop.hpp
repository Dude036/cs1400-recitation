#ifndef CLASS_HPP
#define CLASS_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

const int PRINT_WIDTH_NAME = 20;
const int PRINT_WIDTH_STOCK = 8;
const int PRINT_WIDTH_PRICE = 2;


struct sellableItem {
    std::string itemName;
    int storeStock;
    double retailPrice;
    
    /**
     * Default Cosntructor
     */
    sellableItem() {
        itemName = "None";
        storeStock = 0;
        retailPrice = 0;
    }
    
    /**
     * Parametered Constructor
     * @param _iN Item Name
     * @param _sS Store Stock
     * @param _rP Retail Price
     */
    sellableItem(std::string _iN, int _sS, double _rP) {
        itemName = _iN;
        storeStock = _sS;
        retailPrice = _rP;
    }
};


class Shop {
// Public Data Members are accessable by all data members, and even accessable outside of the class.
  public:
    /**
     * Default Constructor
     * @param std::string Name of the store
     * @param double Profit Interest of your store.
     * @param double Initial store Value
     */
    Shop(std::string _sN, double _pI, double _sV = 0) {
        storeName = _sN;
        priceInterest = _pI;
        storeVault = _sV;
    };
    
    /**
     * Destructor
     * Note: This simple clears all items in the store's inventory
     */
    ~Shop(){
        std::cout << std::endl << "It was a good run. We made " << std::fixed
            << std::setprecision(PRINT_WIDTH_PRICE) << storeVault << std::endl;
        itemsInStock.clear();
    }
    
    /**
     * Prints all of the items for sale in the store
     */
    void printAllItems() {
        std::cout << "Welcome to " << storeName << "!" << std::endl;
        std::cout << std::left << std::setw(PRINT_WIDTH_NAME) << "Name"
            << std::setw(PRINT_WIDTH_STOCK) << "Stock"
            << std::setw(PRINT_WIDTH_PRICE) << "Price" << std::endl; 
        for (unsigned int i = 0; i < itemsInStock.size(); i++) {
            std::cout << std::left << std::setw(PRINT_WIDTH_NAME) 
                << itemsInStock[i].itemName << std::setw(PRINT_WIDTH_STOCK)
                << itemsInStock[i].storeStock << std::fixed
                << std::setprecision(PRINT_WIDTH_PRICE) << "$"
                << itemsInStock[i].retailPrice * priceInterest << std::endl;
        }
    }
    
    /**
     * Item cost when purchasing.
     * @param std::string What item to search for
     * @return Price of the item, including interest
     */
    double getItemPrice(std::string name) {
        sellableItem item = searchTheBack(name);
        return item.retailPrice * priceInterest;
    }
    
    /**
     * Purchase an item from the store
     * @param std::string Name of the item being bought
     * @return Item being bought
     */
    sellableItem purchaseItem(std::string name) {
        sellableItem item = searchTheBack(name);
        if (!inStock(item)) {
            std::cout << "Sorry, we're out of " << item.itemName << "." << std::endl;
            return sellableItem();
        } else {
            storeVault += item.retailPrice * priceInterest;
            item.storeStock--;
            takeItemToBack(item);
            
            item.retailPrice *= priceInterest;
            item.storeStock = 1;
            std::cout << "Thank you for shopping at " << storeName << "!" << std::endl;
            std::cout << "Here are your " << item.itemName << ". Have a nice day" << std::endl;
            return item;
        }
    }
    
    /**
     * Checks if the item is in the store or not
     * @param std::string Name of the Item
     * @return true if the item has at least 1, false otherwise
     */
    bool inStock(std::string name) {
        return inStock(searchTheBack(name));
    }
    
    /**
     * add an item to the inventory. Will increase stock and price if the item
     * is already in the store's inventory
     * @param sellableItem Item being added to the inventory
     */
    void getShipment(sellableItem delivery) {
        int i = getShelfNumber(delivery);
        if (i < 0) {
            // Item isn't in the data base.
            itemsInStock.push_back(delivery);
        } else {
            itemsInStock[i].storeStock += delivery.storeStock;
            itemsInStock[i].retailPrice = delivery.retailPrice;
        }
        std::cout << "Item added to inventory." << std::endl;
    }
    
    std::string storeName;
    
// Private Data Members are only accessible to the class functions.
  private:
    double priceInterest;
    double storeVault;
    std::vector<sellableItem> itemsInStock;
    
    /**
     * Checks if the item is in the store or not
     * @param name of the Item
     * @return true if the item has at least 1, false otherwise
     */
    bool inStock(sellableItem item) {
        return item.storeStock > 0;
    }
    
    /**
     * Searches the stock for the available Item
     * @param Name of the item
     * @return Sellable item instance
     */
    sellableItem searchTheBack(std::string name) {
        // Search the itemsInStock
        for (unsigned int i = 0; i < itemsInStock.size(); ++i) {
            if (itemsInStock[i].itemName == name) {
                // found the item
                return itemsInStock[i];
            }
        }
        
        // Didn't find the item
        return sellableItem();
    }
    
    /**
     * Gets the place in the vector for that item
     * @param sellableItem 
     * @return Index in itemsInStock Vector
     */
    int getShelfNumber(sellableItem item) {
        int i;
        for (i = 0; i < (int) itemsInStock.size(); ++i) {
            if (itemsInStock[i].itemName == item.itemName) {
                return i;
            }
        }
        // Not Found
        return -1;
    }
    
    /**
     * Updates information in the system for stock of item
     * @param sellableItem Purchased item
     */
    void takeItemToBack(sellableItem item) {
        int i = getShelfNumber(item);
        if (i >= 0) {
            itemsInStock[i].storeStock = item.storeStock;
        }
    }
};

#endif  // CLASS_HPP
