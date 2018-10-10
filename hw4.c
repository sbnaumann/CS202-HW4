/*
Assignment: 4
<float>

Name: Sam Naumann
Email: sbnaumann@middlebury.edu
Date: 10/8/2018
Collaborators: None

To compile: gcc ~/CS202/HW4/hw4.c -o ~/CS202/HW4/hw4
To run:./CS202/HW4/hw4 

*/

#include <stdio.h>
#include <math.h>

int printFloats(int forRead){
  //print forRead in the hex format
  printf(" %0*X: ", 2, forRead);
  //printf("\n"); 

  //retreive binary values from int
  int m_mask = 0x0f; 
  int mantissa = 0;
  mantissa = m_mask & forRead;

  int e_mask = 0x70;
  int exponent = 0;
  exponent = (e_mask & forRead)/15;

  int s_mask = 0x80;
  int sign = 0;
  sign = (s_mask & forRead)/127;



 
  // printf("mantissa: %d\n", mantissa);
  //printf("mantissaTrue: %f, exponent: %d, sign: %d\n", mantissaTrue, exponent, sign);
  if(exponent == 0){
    float mantissaTrue = mantissa/8.0;
    float floatPrint = pow(-1,sign) * pow(2,(exponent-3)) * (mantissaTrue);
    printf("%f\n", floatPrint);
  } else if(exponent == 7 && mantissa == 0){
    printf("+/-infinity\n");
  } else if(exponent == 7 && mantissa != 0){
    printf("NaN\n");
  } else {
    float mantissaTrue = mantissa/16.0;
    float floatPrint = pow(-1,sign) * pow(2,(exponent-3)) * (mantissaTrue + 1);
    printf("%f\n", floatPrint);
  }
  

  

  
  
}

int main(int argc, char * argv[]){
  for(int i = 0; i < 256; i++){
    int forRead = i; 
    printFloats(forRead); 
    }
}
