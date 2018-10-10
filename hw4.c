/*
Assignment: 4
<float>

Name: Sam Naumann
Email: sbnaumann@middlebury.edu
Date: 10/8/2018
Collaborators: None

To compile: gcc ~/CS202/HW4/hw4.c -lm -o ~/CS202/HW4/hw4
To run:./CS202/HW4/hw4 
      There are no arguments for this function, but it iterates through and prints all the float numbers in an 
      8 bit float representation that uses the excess 3 IEEE 754 format 

*/

#include <stdio.h>
#include <math.h>

//This function decodes the ints and prints them as their correct hex and float representations 
int printFloats(int forRead){
  //print forRead in the hex format
  printf(" %0*X: ", 2, forRead);

  
  //retreive binary values from int and convert them into a float
  int m_mask = 0x0f; 
  int mantissa = 0;
  mantissa = m_mask & forRead;

  int e_mask = 0x70;
  int exponent = 0;
  exponent = (e_mask & forRead)/15;

  int s_mask = 0x80;
  int sign = 0;
  sign = (s_mask & forRead)/127;


  //This piece prints the float number and makes specific calculations based on the exponent value to obtain
  //    those floats 
  if(exponent == 0){
    float mantissaTrue = mantissa/8.0;
    float floatPrint = pow(-1,sign) * pow(2,(exponent-3)) * (mantissaTrue);
    printf("%f\n", floatPrint);
  } else if(exponent == 7 && mantissa == 0 && sign == 0){
    printf("+infinity\n");
  } else if(exponent == 7 && mantissa == 0 && sign == 1){
    printf("-infinity\n");
  } else if(exponent == 7 && mantissa != 0){
    printf("NaN\n");
  } else {
    float mantissaTrue = mantissa/16.0;
    float floatPrint = pow(-1,sign) * pow(2,(exponent-3)) * (mantissaTrue + 1);
    printf("%f\n", floatPrint);
  }
  

  

  
  
}

//main in this iterates through the 256 Representations and calls the printFloats function
int main(int argc, char * argv[]){
  for(int i = 0; i < 256; i++){
    int forRead = i; 
    printFloats(forRead); 
    }
}
