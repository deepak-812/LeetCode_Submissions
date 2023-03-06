//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;

class GFG{
	public static void main(String [] args) throws IOException{
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		while(test-- > 0) {
			int N = sc.nextInt();
			Solution obj = new Solution();
			obj.toBinary(N);
			System.out.println();
		}
	}
}
// } Driver Code Ends


//User function Template for Java

class Solution{
	void toBinary(int n) {
		//Write your code here
		int bitArr[];
		bitArr=new int[32];
		int i=0;
		while(n>0){
		    if((n & 1) == 1)bitArr[i]=1;
		    else{
		        bitArr[i]=0;
		    }
		    n=n/2; i++;
		}
		for(int j=i-1;j>=0;j--){
		    System.out.print(bitArr[j]);
		}
	}
}