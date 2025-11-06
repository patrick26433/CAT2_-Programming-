/*
Name:patrick kanyora 
Reg No:CT101/G/26433/25
Description:CAT2 2D array
*/

#include <stdio.h>

//declare and initialise 
int main(){
int scores[2][2]{
{65, 92},
{84, 72}
};

//print the elements 
for(int i=0;i<2;i++){
for(int j=0;j<2;j++)
{
printf("%d ",scores[i][j]);
}
printf("\n");
}

return 0;
}