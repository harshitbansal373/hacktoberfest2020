# Python code to demonstrate 
# removal of dict. pair  
# using del 
  
# Initializing dictionary 
test_dict = {"Arushi" : 22, "Anuradha" : 21, "Mani" : 21, "Haritha" : 21} 
  
# Printing dictionary before removal 
print ("The dictionary before performing remove is : " + str(test_dict)) 
  
# Using del to remove a dict 
# removes Mani 
del test_dict['Mani'] 
  
# Printing dictionary after removal 
print ("The dictionary after remove is : " + str(test_dict)) 
  
# Using del to remove a dict 
# raises exception 
del test_dict['Manjeet'] 
