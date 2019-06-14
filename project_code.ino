#include<Wire.h>
const int MPU=0x68; 
int16_t AcX,AcY,AcZ,Tmp;

void setup(){
  pinMode(8,OUTPUT);
   pinMode(9,OUTPUT);
  
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
  Serial.begin(9600);
}
void loop(){
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);  
  AcX=Wire.read()<<8|Wire.read();    
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();    
  
  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(AcX);
  Serial.print(" | Y = "); Serial.print(AcY);
  Serial.print(" | Z = "); Serial.println(AcZ);
   
   if (AcX >0)
 {
digitalWrite(8,HIGH);
 }
 else
 {
  digitalWrite(8,LOW);  
 }

  if (AcY >0)
 {
digitalWrite(9,HIGH);
 }
 else
 {
  digitalWrite(9,LOW);  
 }
  delay(333);
}
