#include <iostream>
#include <string>
#include <vector>
#include "mat.hpp"


using namespace std;

namespace ariel{

string mat(int cols, int rows, char c1, char c2) {
	 //define thee range of symbol
     const int MAX_VAL =126;
     const int MIN_VAL =33;
      
       // default cases 
        if( rows%2 == 0 || cols%2 == 0  || rows < 1 || cols < 1) { 
	        throw runtime_error("impossible to be even or smaller than 1");// even or zero and down
	    }
	    if(c1 > MAX_VAL || c1 < MIN_VAL || c2 > MAX_VAL || c2 < MIN_VAL) { // the range of the legal symbol
	        throw runtime_error("must to be a char in the range");
	    }
	    
    string matrix;

    vector<vector<char>> map(rows, vector<char>(cols));        

                //choose the SMALLER between cols to rows
    int temp = 0;
    if(cols>rows){ temp =rows/2+1;} //round up
    else {temp = cols/2+1;}        //round up


    for(int i =0; i<temp; i++){
        
        if(i%2 == 0){ //even's places
                                      //pass on  the first column                      
            for(int j =i; j<rows-i; j++){
                map[j][i] = c1;
            }
                                    //pass on  the last column
            for(int j =i; j<rows-i; j++){
                map[j][cols-i-1] = c1;
            }
                                      //pass on  the first row
            for(int j =i; j<cols-i; j++){
                map[i][j] = c1;
            }
                                     //pass on the last row
            for(int j =i; j<cols-i; j++){
                map[rows-i-1][j] = c1;
            }
            
        }
        else{ // i%2 != 0  --> i is odd
                                        
                                        //pass inside
        for(int j =i; j<rows-i; j++){
                map[j][i] = c2;
        }
        for(int j =i; j<rows-i; j++){
                map[j][cols-i-1] = c2;
        }    
        for(int j =i; j<cols-i; j++){
                map[i][j] = c2;
        }
            
        for(int j =i; j<cols-i; j++){
                map[rows-i-1][j] = c2;
        }
           
        }
    }
                                    //pass on the vector and append in the matrix
    for(int i =0; i<rows; i++){
        for(int j=0; j<cols; j++){
            matrix += map[i][j];
        }
        matrix += "\n";  //downline
    }
    cout<< matrix;
	    return matrix;
	}
}