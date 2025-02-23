#include <iostream>
#include <list>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    list<int> linkedList;
    
    string command;
    while (n--) {
        string op;
        cin >> op;
        if (op == "insert") { 
            int p, x;
            cin >> p >> x;
            list<int>::iterator it = linkedList.begin(); 
            advance(it, min(p, (int)linkedList.size())); 
            linkedList.insert(it, x);
        } else if (op == "delete") { 
            int p;
            cin >> p;
            if (p >= 0 && p < (int)linkedList.size()) {
                list<int>::iterator it = linkedList.begin();
                advance(it, p);
                linkedList.erase(it);
            }
        }
    }
    
    for (list<int>::iterator it = linkedList.begin(); it != linkedList.end(); ++it) {
        cout << *it << " ";
    }

    return 0;
}

