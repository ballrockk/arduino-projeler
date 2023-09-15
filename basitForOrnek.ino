int sure = 250;

void setup() {
  for (int i = 2 ; i < 7 ; i++)
     pinMode(i , OUTPUT);
}

void loop() {
  for (int i = 2 ; i < 7 ; i++)
    {  
     digitalWrite(i , 1);
     delay(sure);
     digitalWrite(i , 0);
    
     }

  





}
