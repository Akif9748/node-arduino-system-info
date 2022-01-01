# Nodejs Arduino System Info
###### See your system information on LCD with Arduino!
You can see RAM usage, and CPU usage.
## Requipments:
- An Arduino Board. **[ You can use all type of Arduino types *(Leonardo, UNO, Mega etc.)* ]**
- A 16X2 *(Minimum)* LCD Shield **with or without I2C**
- A 10K potentiometer 
- A 220 Omh resistor
- Nodejs in your computer


## How to use?
1. Download this repo.
2. Upload code named `systeminfo.ino` to your Board.
3. Connect pins. And connect your board to your computer.
4. Write `npm i` to console in project folder.
5. Write your COM port to code:
```js
const port = new SerialPort('COM3', { baudRate: 9600 });
```
6. And finaly, Write `node index.js` to console and you can see your System Info on LCD.
Image at working:
![image](https://user-images.githubusercontent.com/70021050/147857017-f1ea1fb9-cfdc-4139-93a1-c50da9da4bb0.jpg)

Circuit of Project:
![tinkercad](https://user-images.githubusercontent.com/70021050/147857009-69643cf9-e338-4abb-81e5-e55f44b51196.png)
