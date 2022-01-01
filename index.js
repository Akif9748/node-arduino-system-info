const SerialPort = require('serialport');
const os = require('os-utils');

//Your com port and baudrate: (BaudRate is defined in Arduino Code, 9600.)
const port = new SerialPort('COM3', { baudRate: 9600 });

// Port ready message
port.on("open", () => {
  console.log('Serial is ready!');
});


setInterval(() => {
  const total = os.totalmem().toFixed(0);//Total memory on your system
  const used = (os.totalmem() - os.freemem()).toFixed(0);//Used memory on your system
  const ratio = 100 * ((used / total).toFixed(2));//Used memory / Total memory
  os.cpuUsage(usage => {//CPU USAGE
     /*
      A format for sending datas to Arduino.
      UsedRAM-UsedRAMRatio-CPUUsage
      For example:
      2824-69-10
     */
    port.write(`${used}-${ratio}-${usage.toFixed(2) * 100}`, (err) => {
      if (err) console.error(err);
    });

  });


}, 1000);//Refreshing per one second
