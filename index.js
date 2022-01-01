const SerialPort = require('serialport');
const os = require('os-utils');

//Your com port and baudrate
const port = new SerialPort('COM3', { baudRate: 9600 });

// Read the port data
port.on("open", () => {
  console.log('Serial is ready!');
});


setInterval(() => {
  const total = os.totalmem().toFixed(0);
  const used = (os.totalmem() - os.freemem()).toFixed(0);
  const ratio = 100 * ((used / total).toFixed(2));
  os.cpuUsage(usage => {

    port.write(`${used}-${ratio}-${usage.toFixed(2) * 100}`, function (err) {
      if (err) {
        console.log('error writing');
        console.error(err);
      };

    });

  });


}, 1000);//Per 1000 ms
