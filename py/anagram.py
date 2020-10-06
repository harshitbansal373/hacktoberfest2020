str1 = input("Enter 1st string: ")
str2 = input("Enter 2nd string: ")
str1 = list(str1)
str2 = list(str2)
str1.sort()
str2.sort()
if str1 == str2:
    print("Anagram!")
else:
    print("Not Anagram!")
