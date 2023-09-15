
//KUTUPHANELER
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>


//DEGİSKENLER
#define DHTPIN 12          
#define DHTTYPE DHT11     
DHT dht(DHTPIN, DHTTYPE); // dht 2 kahverengi

    #define ldr A3 //turuncu
    #define gaz A2 //yesil
    #define buzz 3 //sarı
    #define evisik 5 //beyaz
    #define evisik1 6 //beyaz
    #define pot A1 //beyaz


    int sure = 3;
    #define IN1 11 //step Motor pinleri
    #define IN2 10 
    #define IN3 9  
    #define IN4 8 

     
    #define trigPin 4
    #define echoPin 2
    long mesafe=0;
    long sure1=0;


     LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD EKRAN İCİN lcd tanımladık a4 sda , a5 scl mor 

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  Serial.begin(9600); 

  pinMode(buzz,OUTPUT);
  pinMode(evisik,OUTPUT);
  pinMode(evisik1,OUTPUT);
  lcd.backlight();



  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  
}

void loop() {
  sicaklikldr();
  kapi();
 

  
  int a = map(analogRead(gaz), 0,1023,0,50);
  if(a > 13 )
  {
    digitalWrite(buzz,0);
    lcd.clear();
    lcd.setCursor(3, 0);    
    lcd.print("KARAGUMRUK");
     lcd.setCursor(4, 1);
    lcd.print("YANIYOR!");
    }
    else
    {
    lcd.clear();
    sicaklik();
    digitalWrite(buzz,1);
    }

    
  

  delay(1000); 
}








  void sicaklikldr()
  { 

  float temperature = dht.readTemperature();  // Sıcaklık 
  float humidity = dht.readHumidity();        // Nem 

  lcd.setCursor(0, 0);
  lcd.print("Nem:");

  lcd.setCursor(10, 0);
  lcd.print(temperature, 1);  // Sıcaklık
  lcd.print(" C");
  
  lcd.setCursor(4, 0);
  lcd.print("%");
  lcd.print(humidity, 0);     // Nem 


  lcd.setCursor(0, 1);
  lcd.print("kacak=0");

  if(analogRead(ldr)<100)
    {
     int deger = map(analogRead(pot),1023,0,255,2);
     analogWrite(evisik, deger);
     analogWrite(evisik1, deger);
     lcd.setCursor(8, 1);
     lcd.print("aksam");
    
    
    }
    else
    {
      digitalWrite(evisik,0);
      digitalWrite(evisik1,0);
      lcd.setCursor(8, 1);
      lcd.print("sabah");
      }

  
  }
  void kapi()
  {
    
     digitalWrite(trigPin, LOW);
     delayMicroseconds(3);
      digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    sure1 = pulseIn(echoPin, HIGH);
    mesafe = (sure1/2) * 0.0343;
    Serial.print(mesafe);
    if(mesafe<6)
    {
     SaatTersYonu(128);//sag
     delay(3000);
     SaatYonu(128); // sol
     }

 }


 void SaatYonu(int adimSayisi) {
  for (int i = 0; i < adimSayisi; i++) {
    digitalWrite(IN4, HIGH);
    delay(sure);
    digitalWrite(IN4, LOW);
    digitalWrite(IN3, HIGH);
    delay(sure);
    digitalWrite(IN3, LOW);
    digitalWrite(IN2, HIGH);
    delay(sure);
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, HIGH);
    delay(sure);
    digitalWrite(IN1, LOW);
  }
}
void SaatTersYonu(int adimSayisi) {
  for (int i = 0; i < adimSayisi; i++) {
    digitalWrite(IN1, HIGH);
    delay(sure);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    delay(sure);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    delay(sure);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(sure);
    digitalWrite(IN4, LOW);
  }
}
