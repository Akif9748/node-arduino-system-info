# Nodejs Arduino System Info
See your system information on LCD with Arduino!
You can see RAM usage, and CPU usage.
## Requipments:
- An Arduino Board. **[ You can use all type of Arduino types *(Leonardo, UNO, Mega etc.)* ]**
- A 16X2 *(Minimum)* LCD Shield **with or without I2C**
- Nodejs in your computer

**If your LCD Without I2C, you need:**
- A 10K potentiometer 
- A 220 Ohm resistor 


## How to use?
1. Download this repo.
2. If you have I2C upload code named `systeminfoI2C.ino`,else `systeminfo.ino` to your Board.
3. Connect pins. Look under for this. And connect your board to your computer.
4. Write `npm i` to console in project folder.
5. Write your COM port to code:
```js
const port = new SerialPort('COM3', { baudRate: 9600 });
```
6. And finaly, Write `node index.js` to console and you can see your System Info on LCD.
Image at working:
![image](https://user-images.githubusercontent.com/70021050/147857017-f1ea1fb9-cfdc-4139-93a1-c50da9da4bb0.jpg)

Circuit of Project for **NOT I2C**:
![tinkercad](https://user-images.githubusercontent.com/70021050/147857009-69643cf9-e338-4abb-81e5-e55f44b51196.png)

**For I2C**:
![image](https://user-images.githubusercontent.com/70021050/147857874-e9ff53cb-1a57-4f7c-a34b-258d9aaa5340.png)
