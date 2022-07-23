//
//  BSTTreeNode.cpp
//  Banking System
//
//  Created by Malhar Patel on 2022-07-20.
//

#include "BSTTreeNode.hpp"
 
BSTTreeNode::BSTTreeNode()
:BSTTreeNode(0, 0.0, "", "", "")
{}
 
BSTTreeNode::BSTTreeNode(unsigned long long int accountNumber, long double balance, std::string name, std::string address, std::string password)
: left{NULL}, right{NULL}, accountNumber{accountNumber}, balance{balance}, name{name}, address{address}, password{password}
{}

 
