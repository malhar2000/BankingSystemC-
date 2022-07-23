//
//  BSTTree.hpp
//  Banking System
//
//  Created by Malhar Patel on 2022-07-20.
//

#ifndef BSTTree_hpp
#define BSTTree_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <string.h>
#include <fstream>
#include <ctime>
#include <sstream>
#include "BSTTreeNode.hpp"

class BSTTree{
    
    
public:
 
    BSTTreeNode  *root = NULL;
    std::vector<BSTTreeNode*> allNodes;
    
    BSTTree();
    void createAccount(unsigned long long int accountNumber, long double balance, std::string name, std::string address, std::string password);
    void Inorder(BSTTreeNode *root);
    
    BSTTreeNode* searchNode(unsigned long long int accountNumber);
    
    void withdraw(unsigned long long int accountNumber, long double amount);
    
    void update_file(BSTTreeNode *root);
    
    void load_file_data();
    
    bool transfer_money(unsigned long long int sender_accountNumber, unsigned long long int recevier_accountNumber, long double amount);
    
    bool deposite(unsigned long long int accountNumber, long double amount);
};

#endif /* BSTTree_hpp */
