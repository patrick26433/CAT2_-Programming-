/*
Name:patrick kanyora 
Reg No:CT101/G/26433/25
Description:calculating pay
*/

#include<stdio.h>

int main(){

int hours_worked,hourly_wage;
float gross_pay,taxes,net_pay;

printf("Enter the hours worked: ");
scanf("%d",&hours_worked);

printf("Enter hourly wage: ");
scanf("%d",&hourly_wage);

if(hours_worked<=40){
gross_pay=hours_worked*hourly_wage ;
}
else {
gross_pay=(40*hourly_wage)+(((hours_worked-40)*0.5)*hourly_wage);
}

if(gross_pay<=600){
taxes=gross_pay*0.15;
}
else{
taxes=(600*0.15)+((gross_pay-600)*0.2);
}

net_pay=gross_pay-taxes;

printf("Gross pay: %.2f \n",gross_pay);
printf("Taxes: %.2f \n",taxes);
printf("net_pay: %.2f \n",net_pay);

return 0;
}