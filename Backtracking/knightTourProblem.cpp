//Knight Tour Problem: (Not that important)
/*
http://www.geeksforgeeks.org/backtracking-set-1-the-knights-tour-problem/
*/

/*As we know The Knight moves in an L shape in any direction. We can say that it either moves two squares sideways and then one square up or down, or two squares up or down, and then one square sideways.

Based on that knight can move up to max 8 directions thats why we have taken xMove[8] yMove[8].

int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

Value of these array depends upon that which direction Knight can move 
like 
1. go down and right // row + 2, column + 1
2. go right and down // row + 1, column + 2
3. go right and up // row - 1, column + 2 
4. go up and right //row - 2, column + 1
5. go up and left // row - 2, column - 1
6. go left and up //row - 1, column - 2
7. go left and down //row + 1, column - 2
8. go down and left //row + 2, column - 1

It is optimized moves/values sequence otherwise it will take more than an half hour (based on the computer speed) to solve this puzzle.

*/


#include<bits/stdc++.h>
using namespace std;
#define N 8

bool isSafe(int x,int y,int solve[N][N]){
	return (x>=0 && y>=0 && x<N && y <N && solve[x][y]==-1);
}

void printSol(int solve[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j,N;j++)
			cout<<solve[i][j]<<" ";
		cout<<endl;	
	}	
}


int solveKtUtil(int x,int y,int movei,int xMove[N],int yMove[N],int solve[N][N]){
	
	int next_x,next_y;
	
	if(movei==N*N)return true;
	
	for(int i=0;i<8;i++){
		
		next_x=x+xMove[i];
		next_y=y+yMove[i];
		
		if(isSafe(next_x,next_y,solve)){
			solve[next_x][next_y]=movei;
			
			if(solveKtUtil(next_x,next_y,movei+1,xMove,yMove,solve)==true)return true;
			
			else solve[next_x][next_y]=-1;
		}
	}
	return false;
}

bool solveKT(){
	int solve[N][N];
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			solve[i][j]=-1;
			
	int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
    
    
    solve[0][0]=0;
    
    if(solveKtUtil(0,0,1,xMove,yMove,solve)==false){
    	cout<<"abcd"<<endl;
    	return false;
    }
    else{
    	printSol(solve);
    }
	
	return true;
}




int main()
{
    solveKT();
    return 0;
}
