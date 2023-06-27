/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
  
    
    let arr = s.split(" ");
    arr.reverse();
    console.log(arr);
    
    let result='';
    for(let i=0;i<arr.length;i++){
        if(arr[i]!=''){
            result+= arr[i];
            result+= ' ';
        }
    }
    
    return result.slice(0, result.length-1);
    // return result;
};