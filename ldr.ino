int ldr ;
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  ldr = analogRead(A0);
  Serial.println(ldr);
  delay(200);
  if (ldr < 50)
  {  
  digitalWrite(2,1);
  digitalWrite(3,1);
  
  }
  else 
  {
        
   digitalWrite(2,0);
  digitalWrite(3,0);  }
  
  


  // put your main code here, to run repeatedly:

}
