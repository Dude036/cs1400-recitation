#include <iostream>
#include <string>
#include <vector>

#include "Shop.hpp"

int main() {
    Shop myStore("Josh's Clothing Emporium", 1.1);
    myStore.getShipment(sellableItem("Jeans", 10, 20.00));
    myStore.printAllItems();
    
    myStore.purchaseItem("Jeans");
    myStore.purchaseItem("Jeans");
    myStore.purchaseItem("Jeans");
    
    myStore.printAllItems();
    myStore.getShipment(sellableItem("Jeans", 100, 15.00));
    myStore.printAllItems();
    
    return 0;
}
