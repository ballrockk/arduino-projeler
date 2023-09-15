int esikDegeri = 520;               //Gaz eşik değerini belirliyoruz.    
int buzzerPin = 9;                  //Buzzerın takılacağı pin
int deger;                          //Sensörden okunan değer

void setup() {
  pinMode(buzzerPin, OUTPUT);       //Buzzer pinimizi çıkış olarak ayarlıyoruz.
  Serial.begin(9600);
}

void loop() {
  deger = analogRead(A0);           //Sensörden analog değer okuyoruz.
  Serial.println(deger);
  delay(100);
  if(deger > esikDegeri){           //Sensörden okunan değer eşik değerinden büyükse çalışır.
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(100);
  }
  else{                             //Sensörden okunan değer eşik değerinin altındaysa çalışır.
    digitalWrite(buzzerPin, 1);
  }
}
