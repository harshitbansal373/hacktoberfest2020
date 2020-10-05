let missingAlphabets = (str) => {
  //create a new array and initilize it with 0
  let arr = new Array(26);
  arr.fill(0, 0, 25);
  
  //convert the string to lowercase
  str.toLowerCase();
 
  //Mark the present string as true
  for(let i = 0; i < str.length; i++){
     if (str[i] >= 'a' && str[i] <= 'z') {
          arr[str[i].charCodeAt(0) - 'a'.charCodeAt(0)] = true; 
     }
  }
  
 //Create the string of the missing alphabets
  let missing = '';
  for(let i = 0; i < arr.length; i++){
     if(!arr[i]){
       missing += String.fromCharCode(97 + i);
     }
  }
  
 return missing;
}
