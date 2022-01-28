#include <iostream>
#include <string>

using namespace std;

struct Node {
  int value;
  Node *next;
};

class SimpleList {
  private:
    Node *head;

    Node *_getTail(Node *p) {
      if(!p) return NULL;

      if(p->next) {
        return _getTail(p->next);
      } else {
        return p;
      }
    }

    int _find(Node *p, int pos, int value) { 
      if (!p) return -1;

      if(p->value ==  value) {
        return pos;
      } else {
        return _find(p->next, pos + 1, value);
      }
    }


  public: 
    SimpleList();
    Node *getTail();
    void insertAtStart(int value);
    void insertAtEnd(int value);
    void remove(int value);
    bool isEmpty();
    int find(int value);
    string toString();
};

SimpleList::SimpleList() {
  head = NULL;
}

Node *SimpleList::getTail() {
  return _getTail(head);
}

void SimpleList::insertAtStart(int value) {
  Node *newNode = new Node;
  newNode->value = value;
  newNode->next = NULL;
  
  if(!head) {
    head = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }
}

void SimpleList::insertAtEnd(int value) {
  Node *newNode = new Node;
  newNode->value = value;
  newNode->next = NULL;

  Node *tail = getTail();

  if(!head) {
    head = newNode;
  } else {
    tail->next = newNode;
  }
}

bool SimpleList::isEmpty() {
  return head == NULL;
}

string SimpleList::toString() {
  Node *n = head;
  string result = "Data [";

  if(n) {
    while (n) {
      result = result + " -> " + to_string(n->value);
      n = n->next;
    }
  }

  result = result + " ]";
  return result;
}

int SimpleList::find(int value) {
  return _find(head, 0, value);
}

void SimpleList::remove(int value) {
  Node *n = head;

  if(!n) return;

  while(n->next && n->next->value !=value) {
    n = n->next;
  }

  if (!n->next) return;

  n->next = n->next->next;
}

class SetList {
  private:
    Node *head;

  public: 
    SetList();
    void insert(int value);
    string toString();

};

SetList::SetList() {
  head = NULL;
}

void SetList::insert(int value) {
  Node *newNode = new Node;
  newNode->value = value;
  newNode->next = NULL;

  Node *n = head;
  
  if (!n) {
    head = newNode;
  } else {

    bool isRepeated = false;
    while(n->next) {
      if(n->value == value) {
        isRepeated = true;
        break;
      }

      n = n->next;
    }

    if(isRepeated) return;
    n->next = newNode;
  }
}

string SetList::toString() {
  Node *n = head;
  string result = "Data [";

  if(n) {
    while (n) {
      result = result + " -> " + to_string(n->value);
      n = n->next;
    }
  }

  result = result + " ]";
  return result;
}

int main(void) {
  SimpleList l1 = SimpleList();

  string isEmptyStr = l1.isEmpty() ? "Esta vacia" : "No esta vacia";
  cout << "Estado actual de L1: " << isEmptyStr << endl << endl;

  cout << "Ingresando los valores de la lista (inicio)" << endl;

  int value = 0;
  do {
    cout << "Valor: ";
    cin >> value;

    if (value != 0) {
      l1.insertAtStart(value);
    }
  } while (value != 0);
  
  cout << endl << "Ingresando los valores de la lista (final)" << endl;

  value = 0;
  do {
    cout << "Valor: ";
    cin >> value;

    if (value != 0) {
      l1.insertAtEnd(value);
    }
  } while (value != 0);

  cout << endl << "---- LISTA 1 ----" << endl << "L1: " << l1.toString() << endl;
  isEmptyStr = l1.isEmpty() ? "Esta vacia" : "No esta vacia";
  cout << "Estado actual de L1: " << isEmptyStr << endl << endl;

  return 0;
}