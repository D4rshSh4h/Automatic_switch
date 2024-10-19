#include <Keypad.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Servo.h>
Servo myservo;
const byte ROWS = 4; 
const byte COLS = 4; 
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 
char string[5] = {};
char mins[3] = {};
char secs[3] = {};
int inputMin;
int inputSec;
int counter = 0;
char customKey;


//Making a keypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  myservo.attach(12);
  myservo.write(180);
  string[5] = '\0';
  mins[3] = '\0';
  secs[3] = '\0';
  
  
  
}
  
void loop(){
  getKey();
  
  
}


int getNumber(char customKey){
    
  while (counter< 1){
    strncpy(mins, string, 2);
    strncpy(secs, string + 2, 2);
    //mins[2] = '\0';
    //secs[2] = '\0';
    inputMin = atoi(mins);
    inputSec = atoi(secs);

    Serial.println(inputMin);
    Serial.println(inputSec);
    counter ++;

    

  }
  if ((strlen(mins) == 2) && (strlen(secs) == 2)){
    motor(inputMin, inputSec);
  }
    
}
void clear(){
  
  
    string[0] = '\0';
    inputMin = 0;
    inputSec = 0;
    Serial.println(string);

}

void motor(int minutes, int seconds){
  Serial.println(minutes);
  Serial.println(seconds);
  myservo.write(80);
  delay((minutes*60000) + (seconds*1000));
  myservo.write(135);
  delay((minutes*60000) + (seconds*1000));
  stop();




}

void getKey(){
  char customKey = customKeypad.getKey();
  if(customKey){
  if(strlen(string) < 4){
    
       if (customKey >= '0' && customKey <= '9'){
          strcat(string, &customKey);
          Serial.println(string);
         }
        else if (customKey = '#'){
         clear();
          
        }

  }
  }
  if (strlen(string) == 4){
    getNumber(string);
  }
  
}
void stop(){
  char stop[] = {'program stopped'};
  int stopvar  = 1;

  while(stopvar<2){

  }
  Serial.println(stop);
}

  

  
    
        
        

  



  



  
