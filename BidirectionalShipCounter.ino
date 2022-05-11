#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
#define in 8
#define out 9
#define led 10
int count=0;
void setup()
{
     lcd.begin(16,2);
     lcd.print("Ship Counter");
     delay(2000);
     pinMode(in, INPUT);
     pinMode(out, INPUT);
     pinMode(led, OUTPUT);
     lcd.clear();
     lcd.print("Ship in Dockyard:");
     lcd.setCursor(0,1);
     lcd.print(count);
  }
  void loop()
  {
     int in_value = digitalRead(in);
     int out_value = digitalRead(out);
     if(in_value == LOW)
     {
         count++;
         lcd.clear();
         lcd.print("Ships in Dockyard:");
         lcd.setCursor(0,1);
         lcd.print(count);
         delay(1000);
     }
     if(out_value == LOW)
     {
         count--; 
         lcd.clear();
         lcd.print("Ship in Dockyard:");
         lcd.setCursor(0,1);
         lcd.print(count);
         delay(1000);
     }
     if(count==0)
     {
         lcd.clear();
         digitalWrite(led, LOW);
         lcd.clear();
         lcd.print("No Ships there!");
         lcd.setCursor(0,1);
         lcd.print("Light is OFF");
         delay(200);
     }
  //Special case: When the number of people exceed the limit of 5
    if(count==5)
    {
       lcd.clear();
       lcd.print("Ship Limit Reach");
       delay(1000);
    }
    else
    {
      digitalWrite(led, HIGH);
    }
} 
