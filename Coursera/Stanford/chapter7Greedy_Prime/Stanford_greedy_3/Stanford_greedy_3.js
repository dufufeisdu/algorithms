let fs = require('fs');
let data = fs.readFileSync(__dirname + '/edges.txt', 'utf8');
data = data.split('\n').map((ele) => (ele.split(' ').map((e)=>(parseInt(e)))));

