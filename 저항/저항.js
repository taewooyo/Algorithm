const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stout,
});

const colors = [
  'black',
  'brown',
  'red',
  'orange',
  'yellow',
  'green',
  'blue',
  'violet',
  'grey',
  'white',
];
const colorArr = [];

rl.on('line', line => {
  colorArr.push(line);
  if (colorArr.length === 3) rl.close();
}).on('close', () => {
  console.log(calculateResistorValues(colorArr));
  process.exit();
});

const calculateResistorValues = arr =>
  +(
    (colors.indexOf(arr[0]) * 10 + colors.indexOf(arr[1])) *
    10 ** colors.indexOf(arr[2])
  );