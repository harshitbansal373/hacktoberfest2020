class Print:
     def __init__(self,name):
          self.name=name
    def in_class(self):
        print("Function Inside Class")
        print("I am writing in "+self.name)        
Object=Print("Python")
Object.in_class()
