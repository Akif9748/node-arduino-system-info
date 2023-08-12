#include <Wire.h>
#include <LiquidCrystal.h>

// LCD pins:
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// String max size: 65536-100-100
const int size = 14, strings_size = 3;

// For datas:
String ram, ramUsage, cpu;
char *strings[strings_size], *ptr = NULL;

void setup()
{
  // LCD size
  lcd.begin(16, 2);
  // Start a serial communication
  Serial.begin(9600);
}

void loop()
{
  // While getting data:
  while (Serial.available() > 1)
  {
    // Read serial
    String data = Serial.readString();
    char values[size];

    data.toCharArray(values, size); // String => Char
    ptr = strtok(values, "-");      // Split "-"

    for (int i = 0; i < strings_size; i++)
    {
      strings[i] = ptr;    // Save to Strings        
      ptr = strtok(NULL, "-"); // Split "-"
    }

    // Values:
    ram = strings[0];
    ramUsage = strings[1];
    cpu = strings[2];

    // Clear LCD
    lcd.clear();

    // Write to LCD
    lcd.setCursor(0, 0);
    lcd.print("RAM: " + ram + " %" + ramUsage);
    lcd.setCursor(0, 1);
    lcd.print("CPU: %" + cpu.substring(0, ((cpu.lastIndexOf('0') > 1) ? 3 : 2)));
  }
}
