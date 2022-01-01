#include <Wire.h>
#include <LiquidCrystal.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char *strings[10];   // For datas
char *ptr = NULL;    //
String kol_Str = ""; //

String lnk_1 = "";
String lnk_2 = ""; // For strings
String lnk_3 = "";

void setup()
{
  //LCD size
  lcd.begin(16, 2);
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
