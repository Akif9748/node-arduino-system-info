#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD SIZE:
LiquidCrystal_I2C lcd(0x27, 16, 2);
// Change address if this is not applicable. Example: 0x27,0x3F

// String max size: 65536-100-100
const int size = 14;

// For datas:
String ram, ramUsage, cpu;
char *strings[size], *ptr = NULL;

void setup()
{
    // LCD
    lcd.begin();
    lcd.backlight();
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

        int index = 0;
        while (ptr != NULL)
        {
            strings[index] = ptr; // Save to Strings
            index++;
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
        lcd.print("CPU: %" + cpu);
    }
}
