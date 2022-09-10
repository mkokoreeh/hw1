#include <iostream>
#include "split.h"
using namespace std;

int main(int argc, char *argv[]){
    //int num;
    //int val;
    //cout<<"In Main"<<endl;
    Node *evens = nullptr;
    Node *odds = nullptr;
    
    Node *g= new Node(7, nullptr);
    Node *f= new Node(6, g);
    Node *e= new Node(5, f);
    Node *d= new Node(4, e);
    Node *c= new Node(3, d);
    Node *b= new Node(2, c);
    Node *a= new Node(1, b);
    Node* ptr=a;
    //cout << "hi" << endl;
    split(ptr, odds, evens);
    cout << "Odds: ";
    while(odds!=nullptr){
        cout << odds->value << ", ";
        odds=odds->next;
    }
    cout << endl << "Evens: ";
    while(evens!=nullptr){
        cout << evens->value << ", ";
        evens=evens->next;
    }
    if(ptr==nullptr){ //to make sure og list is gone
        cout << endl << "In: Gone, Reduced to Ashes" << endl;
    }
    //deletion for memleaks
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;
    delete g;
    return 0;
}