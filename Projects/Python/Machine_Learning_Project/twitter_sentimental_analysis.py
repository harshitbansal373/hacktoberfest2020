#Importing Libraries
import numpy as np
import pandas as pd
import re
import nltk
nltk.download('stopwords')
from nltk.corpus import stopwords
from sklearn.feature_extraction.text import CountVectorizer
from nltk.stem.porter import PorterStemmer
import matplotlib.pyplot as plt
from sklearn.externals import joblib 


#importing Dataset
dataset = pd.read_csv('train.csv')
dataset.head()
#Visualization of data
dataset.label.value_counts().plot(kind='pie', autopct='%1.0f%%', colors=["red", "green"])
df= pd.read_csv('test.csv')


#Cleaning of Train dataset

corpus = []
for i in range(0,10000):
    #Selecting the useful things
    review=re.sub("(@[A-Za-z0-9]+)|([^0-9A-Za-z \t])|(\w+:\/\/\S+)"," ",dataset['tweet'][i])
    #Changing case of alpahbe
    review = review.lower()
    #Splitting the sentence
    review = review.split()
    #Removing unuseful words( like - is,the,this)
    review = [word for word in review if not word in stopwords.words('english')]
    #stemming(Finding root word from word by removing root word)
    ps = PorterStemmer()
    review = [ps.stem(word) for word in review]
    review=" ".join(review)  
    corpus.append(review)
    
#Cleaning of Test dataset    
testing = []
for i in range(0,3062):
    review = re.sub("(@[A-Za-z0-9]+)|([^0-9A-Za-z \t])|(\w+:\/\/\S+)"," ",df['tweet'][i])
    review = review.lower()
    review = review.split()
    review = [word for word in review if not word in stopwords.words('english')]
    ps = PorterStemmer()
    review = [ps.stem(word) for word in review]
    review=" ".join(review)  
    testing.append(review)    

#Making Features and labels using count Vectorizer   
cv = CountVectorizer()
features_train= cv.fit_transform(corpus).toarray() 
labels_train= dataset.iloc[:,1].values    
    
features_test = cv.transform(testing).toarray()

#Training of model using RandomForest
from sklearn.ensemble import RandomForestClassifier
classifier = RandomForestClassifier(n_estimators=100)
classifier.fit(features_train,labels_train)


#Saving the model

# Save the model as a pickle in a file 
joblib.dump(classifier, 'twitter.pkl') 
  
#Load the model from the file 
loading_model= joblib.load('twitter.pkl')  
  
#Use the loaded model to make predictions 
labels_pred=loading_model.predict(features_test)

# OR

"""            
import pickle
saved_model = pickle.dumps(classifier)

loading_saved_model = pickle.loads(saved_model)

labels_pred=loading_saved_model.predict(features_test) 
"""

#visualization of predicted data

df['labels_pred']=labels_pred
df.head()
df.labels_pred.value_counts().plot(kind='pie', autopct='%1.0f%%', colors=["red", "green"])
