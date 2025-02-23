#include <iostream> 
#include <string>
#include <stack>

using namespace std;

int main () {
	int n;
	cin >> n;
	stack<int> q;
	string a;
	for (int i = 0; i< n; i++) {
		cin >> a;
		
		if (a == "push") {
			int x;
			cin >> x;
			q.push(x);
		}	
	    else if (a == "pop") {
	    	if (!q.empty()) {
	    		q.pop();
	    	}
	    }
	}
	
    stack<int> temp;
    while (!q.empty()) {
        temp.push(q.top());
        q.pop();
    }
    
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }

    return 0;
}
	
