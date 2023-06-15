/**
 * @param {string} title
 * @return {string}
 */
var capitalizeTitle = function(title) {
    
    const str = title.toLowerCase();
    const arr = str.split(' ');
    arr.forEach((ele, i, arr)=>{
        if(ele.length>2)
        arr[i]=ele[0].toUpperCase()+ele.substring(1, ele.length);
    })
    
    return arr.join(' ');
};