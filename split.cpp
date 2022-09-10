/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  
  if(in==nullptr){
    return;
  }
  else if((in->value%2)==0){
    Node* temp=in->next;
    evens=in;
    (evens->next)=nullptr;//delete the pointer to the next node in the original list
    in=nullptr; //have to delete the original list
    split(temp, odds, evens->next); //recursive call, use next for OG list and the next for even
  }
  else if((in->value%2)==1){
    Node* temp=in->next;
    odds=in;
    odds->next = nullptr; //delete the pointer to the next node in the original list
    in=nullptr; //delete original list
    split(temp, odds->next, evens);  //recursive call
  }
  in=nullptr;//final code to delete og list
  return;
}

/* If you needed a helper function, write it here */
/*void helper(Node* odds, Node* evens){
  if((
}*/
// WRITE YOUR CODE HERE