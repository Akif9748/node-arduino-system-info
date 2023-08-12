import SerialPort from 'serialport';
import { setTimeout } from "timers/promises"
import os, { totalmem, freemem } from 'os';
//Your com port and baudrate
const arduinoPORT = (await SerialPort.list()).find(port => port.manufacturer.includes('Arduino')).path || 'COM6';

const port = new SerialPort(arduinoPORT, { baudRate: 9600 });

// taken from os-utils
async function getCPUUsage() {
  const stats1 = await setTimeout(1000, getCPUInfo()),
    stats2 = getCPUInfo(),
    perc = (stats2.idle - stats1.idle) / (stats2.total - stats1.total);
  return Math.round(100 * (1 - perc));
}

function getCPUInfo() {
  const cpus = os.cpus(),
    types = { user: 0, nice: 0, sys: 0, idle: 0, irq: 0 };

  for (const cpu of cpus)
    for (const type in cpu.times)
      types[type] += cpu.times[type];


  types.total = Object.values(types).reduce((acc, type) => acc + type, 0)
  return types;
}

// Read the port data
port.on("open", () => console.log('Serial is ready on', arduinoPORT, 'port!'));

//Total Mem
const totalMem = totalmem() / 2 ** 20;
//Main interval
setInterval(async () => {
  //Memory usage:
  const memUsage = parseInt(totalMem - freemem() / 2 ** 20),
    memRatio = parseInt(100 * (memUsage / totalMem)),
    //CPU usage:
    cpuUsage = await getCPUUsage(),
    cpuRatio = cpuUsage < 10 ? `0${cpuUsage}` : cpuUsage,
    data = `${memUsage}-${memRatio}-${cpuRatio}         `;

  //Writing to port.
  port.write(data, err => err ? console.error(err) : null)

}, 1000);//Per 1000 ms