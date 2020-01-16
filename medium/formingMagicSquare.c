//
//  main.c
//  test1
//
//  Created by Chan Yong Lee on 05.01.20.
//  Copyright © 2020 Chan Yong Lee. All rights reserved.
//

#include <stdio.h>

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int formingMagicSquare(int s_rows, int s_columns, int** s) {
    
    //array to save the sum of each column and row
    int tmpArr[s_rows + s_columns];
    int counter = 0;

    for(int i = 0 ; i < s_rows ; i++){
        int tmp = 0;
        for(int j = 0 ; j < s_columns ; j++){
            tmp += *(*(s + i) + j);
        }
        tmpArr[counter] = tmp;
        counter++;
    }

    for(int i = 0 ; i < s_columns ; i++){
        int tmp = 0;
        for(int j = 0 ; j < s_rows ; j++){
            tmp += *(*(s + j) + i);
        }
        tmpArr[counter] = tmp;
        counter++;
    }
    
    //finding the sum that every row and column should have
    int minChange = 100;
    int index = 0;
    int result = 0;
    
    for(int i = 0 ; i < s_rows + s_columns ; i++){
        int tmp = 0;
        for(int j = 0 ; j < s_rows + s_columns ; j++){
            if(tmpArr[j] > tmpArr[i]){
                tmp += (tmpArr[j] - tmpArr[i]);
            }
            else{
                tmp += (tmpArr[i] - tmpArr[j]);
            }
        }

        if(tmp < minChange){
            minChange = tmp;
            index = i;
        }
    }
    
    int value = tmpArr[index];
    counter = 0;
    
    for(int i = 0 ; i < s_rows ; i++){
        
        int tmp = tmpArr[i];
        
        /*
        for(int j = 0 ; j < s_columns ; j++){
            tmp += *(*(s + i) + j);
        }
         */
        
        if(tmp != value){
            for(int k = 0 ; k < 3 ; k++){
                if(tmpArr[k + 3] == value){
                    //noop
                }
                else{
                    if(tmp > value){
                        *(*(s+i) + k) -= tmp - value;
                        result += tmp - value;
                        tmpArr[i] = value;
                        tmpArr[k+3] -= tmp - value;
                    }
                    else{
                        *(*(s+i) - k) += value - tmp;
                        result += value - tmp;
                        tmpArr[i] = value;
                        tmpArr[k+3] += tmp + value;
                    }
                }
            }
        }
    }
    
    for(int i = 0 ; i < s_columns ; i++){
        int tmp = 0;
        for(int j = 0 ; j < s_rows ; j++){
            tmp += *(*(s + j) + i);
        }
        
        //if(tmp != value){
            if(tmp != value){
                for(int k = 0 ; k < 3 ; k++){
                    if(tmpArr[k] == value){
                        //noop
                    }
                    else{
                        if(tmp > value){
                            *(*(s+ k) + i) -= tmp - value;
                            result += tmp - value;
                        }
                        else{
                            *(*(s+k) - i) += value - tmp;
                            result += value - tmp;
                        }
                    }
                }
            }
        //}
    }
    

    return result;

    
}

int main(){
    int** s = malloc(3 * sizeof(int*));
    *(s) = malloc(3*sizeof(int));
    *(s+1) = malloc(3*sizeof(int));
    *(s+2) = malloc(3*sizeof(int));
    *(*(s)) = 4;
    *(*(s) + 1) = 8;
    *(*(s) + 2) = 2;
    *(*(s + 1) ) = 4;
    *(*(s+1) +1) = 5;
    *(*(s+1)+2) = 7;
    *(*(s+2)) = 6;
    *(*(s+2)+1) = 1;
    *(*(s+2)+2) = 6;
    //= {{4, 9 ,2} , {3, 5, 7} , {8, 1, 5}};
    int result = formingMagicSquare(3, 3, s);
}
