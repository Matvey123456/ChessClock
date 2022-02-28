#include <TimeLib.h>

int numbers[10][7] = {
                    {1,1,1,1,1,1,0},
                    {0,1,1,0,0,0,0},
                    {1,1,0,1,1,0,1},
                    {1,1,1,1,0,0,1},
                    {0,1,1,0,0,1,1},
                    {1,0,1,1,0,1,1},
                    {1,0,1,1,1,1,1},
                    {1,1,1,0,0,0,0},
                    {1,1,1,1,1,1,1},
                    {1,1,1,1,0,1,1},
                    };

int ATimeM = 3;
int ATimeS = 0;

int BTimeM = 3;
int BTimeS = 0;

int plusSeconds = 2;

boolean player = false;
boolean theEnd = false;
//test
void pick_digit(int digit) {
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  
  switch(digit) {
    case 1: digitalWrite(10, HIGH); break;
    case 2: digitalWrite(11, HIGH); break;
    case 3: digitalWrite(12, HIGH); break;
    default:digitalWrite(13, HIGH); break;
  }
  
}
void printATime() {
 
  for(int a = 0;a < 7;a++){
    if(numbers[(int)ATimeM/10][a] == 0){
      digitalWrite(a + 3,HIGH);  
    }
    else{
      digitalWrite(a + 3, LOW);
    }  
  }
  pick_digit(1);
  delay(5);
  
  for(int a = 0;a < 7;a++){
    if(numbers[ATimeM%10][a] == 0){
      digitalWrite(a + 3,HIGH);  
    }
    else{
      digitalWrite(a + 3, LOW);
    }  
  }
  pick_digit(2);
  delay(5);
  
  for(int a = 0;a < 7;a++){
    if(numbers[(int)ATimeS/10][a] == 0){
      digitalWrite(a + 3,HIGH);  
    }
    else{
      digitalWrite(a + 3, LOW);
    }  
  }
  pick_digit(3);
  delay(5);
  
  for(int a = 0;a < 7;a++){
    if(numbers[ATimeS%10][a] == 0){
      digitalWrite(a + 3,HIGH);  
    }
    else{
      digitalWrite(a + 3, LOW);
    }  
  }
  digitalWrite(2,LOW);
  pick_digit(4);
  delay(5);

  digitalWrite(2,HIGH);
}

void printBTime() {
 
  for(int a = 0;a < 7;a++){
    if(numbers[(int)BTimeM/10][a] == 0){
      digitalWrite(a + 3,HIGH);  
    }
    else{
      digitalWrite(a + 3, LOW);
    }  
  }
  digitalWrite(2,LOW);
  pick_digit(1);
  delay(5);
  
  digitalWrite(2,HIGH);
  
  for(int a = 0;a < 7;a++){
    if(numbers[BTimeM%10][a] == 0){
      digitalWrite(a + 3,HIGH);  
    }
    else{
      digitalWrite(a + 3, LOW);
    }  
  }
  pick_digit(2);
  delay(5);
  
  for(int a = 0;a < 7;a++){
    if(numbers[(int)BTimeS/10][a] == 0){
      digitalWrite(a + 3,HIGH);  
    }
    else{
      digitalWrite(a + 3, LOW);
    }  
  }
  pick_digit(3);
  delay(5);
  
  for(int a = 0;a < 7;a++){
    if(numbers[BTimeS%10][a] == 0){
      digitalWrite(a + 3,HIGH);  
    }
    else{
      digitalWrite(a + 3, LOW);
    }  
  }
  pick_digit(4);
  delay(5);
  
}

void setup() {
  
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  
  Serial.begin(9600);


}

void loop() { 
  if(!theEnd){
    TimeLimit();  
    button();
  }
  if(player){
    if(second() > 0 && !theEnd){
      ATimeS--;
      setTime(0,0,0,0,0,0);
    }
    printATime();  
  }
  else{
    if(second() > 0 && !theEnd){
      BTimeS--;
      setTime(0,0,0,0,0,0);
    }
    printBTime();
  }
}

void TimeLimit(){

  if(ATimeS == 0 && ATimeM == 0||BTimeS == 0 && BTimeM == 0){
    theEnd = true;  
  }
  if(ATimeS < 0){
    ATimeM--;
    ATimeS = 59;
  }
  if(BTimeS < 0){
    BTimeM--;
    BTimeS = 59;
  }
  if(ATimeS > 59){
    ATimeM++;
    ATimeS -= 60;
  }
  if(BTimeS > 59){
    BTimeM++;
    BTimeS -= 60;
  }
}
void button(){
  if(analogRead(A0) == 0){
    player = !player; 

    if(player){
      BTimeS += plusSeconds;
    }
    else{
      ATimeS += plusSeconds;  
    }
     
    delay(200);
  }
}
