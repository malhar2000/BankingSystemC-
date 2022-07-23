//
//  BSTTree.cpp
//  Banking System
//
//  Created by Malhar Patel on 2022-07-20.
//

#include "BSTTree.hpp"
#include "BSTTreeNode.hpp"
using namespace std;
BSTTree::BSTTree()
:root{NULL}
{}

 

void BSTTree::createAccount(unsigned long long int accountNumber, long double balance, std::string name, std::string address, std::string password){
    
    
    std::ofstream fp{"accountData.txt", std::ios::app};
    
    
    BSTTreeNode *current = root;
    BSTTreeNode *previousCurrent;
    BSTTreeNode *temp = new BSTTreeNode(accountNumber, balance, name, address, password);
   
    if(root == NULL){
       
        root = temp;
        fp  <<name<<" "
            <<accountNumber << " "
            <<balance << " "
            <<address << " "
            <<password <<"\n";
        fp.close();
        return;
    }
    while(current != NULL){
        previousCurrent = current;
        if(current->accountNumber > accountNumber){
            current = current->left;
        }else if(current->accountNumber < accountNumber){
            current = current->right;
        }else{
            return;
        }
    }
     
    if(previousCurrent->accountNumber > accountNumber){
        previousCurrent->left = temp;
    }else{
        previousCurrent->right = temp;
    }
    fp  <<name<<" "
        <<accountNumber << " "
        <<balance << " "
        <<address << " "
        <<password << "\n";
    fp.close();
}

void BSTTree::Inorder(BSTTreeNode *p){
    if(p){
        Inorder(p->left);
        std::cout << p->balance << " " << p->name << std::endl;
        Inorder(p->right);
    }
}

BSTTreeNode * BSTTree::searchNode(unsigned long long accountNumber){
    BSTTreeNode *p = root;
    
    while(p != NULL){
        if(p->accountNumber == accountNumber){
            return p;
        }else if(p->accountNumber > accountNumber){
            p = p->left;
        }else{
            p = p->right;
        }
    }
    
    return NULL;
}

void BSTTree::withdraw(unsigned long long accountNumber, long double amount){
    
        BSTTreeNode *user = searchNode(accountNumber);
//    int seekPosition = 0;
        std::string file_name = to_string(accountNumber);
        file_name = file_name.append(".txt");
        
        std::ofstream fp{file_name, std::ios::app};
        time_t now = time(0);
        char* dt = ctime(&now);
        
        fp << dt << " You Withdrew -" << amount;
        fp.close();
        user->balance -= amount;
//            fp.seekg(seekPosition+2, ios::beg);
//            fp << user->name << " "
//            << user->accountNumber << " "
//            << user->balance << " "
//            << user->address << " "
//            << user->password;
//
//            fp.close();
            remove("accountData.txt");
            update_file(root);
            
            
//        seekPosition += (from_file.size()+1);
         
     }
    
void BSTTree::update_file(BSTTreeNode* temp){
    
    std::ofstream fp{"accountData.txt", std::ios::app};
    if(temp != NULL){
        
        update_file(temp->left);
        cout << temp->accountNumber << endl;
        fp  << temp->name << " "
            <<temp->accountNumber << " "
            << temp->balance << " "
            << temp->address << " "
            << temp->password << "\n";
        update_file(temp->right);
    }
    fp.close();
    
}

void BSTTree::load_file_data(){
    
    std::ifstream fp{"accountData.txt"};
    unsigned long long int accountNumber;
    std::string name;
    std::string address;
    std::string password;
    long double balance;
    
    BSTTreeNode *temp;
     
    while(!fp.eof()){
        fp >> name >> accountNumber >> balance >> address >> password;
         
        temp = new BSTTreeNode(accountNumber, balance, name, address, password);
        
        if(root == NULL){
            root = temp;
        }else{
            BSTTreeNode *previousCurrent;
            BSTTreeNode *current = root;
            while(current != NULL){
                previousCurrent = current;
                if(current->accountNumber > accountNumber){
                    current = current->left;
                }else if(current->accountNumber < accountNumber){
                    current = current->right;
                }else{
                    break;
                }
            }
            if(previousCurrent->accountNumber > accountNumber){
                previousCurrent->left = temp;
            }else{
                previousCurrent->right = temp;
            }
        }
    }
    fp.close();
}

bool BSTTree::transfer_money(unsigned long long int sender_accountNumber, unsigned long long int recevier_accountNumber, long double amount){
    BSTTreeNode *sender = searchNode(sender_accountNumber);
    BSTTreeNode *receiver = searchNode(recevier_accountNumber);
    std::string sender_file_name = to_string(sender_accountNumber);
    sender_file_name = sender_file_name.append(".txt");
    std::string receiver_file_name = to_string(recevier_accountNumber);
    receiver_file_name = receiver_file_name.append(".txt");
    std::ofstream fp_send{sender_file_name, std::ios::app};
    std::ofstream fp_rec{receiver_file_name, std::ios::app};
    
    time_t now = time(0);
    char* dt = ctime(&now);
    
    fp_send << dt << " You transfered " << amount << " to " << receiver->name << " account#: " << recevier_accountNumber << endl;
    fp_rec << dt << " You Received " << amount << " from " << sender->name << " account#: " << sender_accountNumber << endl;
    fp_send.close();
    fp_rec.close();
    sender->balance -= amount;
    receiver->balance += amount;
    
    remove("accountData.txt");
    update_file(root);
    
    return true;
    
}

bool BSTTree::deposite(unsigned long long int accountNumber, long double amount){
    BSTTreeNode *user = searchNode(accountNumber);
    std::string file_name = to_string(accountNumber);
    file_name = file_name.append(".txt");
    
    std::ofstream fp{file_name, std::ios::app};
    time_t now = time(0);
    char* dt = ctime(&now);
    
    fp << dt << " You deposited " << amount;
    user->balance += amount;
    fp.close();
    remove("accountData.txt");
    update_file(root);
    
    
    return true;
}
