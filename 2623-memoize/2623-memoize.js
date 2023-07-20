/**
 * @param {Function} fn
 */


function memoize(fn) {
    let map1 = new Map();
    return function(...args) {
         let strArgs = args.join();
        if(!map1.has(strArgs)){
             let res=fn(...args);
            map1.set(args.join(), res);
        }
         return map1.get(strArgs); 
    }
}
// let callCount = 0;
// const memoizedFn = memoize(function (a, b) {
//  	 callCount += 1;
//      return a + b;
//   })
// console.log(memoizedFn(10,3));

/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */