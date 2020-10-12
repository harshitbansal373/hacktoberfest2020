package com.javacodeexamples.stringexamples;
 
public class CountOccurrencesOfSubstringExample {
 
    public static void main(String[] args) {
        
        String str = "JavaExamplesJavaCodeJavaProgram";
        
        String strFind = "Java";
        int count = 0, fromIndex = 0;
        
        while ((fromIndex = str.indexOf(strFind, fromIndex)) != -1 ){
 
            System.out.println("Found at index: " + fromIndex);
            count++;
            fromIndex++;
            
        }
        
        System.out.println("Total occurrences: " + count);
    }
}
