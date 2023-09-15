int anahtarOkuma = digitalRead(12);
int butonOkuma = digitalRead(13);
int buzzer = 9;
const byte potPin=A0; //Potansiyometre data pini arduino bağlantı pini
int potDeger; //Potansiyometreden okunacak değer değişkeni
int ledPin=10; //Led'in bağlı olduğu pwm pini
// Potansiyometre : 3 delik sırasıyla 1. Artıya , 2. analog pinine , 3. eksiye

void setup() {
  
for (int i = 9 ; i <12 ; i++)
  {
    pinMode(i ,OUTPUT);
  }
  pinMode(12 ,INPUT);
  pinMode(13 ,INPUT);

}

void loop() {
  noTone(9);
  //map komutu ile potansiyometre değerini
//pwm sinyaline dönüştürüyoruz.
potDeger=map(analogRead(potPin),0,1023,0,255);
analogWrite(ledPin,potDeger);
}
