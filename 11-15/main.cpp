#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "Shop.hpp"

int main() {
    // Name My Store
    Shop myStore("Josh's Clothing Emporium", 1.1);
    
    // Deliver Sellable Items
    myStore.getShipment(sellableItem("Jeans", 10, 20.00), false);
    myStore.getShipment(sellableItem("Red Shirt", 10, 5.00), false);
    myStore.getShipment(sellableItem("Blue Shirt", 8, 5.50), false);
    myStore.getShipment(sellableItem("Yellow Shirt", 100, 2.50), false);
    myStore.getShipment(sellableItem("Black Chinos", 15, 35.00), false);
    myStore.getShipment(sellableItem("Kahki Slacks", 15, 30.00), false);
    myStore.getShipment(sellableItem("White Dress Shirt", 10, 100.00), false);
    myStore.getShipment(sellableItem("Socks", 50, 1.75), false);
    
    std::string lineInput;
    int outer;
    do {
        std::cout << "This is " << myStore.storeName << ". What would you like to do?" << std::endl;
        std::cout << "1) Shop Items in the store." << std::endl;
        std::cout << "2) Check the price of an item." << std::endl;
        std::cout << "3) I'm a delivery guy, you've got an order." << std::endl;
        std::cout << "4) Quit." << std::endl; 
        std::cin >> outer;
        std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

        // Shop
        if (outer == 1) {
            do {
                myStore.printAllItems();
                std::cout << "What would you like to buy? [\"Quit\" to quit this menu]" << std::endl;
                std::getline(std::cin, lineInput);
                sellableItem item = myStore.purchaseItem(lineInput);
            } while (lineInput != "Quit") ;

        // Price Check
        } else if (outer == 2) {
            std::cout << "What item are you wanting to price?" << std::endl;
            std::cin.sync();
            std::getline(std::cin, lineInput);
            double price = myStore.getItemPrice(lineInput);
            if (price == 0) {
                std::cout << lineInput << " is not Listed." << std::endl;
            } else {
                std::cout << lineInput << " costs $" << price << '.' << std::endl;
            }
            
        // Restock
        } else if (outer == 3) {
            std::cout << "So, what did you bring to stock my store?" << std::endl;
            sellableItem newItem;
            std::getline(std::cin, newItem.itemName);
            std::cout << "How many of those are there?" << std::endl;
            std::cin >> newItem.storeStock;
            std::cout << "And what's the MSRP?" << std::endl;
            std::cin >> newItem. retailPrice;
            
            std::cout << "Great! I'll put that in the back." << std::endl;
            myStore.getShipment(newItem);
            
        // Quit
        } else if (outer == 4) {
            std::cout << "It's sad to see you go... " << std::endl;
            lineInput = "Quit";
            
        // Invalid
        } else {
            std::cout << "That's not a valid option. Try again." << std::endl;
        }
    } while (outer != 4);
    
    std::cout << "Have a great day!" << std::endl;
    return 0;
}
