#include<bits/stdc++.h>
using namespace std;

int isSameBST(int X[], int Y[], int n)
{
    int leftX[n-1], rightX[n-1], leftY[n-1], rightY[n-1];
    int k = 0, l = 0, m = 0, o = 0;
    
    // if no element is present in the array, return true
    if (n == 0)
        return 1;
 
    // if 1st element differs in both array (root node key), return false
    if (X[0] != Y[0])
        return 0;
 
    // if array contains only one key, return true
    if (n == 1)
        return 1;
 
    // process remaining keys and divide them into two groups
    for (int i = 1; i < n; i++)
    {
        // leftX[] will contain all elements less than X[0]
        if (X[i] < X[0])
            leftX[k++] = X[i];
 
        // rightX[] will contain all elements more than X[0]
        else
            rightX[l++] = X[i];
 
        // leftY[] will contain all elements less than Y[0]
        if (Y[i] < X[0])
            leftY[m++] = Y[i];
 
        // rightY[] will contain all elements more than Y[0]
        else
            rightY[o++] = Y[i];
    }
    
    // number of nodes in left subtree of both trees differs
    if (k != m)
        return 0;
    // number of nodes in right subtree of both trees differs
    if (l != o)
        return 0;
 
    // check left subtree and right subtree
    return isSameBST(leftX, leftY, k) &&
            isSameBST(rightX, rightY, l);
}
 
// main function
int main()
{
    int X[] = { 15, 25, 20, 22, 30, 18, 10, 8, 9, 12, 6 };
    int Y[] = { 15, 10, 12, 8, 25, 30, 6, 20, 18, 9, 22 };
 
    int n = sizeof(X) / sizeof(X[0]);
    int m = sizeof(Y) / sizeof(Y[0]);
 
    if (m == n && isSameBST(X, Y, n))
    	cout<<1<<endl;
    else
        cout<<0<<endl;
 
    return 0;
}
