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



/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */
long long int gcd(long long int a, long long int b){
    if(a == 0 && b == 0){
        return 0;
    }
    else if( a == 0 && b != 0 ){
        return b;
    }
    else if( b == 0 && a != 0){
        return a;
    }
    else if( a == b){
        return a;
    }
    else{
        return gcd(b, a % b);
    }
}
long long int lcm(long long int a, long long int b){

    return a * b / gcd(a, b);
}

long long int getGCD(int b_count, int* b){
    if(b_count == 1){
        return *b;
    }
    long long int gcdTmp = gcd(*b, *(b+1));
    for(int i = 2 ; i < b_count ; i++){
       gcdTmp = gcd(*(b+i), gcdTmp);
    }
    
    return gcdTmp;
}

long long int getLCM(int a_count, int* a){
    
    if(a_count == 1){
        return *a;
    }
    
    long long int lcmTmp = lcm(*a, *(a + 1));
    for(int i = 2 ; i < a_count ; i++){
        lcmTmp = lcm(lcmTmp, *(a+i));
    }
    
    return lcmTmp;
}
int getTotalX(int a_count, int* a, int b_count, int* b) {
    
    int minA = 100;
    for(int i = 0 ; i < a_count ; i++){
        if(*(a+i) < minA){
            minA = *(a+i);
        }
    }
    
    int maxB = 0;
    for(int i = 0 ; i < b_count ; i++){
        if(*(a+i) > maxB){
            maxB = *(a+i);
        }
    }
    
    if(minA > maxB){
        return 0;
    }
     
    long long int lcm = getLCM(a_count, a);
    long long int gcd = getGCD(b_count, b);
    
    if(lcm == 0){
        return 0;
    }
    else{
        if(lcm > gcd){
            return 0;
        }
        else if( gcd % lcm != 0){
            return 0;
        }
        else{
            int counter = 0;
            long long int tmp = lcm;
            while(lcm <= gcd){
                if(gcd % lcm == 0){
                    counter++;
                }
                lcm += tmp;
            }
            return counter;
        }
    }
    
}

int main(){
    int a[1] = {2};
    int b[3] = {20, 30, 12};
    int res = getTotalX(1, a, 3, b);
}
