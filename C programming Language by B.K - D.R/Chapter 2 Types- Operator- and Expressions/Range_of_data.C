/*
  Exercise 2-1
  Write a program to determine the ranges of char , short , int , and long variables,
  both signed and unsigned , by printing appropriate values from standard headers
  and by direct computation. Harder if you compute them:
  determine the ranges of the various floating-point types.
*/
#include <stdio.h>
#include<limits.h>  // To find Range of various datatype
int main(void) {
  printf("Size of Char %d Range is from:%d to %d\n",CHAR_BIT,CHAR_MIN,CHAR_MAX);
  printf("Size of int %d Range is from:%d to %d\n", sizeof(int),INT_MIN,INT_MAX);
  printf("Size of long %d Range is from:%d to %d\n",sizeof(long),LONG_MIN,LONG_MAX);
  printf("Size of short %d Range is from:%d to %d\n",sizeof(short),SHRT_MIN,SHRT_MAX);
  printf("Size of unsigned char %d Range is from:%d to %d\n",sizeof(unsigned char),0,UCHAR_MAX);
  printf("Size of unsigned long %d Range is from:%d to %ul\n",sizeof(unsigned long),0,ULONG_MAX);
  printf("Size of unsigned int %d Range is from:%d to %ud\n",sizeof(unsigned int),0,UINT_MAX);
  printf("Size of unsigned short %d Range is from:%d to %d\n",sizeof(unsigned short),0,USHRT_MAX);
  return 0;
}
