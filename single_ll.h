#pragma once
#include <iostream>
#include <string>
#include "node.h"
using namespace std;

class Linked {
protected:
  Node* headPtr;
  Node* tailPtr;
  int numItems;

public:
  Linked();
  ~Linked(); // destructor

  void push_front(int d);
  void push_back(int d);
  void pop_front();
  void pop_back();

  int front(){return headPtr->num;}
  int back(){return tailPtr->num;}

  bool empty();

  void insert(int d, size_t idx);
  bool remove(size_t idx);

  size_t find(int d);
};