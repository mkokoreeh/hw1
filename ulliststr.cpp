#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val){
  if(empty() == true){ //if empty, initialize a new node to hold the new value
    Item* node = new Item;
    node->first = 0; 
    node->last = 0; 
    head_ = node;
    tail_ = node;
    //Initialize first and last, avoids seg faults and such
    head_->first = ARRSIZE; 
    head_->last = ARRSIZE;
    tail_->first = ARRSIZE;
    tail_->last = ARRSIZE;
  }
  if(tail_->last == ARRSIZE){//if the final node is full, make a new array to hold the new value at the front
		Item* temp = new Item;
    temp->prev = tail_; //old tail node is now placed before the new tail node
    tail_->next = temp;
		tail_ = temp; // tail node is now the new array with the new value
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
	else{ //if there is space in the array, add the value normally
	  tail_->val[tail_->last] = val;
		tail_->last++;
	}
  size_++; //increment size because... duh
  return;
}

void ULListStr::push_front(const std::string& val){
  if(empty() == true){ //same, start the list if there is no list yet initialize first/last
		Item* node = new Item;
		head_ = node;
    tail_ = node; 
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
    tail_->first = ARRSIZE;
    tail_->last = ARRSIZE;
	}
	else if(head_->first == 0){//if there is no space in the front, make a new array and plop the value in the back of new
		Item* temp = new Item;
		temp->next = head_;
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
		head_->prev = temp;
		head_ = temp;
	}
	head_->first--;
  head_->val[head_->first] = val;
  size_++;
	return;
}
void ULListStr::pop_back(){
	if(empty() == false){//normal case, if not empty, decrement everything
    tail_->last--;
    size_--;
  }
  else{//if there's no list, just return nothing
    return;
  }
  if(tail_->last == tail_->first){//checking if there is nothing in the tail after decrementing
    Item *temp = tail_->prev;
    // make tail point to the previous thing
    tail_ = temp;
    tail_->prev = temp->prev;

  }
  return;
}

void ULListStr::pop_front(){
  if(empty() == false){ // if not empty decrement as normal
    head_->first++;
    size_--;
  }
  else{
    return;
  }
  if(head_->first == head_->last){ // if there is no spot in the current array, make a new one
    Item *temp = head_->next;
    head_=temp;
    head_->next = temp->next;

  }
  return;
}
std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}
std::string const & ULListStr::front() const
{
	return head_->val[head_->first];
}
std::string* ULListStr::getValAtLoc(size_t loc) const
{
	Item* temp = head_;
  size_t update=loc; //a new variable for loc for updating and a better naming convention
  size_t totalSpots = 0;
  if((size_ == 1)&&(loc == 0)){ //special case for when size is exactly 1
    return &head_->val[head_->first];
  }
  //Checks if loc is in an array, if so return, if not move on to next array
  while(temp!=NULL){
    totalSpots=temp->last - temp->first;
		if(update<totalSpots){   //loc is in the array if it is within the TotalSpots interval
      
      // need to return the reference to the desired value
      return &temp->val[temp->first+update];
    }
    else{ //if loc is not in this array, move to the next one and update the checking varaiable
		  temp = temp->next;
      update = update-totalSpots;
    }
	}
  // returns null the location is never found
  return nullptr;
}
void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
