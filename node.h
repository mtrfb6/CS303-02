
struct Node {
  int num;
  Node *nextPtr;

  Node() : num(0), nextPtr(nullptr){}
  Node(const int& dat, Node* next = nullptr) : num(dat), nextPtr(next) {}
};
