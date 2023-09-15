int anahtarOkuma = digitalRead(12);
int butonOkuma = digitalRead(13);
int kirmizi = 10;
int yesil = 11;
int buzzer = 9;
int C = 262;
int D = 294;
int E = 330;
int F = 349;
int G = 392;
int A = 440;
int B = 494;
int C_ = 523;
int notalar[] = {C, D, E, F, G, A, B, C_};
void setup() 
{
  for (int i = 9 ; i <12 ; i++)
  {
    pinMode(i ,OUTPUT);
  }
  pinMode(12 ,INPUT);
  pinMode(13 ,INPUT);
      
}

void loop() {
  anahtarOkuma = digitalRead(12);
  butonOkuma = digitalRead(13);
  if (anahtarOkuma == 1)
   {
     digitalWrite(yesil,1);
     digitalWrite(kirmizi ,0);
    
    for (int i = 0 ; i <8;i++)
     {
       tone(buzzer, notalar[i]);
       delay(500)      ; 
       noTone(buzzer);
       delay(200);
       }
     

     
   }  
  else 
   {
     digitalWrite(yesil,0);
     digitalWrite(kirmizi ,1);
     noTone(buzzer );
    }

























}
