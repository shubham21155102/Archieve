// console.log("hii")
const spawn=require("child_process").spawn;
var process = spawn('python',`C:\Users\Satyam\Desktop\Shubham_Notes\Backend\Redis\HBH.py` ); 
process.stdout.on('data', function(data) { 
console.log(data.toString());
} ) 