#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//LCD SIZE:
LiquidCrystal_I2C lcd(0x27,16,2); //Change address if this is not applicable. Example: 0x27,0x3F


char *strings[10];   // For datas
char *ptr = NULL;    //
String kol_Str = ""; //

String lnk_1 = "";
String lnk_2 = ""; // For strings
String lnk_3 = "";

void setup()
{
  //LCD
  lcd.begin();
  lcd.backlight();
  //Start a serial communication
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    while (Serial.available() > 0)
    {
      //  Read serial
      kol_Str = Serial.readString();
      int index = 0;
      char kolyedek[11];
      String kol_Str_yedek;
      kol_Str.toCharArray(kolyedek, 11); // String => Char

      ptr = strtok(kolyedek, "-"); // Split "-"
      while (ptr != NULL)
      {
        strings[index] = ptr; // Save to Strings
        index++;
        ptr = strtok(NULL, "-"); //Split "-"
      }

      lnk_1 = strings[0];
      lnk_2 = strings[1];
      lnk_3 = strings[2];
      //Clear LCD
      lcd.clear();
      //Write to LCD
      lcd.setCursor(0, 0);
      lcd.print("RAM: " + lnk_1 + " %" + lnk_2);
      lcd.setCursor(0, 1);
      lcd.print("CPU: %" + lnk_3);
    }
  }
}
