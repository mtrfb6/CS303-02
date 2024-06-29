#include "single_ll.h"

Linked::Linked() {
  cout << "Constructor called\n";
	headPtr = nullptr;
  tailPtr = nullptr;
  numItems = 0;
}

Linked::~Linked() {
   cout << "Destructor called\n";
  //Destructor will loop through the list and delete each node
  Node* tempPtr = headPtr;
  Node* delPtr = tempPtr;
  while (tempPtr != nullptr){
  tempPtr = tempPtr->nextPtr;
    delete delPtr;
    delPtr = tempPtr;
  }
  numItems = 0;
}

void Linked::push_front(int d){
  Node* newNode = new Node(d, headPtr);
  if (headPtr == nullptr){ //List is empty, head and tail are new node
    headPtr = newNode;
    tailPtr = newNode;
  }
  else{ //otherwise just set head to new node
    headPtr = newNode;
  }
  numItems++;
}

void Linked::push_back(int d){
  if (tailPtr != nullptr){
    tailPtr->nextPtr = new Node(d, nullptr);
    tailPtr = tailPtr->nextPtr;
    numItems++;

  }
  else{ //Empty list
    push_front(d);
  }
}

void Linked::pop_front(){
  if (headPtr == nullptr)
    throw invalid_argument("Pop called on empty list");
  
  Node* delnode = headPtr;
  headPtr = headPtr->nextPtr;
  if(tailPtr == headPtr)
    tailPtr = nullptr;
  delete delnode;
}

void Linked::pop_back(){
  if (headPtr == nullptr)
    throw invalid_argument("Pop called on empty list");
  
  Node* delnode = tailPtr;
  Node* current_node = headPtr;

  while (current_node != nullptr){ //Traverse to find the node before the tail and make that the new tail
    if (current_node->nextPtr == tailPtr){
      current_node->nextPtr = nullptr;
      tailPtr = current_node;
      break;
    }
    else{
      current_node = current_node->nextPtr;
    }
  }
  delete delnode;
  numItems--;
}

bool Linked::empty(){
  if (headPtr == nullptr)
    return 1;
  return 0;
}

void Linked::insert(int d, size_t idx){
  if (idx > numItems || idx < 0)
    throw out_of_range("Index for insert was outside list range");

  if (idx == 0){
    push_front(d);
    return;
  }
  else if (idx == numItems-1){
    push_back(d);
    return;
  }
  
  Node* prior_node = headPtr; //If we're inserting at an index, we need the node of the index prior

  for (int i = 0; i < idx-1; i++){
    prior_node = prior_node->nextPtr;
  }
  prior_node->nextPtr = new Node(d, prior_node->nextPtr);
  numItems++;
}

bool Linked::remove(size_t idx){
  if (idx > numItems || idx < 0)
    throw out_of_range("Index for remove was outside list range");

  if (idx == 0){
    pop_front();
    return;
  }
  else if (idx == numItems-1){
    pop_back();
    return;
  }

  Node* prior_node = headPtr; 

  for (int i = 0; i < idx-1; i++){
    prior_node = prior_node->nextPtr;
  }
  prior_node->nextPtr = prior_node->nextPtr->nextPtr;
  numItems--;
}

size_t Linked::find(int d){
  if (headPtr == nullptr)
    return numItems;
  
  Node* current_node = headPtr;
  for (int i = 0; i < numItems-1; i++){
    if (current_node->num == d)
      return i;
    current_node = current_node->nextPtr;
  }
  return numItems;
}