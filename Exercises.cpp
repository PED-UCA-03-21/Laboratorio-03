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

      if(!p->next) {
        return p;
      } else {
        return _getTail(p->next);
      }
    }

    int _find(Node *p, int pos, int value) {
      if(!p) return -1;

      if(p->value == value) {
        return pos;
      } else {
        return _find(p->next, pos + 1, value);
      }
    }

  public:
    SimpleList();
    void insertAtStart(int value);
    void insertAtEnd(int value);
    void remove(int value);
    int find(int value);
    string toString();
    bool isEmpty();
    Node *getTail();
};

SimpleList::SimpleList() {
  head = NULL;
}

Node *SimpleList::getTail() {
  return _getTail(head);
}

bool SimpleList::isEmpty() {
  /* if(head == NULL) {
    return true;
  }else {
    return false;
  } */

  return head == NULL;
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

void SimpleList::remove(int value) {
  Node *n = head;

  if(!head) return;

  if(n->value == value) {
    head = n->next;
    delete n;
    return;
  }

  while(n->next && n->next->value != value) {
    n = n->next;
  }

  //Posibilidades de n: 1. Es el anterior al que busco 2. Es el ultimo elemento
  if(!n->next) return;

  Node *r = n->next;
  n->next = r->next;
  delete r;
}

string SimpleList::toString() {
  Node *n = head;
  string result = "List [";

  if(n) {
    while(n) {
      result = result + " -> " + to_string(n->value);
      n=n->next;
    }
  }

  result = result + " ]";
  return result;
}

int SimpleList::find(int value) {
  return _find(head, 0, value);
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

string SetList::toString() {
  Node *n = head;
  string result = "Set [";

  if(n) {
    while(n) {
      result = result + " -> " + to_string(n->value);
      n=n->next;
    }
  }

  result = result + " ]";
  return result;
}

void SetList::insert(int value) {
  Node *newNode = new Node;
  newNode->value = value;
  newNode->next = NULL;

  if(!head) {
    head = newNode;
    return;
  }

  Node *n = head;
  bool isRepeated = false;

  while(n->next && !isRepeated) {
    if(n->value == value) {
      isRepeated = true;
    }

    n = n->next;
  } 

  isRepeated = isRepeated || n->value == value;

  if(!isRepeated) {
    n->next = newNode;
  } else {
    delete newNode;
  }
}


int main(void) {

  SimpleList l1 = SimpleList();
  SetList set = SetList();

  /* string isEmptyStr = l1.isEmpty() ? "Esta vacia" : "Tiene datos";
  cout << "Estado de la lista: " << isEmptyStr << endl << endl;

  cout << "Pidiendo los valores de la lista (inicio)..." << endl;

  int value = 0;
  do {
    cout << "Valor: ";
    cin >> value;

    if(value != 0) {
      l1.insertAtStart(value);
    }
  } while(value != 0);

  cout << "Pidiendo los valores de la lista (final)..." << endl;

  value = 0;
  do {
    cout << "Valor: ";
    cin >> value;

    if(value != 0) {
      l1.insertAtEnd(value);
    }
  } while(value != 0);

  cout << "--- LISTA 1 ---" << endl;
  cout << "L1: " << l1.toString() << endl << endl;

  isEmptyStr = l1.isEmpty() ? "Esta vacia" : "Tiene datos";
  cout << "Estado de la lista: " << isEmptyStr << endl << endl;

  cout << "Numero a buscar: ";
  int toFind = 0, posFound;
  cin >> toFind;

  posFound = l1.find(toFind);
  if (posFound < 0) {
    cout << "Numero no encontrado" << endl << endl;
  } else {
    cout << "El Numero esta en la posicion: " << posFound << endl << endl;
  }

  cout << "Numero a eliminar: ";
  int toRemove = 0;
  cin >> toRemove;

  l1.remove(toRemove);
  cout << "L1: " << l1.toString() << endl << endl; */

  cout << "Pidiendo los valores del set..." << endl;

  int value = 0;
  do {
    cout << "Valor: ";
    cin >> value;

    if(value != 0) {
      set.insert(value);
    }
  } while(value != 0);

  cout << "--- SET ---" << endl;
  cout << "S1: " << set.toString() << endl << endl;

  return 0;
}