Given an array nums of n integers where n > 1, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input: [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).


let input = [1, 2, 3, 4];
let output = [];
let right = [];
let left = [];
left[0] = 1;
const limit = input.length;
right[limit - 1] = 1;
for (let i = 1; i < limit; i++) {
    left[i] = left[i - 1] * input[i - 1];
}

for (let i = limit - 2; i > -1; i--) {
    right[i] = right[i + 1] * input[i + 1];
}


for (let i = 0; i < input.length; i++) {
    output[i] = left[i] * right[i];
}

console.log(output);
