import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df = pd.read_csv("iris.csv")  
df.drop(['Id'], 1, inplace=True)
print('Dataset : \n')
print(df)

#dividing the dataset
x = df.iloc[:,:-1].values   #input
y = df.iloc[:,-1].values  #expected output

#splitting the dataset into train set and test set
from sklearn.model_selection import train_test_split
x_train,x_test, y_train, y_test = train_test_split(x, y, test_size = 0.25, random_state = 0)

#using K-Nearest Neighbors algorithm
from sklearn.neighbors import KNeighborsClassifier
clf=KNeighborsClassifier(n_neighbors = 5, metric = 'minkowski', p = 2)
clf.fit(x_train, y_train)

y_pred = clf.predict(x_test)

#Confusion Matrix
from sklearn.metrics import confusion_matrix, accuracy_score
cm = confusion_matrix(y_test, y_pred)
print('\n Confusion Matrix : \n', cm)

#Accuracy of the program
print('\n Accuracy : ', accuracy_score(y_test, y_pred))

#user input
SepalL = float(input('Enter Sepal Length(cm) : '))
SepalW = float(input('Enter Sepal Width(cm) : '))
PetalL = float(input('Enter Petal Length(cm) : '))
PetalW = float(input('Enter Petal Width(cm) : '))
print('\n Species : ', clf.predict([[SepalL, SepalW, PetalL, PetalW]]))