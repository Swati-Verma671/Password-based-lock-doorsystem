/* Main.c file generated by New Project wizard
 *
 * Created:   Wed Jun 29 2022
 * Processor: AT89C51
 * Compiler:  Keil for 8051
 */

#include <reg51.h>
#include <stdio.h>
/* row initialization */
sbit row1 = P1^3;
sbit row2 = P1^4;
sbit row3 = P1^5;
sbit row4 = P1^6;

/* column initialization */
sbit column1 = P1^2;
sbit column2 = P1^1;
sbit column3 = P1^0;

/*motor pin*/
sbit motor1 = P3^0;
sbit motor2 = P3^1;

/*led pins*/
sbit rs = P0^0;
sbit rw = P0^1;
sbit en = P0^2;

void lcddta (unsigned char);/* data command*/
void lcdisplay(unsigned char *k);/* display the messages*/
void lcdcmd(unsigned char);/*lcd command*/
void delay(unsigned int);/* delay command*/
char keypad();/* keypad interfacing*/
void check();/*check for the password*/
unsigned char pin[] ={"1234567"};/* the assumed password*/
unsigned char Lpin[7];/* the length of the assumed password*/

void main(){
   lcdcmd(0x38);//5 x 7 mstrix selection command
   lcdcmd(0x0e);//display on cursor blinking
   lcdcmd(0x01);//clear screen
   lcdcmd(0x06);//shift to cursor right
   
   while(1){
      unsigned int p = 0;
      lcdcmd(0x80);//1st position for the cursor
      lcdisplay("Enter Pin Number");//message to be displayed
      delay(1000);
      lcdcmd(0xc0);//next line
      while(pin[p]!='\0'){
	 Lpin[p]=keypad();//array storing the user's pin
	 delay(1000);
	 p++;
      };
      check();
   }//end of while
}//end of main

//delay function
void delay(unsigned int j){
   int s, w;
   for (s=0;s<j;s++){
      for(w=0;w<10;w++){
      }
   }
}

//lcd commands function
void lcdcmd (unsigned char a){
   P2=a;
   rs=0;
   rw=0;
   en=1;
   delay(1000);
   en=0;
}

//lcd data function
void lcddta(unsigned char i){
   P2=i;
   rs=1;
   rw=0;
   en=1;
   delay(1000);
   en=0;
}

//lcd display function
void lcdisplay(unsigned char *k){
   int q;
   for(q=0;k[q]!='\0';q++){
      lcddta(k[q]);
   }
   delay(1000);
}

//keypad function
char keypad(){
   int x = 0;
   while (x==0){
      //assign values for first row
      row1=0;
      row2=1;
      row3=1;
      row4=1;
      if(column1==0){
	 lcddta('*');
	 delay(1000);
	 x=1;
	 return '1';
      }
      if(column2==0){
	 lcddta('*');
	 delay(1000);
	 x=1;
	 return '2';
      }
      if(column3==0){
	 lcddta('*');
	 delay(1000);
	 x=1;
	 return '3';
      }
      row1=1;
      row2=0;
      row3=1;
      row4=1;
      if(column1==0){
	 lcddta('*');
	 delay(1000);
	 x=1;
	 return '4';
      }
      if(column2==0){
	 lcddta('*');
	 delay(1000);
	 x=1;
	 return '5';
      }
      if (column3==0){
	 lcddta('*');
	 delay(1000);
	 x=1;
	 return '6';
      }
      row1=1;
      row2=1;
      row3=0;
      row4=1;
      if(column1==0){
	 lcddta('*');
	 delay(1000);
	 x=1;
	 return '7';
      }
      if (column2==0){
	 lcddta('*');
	 delay(1000);
	 x=1;
	 return '8';
      }
      if (column3==0){
	 lcddta('*');
	 delay(1000);
	 x=1;
	 return '9';
      }
      row1=1;
      row2=1;
      row3=1;
      row4=0;
      if(column1==0){
	 lcddta('*');
	 delay(1000);
	 x=1;
	 return '*';
      }
      if (column2==0){
	 lcddta('*');
	 delay(1000);
	 x=1;
	 return '0';
      }
      if(column3==0){
	 lcddta('*');
	 delay(1000);
	 x=1;
	 return '#';
      }
   }
}

//check function
void check(){
   if(pin[0]==Lpin[0] && pin[1]==Lpin[1] && pin[2]==Lpin[2 ]&& pin[3]==Lpin[3] && pin[4]==Lpin[4] && pin[5]==Lpin[5] && pin[6]==Lpin[6]){
      lcdcmd(0x01);//clear screen
      lcdcmd(0x80);//first line
      lcdisplay("Correct Pin");
      motor1 =1;//start the motor
      motor2 = 0;
      delay(1000);
      lcdcmd(0xc0);//next line
      lcdisplay("Door Opened");
      delay(1000);
      motor1=1;//stop the motor
      motor2=1;
      lcdcmd(0x01);
   }else{
      lcdcmd(0x01);
      lcdcmd(0x80);
      lcdisplay("Wrong Pin");
      delay(1000);
      lcdcmd(0x01);
   }
}
