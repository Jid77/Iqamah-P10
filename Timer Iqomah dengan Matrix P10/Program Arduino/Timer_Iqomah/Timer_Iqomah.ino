/*************************************
JID
 * ***********************************/

#include <SPI.h>        
#include <DMD.h>        
#include <TimerOne.h>   
#include "SystemFont5x7.h"
#include "Arial_black_16.h"

#define DISPLAYS_ACROSS 1
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);
int menit,detik,i;
char b[8];
String str;

void ScanDMD()
{ 
  dmd.scanDisplayBySPI();
}


void setup()
{ 
  Serial.begin(9600);
  Timer1.initialize( 5000 );           
  Timer1.attachInterrupt( ScanDMD );
  dmd.clearScreen( true );
  pinMode(2,INPUT);
  digitalWrite(2,HIGH);  
}

void loop()
{
  str=""; 
  
  menit=2;
  
  while(digitalRead(2)); 
  i=1;
  while(i){    
    if(detik>0){
      detik--;
    }
    else if(detik==0){
      detik=59;
      if(menit>0){
        menit--;
      }
      else if(menit==0){
       detik=0;
       i=0; 
      }
      
    }
    dmd.clearScreen( true );    
    str=String(menit)+":"+String(detik);
    str.toCharArray(b,6);  
    dmd.selectFont(Arial_Black_16);  
    dmd.drawString( 0, 1, b, 5, GRAPHICS_NORMAL );  
    delay(1000);   
}

}


