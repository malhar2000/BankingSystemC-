//
//  main.cpp
//  Banking System
//
//  Created by Malhar Patel on 2022-07-20.
//

#include <iostream>
#include "BSTTree.hpp"
#include "BSTTreeNode.hpp"

int main(int argc, const char * argv[]) {
    BSTTree t;
    
    t.load_file_data();
    
 
    
    t.transfer_money(111120, 111119, 100);
    t.transfer_money(111120, 111119, 100);
    t.deposite(111120, 10000);

    return 0;
}
