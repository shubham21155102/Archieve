console.log(NaN==NaN) // false
// why NaN is not equal to NaN?
// NaN is a special value in JavaScript, it means Not a Number
// NaN is not equal to NaN because NaN is not a number
console.log(NaN===NaN) // false

console.log(isNaN(NaN)) // true
console.log(isNaN(123))     // false
console.log(isNaN('123'))  // false
console.log(isNaN('123abc')) // true
console.log(isNaN(true)) // false
console.log(0=="") // true
console.log(0==[]) // true
console.log(0=={}) // false
console.log(0==null) // false
console.log(0==undefined) // false
console.log(''==[]) // true
console.log(''=={}) // false
console.log(''==null) // false
console.log(''==undefined) // false
console.log([]==[]) // false
console.log([]=={}) // false
console.log('b'+'a'+ +'a'+'a') // baNaNa
console.log('1'+2+3) // 123
console.log(1+2+'3') // 33
console.log('1'+2+3) // 123
console.log('1'+2+'3') // 123
console.log('1'+2+3) // 123
