// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
   stack<int> s;
   int n=k;
   while(n--)
   {
       s.push(q.front());
       q.pop();
   }
   // 3 2 1
   while(!s.empty())
   {
       q.push(s.top());
       s.pop();
   }
   // 4 5 3 2 1
   int i=q.size()-k;
   //cout<<i;
   while(i--)
   {
      q.push(q.front());
      q.pop();
   }
   return q;
   // 3 2 1 4 5
}