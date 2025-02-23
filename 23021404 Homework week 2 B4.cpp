#include <iostream> 
#include <string>
#include <queue>

using namespace std;

int main () {
	int n;
	cin >> n;
	queue<int> q;
	string a;
	for (int i = 0; i< n; i++) {
		cin >> a;
		
		if (a == "enqueue") {
			int x;
			cin >> x;
			q.push(x);
		}	
	    else if (a == "dequeue") {
	    	if (!q.empty()) {
	    		q.pop();
	    	}
	    }
	}
	
	while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
	
