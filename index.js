const SerialPort = require('serialport');
const { totalmem, freemem, cpuUsage } = require('os-utils');
//Your com port and baudrate
const port = new SerialPort('COM3', { baudRate: 9600 });

// Read the port data
port.on("open", () => console.log('Serial is ready!'));

//Total Mem
const totalMem = totalmem();

//Main interval
setInterval(() => {
  //Memory usage:
  const memUsage = (totalMem - freemem()).toFixed(0),
    memRatio = 100 * (memUsage / totalMem).toFixed(2);

  //CPU usage:
  cpuUsage(usage =>
    //Writing to port.
    port.write(`${memUsage}-${memRatio}-${usage.toFixed(2) * 100}`, err => err ? console.error(err) : null)
  );

}, 1000);//Per 1000 ms
