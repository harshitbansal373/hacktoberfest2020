//Selection Sort
//mrSidSat

function SelectionSort(arr)//Declare the function
{
    let i,j,minpos,temp;//declare the variable local to function to save heap space
    for(i=0;i<arr.length;i++)
    {
        minpos = i;
        for(j = i+1;j<arr.length;j++)//find the position of min element as minpos from i+1 to n-1
        {
            if(arr[j]<arr[minpos])minpos = j;
        }
        if(minpos !=i)
        {
            temp = arr[i];
            //swap the ith element and the minpos element
            arr[i] = arr[minpos];
            arr[minpos] = temp;

        }
    }
}
const arr = [12,11,1245,3,1,13,23,99];//take  a example array
SelectionSort(arr);//call the sorting function
console.log(arr);//check the result array;

/*
complexity :  O(n^2)
*/

//Selection Sort successfully implemented :)
             
