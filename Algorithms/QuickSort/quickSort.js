function quickSortBasic(array) {
  if(array.length < 2) {
    return array;
  }

  var pivot = array[0];
  var lesserArray = [];
  var greaterArray = [];

  for (var i = 1; i < array.length; i++) {
    if ( array[i] > pivot ) {
      greaterArray.push(array[i]);
    } else {
      lesserArray.push(array[i]);
    }
  }

  return quickSortBasic(lesserArray).concat(pivot, quickSortBasic(greaterArray));
}
