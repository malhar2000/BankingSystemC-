//
//  BSTTreeNode.hpp
//  Banking System
//
//  Created by Malhar Patel on 2022-07-20.
//

#ifndef BSTTreeNode_hpp
#define BSTTreeNode_hpp
 
 
#include <stdio.h>
#include <string>
class BSTTreeNode{
    
public:
    BSTTreeNode *left;
    BSTTreeNode *right;
    unsigned long long int accountNumber;
    long double balance;
    std::string name;
    std::string address;
    std::string password;
    
    BSTTreeNode();
    BSTTreeNode(unsigned long long int accountNumber, long double balance, std::string name, std::string address, std::string password);
};

 
#endif /* BSTTreeNode_hpp */
