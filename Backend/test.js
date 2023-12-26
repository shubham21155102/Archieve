// const { execSync } = require('child_process');
// execSync('open https://www.bing.com/search?q=Bing%20Homepage%20quiz1&form=ML2BF1&OCID=ML2BF1&PUBL=RewardsDO&PROGRAMNAME=BingDailyOfferIN&CREA=ML2BF1');
// execSync('open https://www.bing.com/search?q=Bing%20Homepage%20quiz2&form=ML2BF1&OCID=ML2BF1&PUBL=RewardsDO&PROGRAMNAME=BingDailyOfferIN&CREA=ML2BF1');
// execSync('open https://www.bing.com/search?q=Bing%20Homepage%20quiz3&form=ML2BF1&OCID=ML2BF1&PUBL=RewardsDO&PROGRAMNAME=BingDailyOfferIN&CREA=ML2BF1');
// execSync('open https://www.bing.com/search?q=Bing%20Homepage%20quiz4&form=ML2BF1&OCID=ML2BF1&PUBL=RewardsDO&PROGRAMNAME=BingDailyOfferIN&CREA=ML2BF1');
// execSync('open https://www.bing.com/search?q=Bing%20Homepage%20quiz5&form=ML2BF1&OCID=ML2BF1&PUBL=RewardsDO&PROGRAMNAME=BingDailyOfferIN&CREA=ML2BF1');
// execSync('open https://www.bing.com/search?q=Bing%20Homepage%20quiz6&form=ML2BF1&OCID=ML2BF1&PUBL=RewardsDO&PROGRAMNAME=BingDailyOfferIN&CREA=ML2BF1');
// execSync('open https://www.bing.com/search?q=Bing%20Homepage%20quiz7&form=ML2BF1&OCID=ML2BF1&PUBL=RewardsDO&PROGRAMNAME=BingDailyOfferIN&CREA=ML2BF1');
// const EventEmitter=require("events");
// const event=new EventEmitter();
// event.on("sayMyName",()=>{
//     console.log("Your name is Shubham");
// });
// event.on("sayMyName",()=>{
//     console.log("Your name is Shubham Gupta");
// });
// event.on("sayMyName",()=>{
//     console.log("Your name is Shubham Gupta and you are a web developer");
// });
// event.emit("sayMyName");
const fs = require('fs');
let data = '';
let readStream = fs.createReadStream('Node_js.html');
readStream.setEncoding('UTF8');
readStream.on('data', function(chunk) {
    data += chunk;
});
readStream.on('end', function() {
    console.log(data);
});
readStream.on('error', function(err) {
    console.log(err.stack);
});
console.log("Program Ended");