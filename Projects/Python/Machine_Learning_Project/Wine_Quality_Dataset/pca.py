# PCA(Principle Component Analysis)
# PCA mainly tries to learn the relationship between the different values and then project the data from a higher dimension to a lower dimension while retaining most of the information. It is highly affected by the outliers in the data.
# Often, the desired goal is to reduce the dimensions of a d-dimensional dataset by projecting it onto a (k)-dimensional subspace (where k<d) in order to increase the computational efficiency while retaining most of the information.
# So mainly we need to reduce the dimensions and provide a simple dataset which can give excellent correlations and which when applied to a logistic regression model gives accurate results.

# Importing the libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Importing the dataset
# There are 13 columns-independent variables and only one dependent variable(last column),so the business owner-suppose if he takes a new obs then he shud be able to predict the customer segment(to which category it belongs to),the owner can recommend the new wine to the right customers
# For each new wine it tells us to which customer segment it will be more appropriate.
# He can build a logistic regression model and predict,but to see the visualizations we cant do it because there are 13 dimensions and cannot be visualized.So we need to apply dimensionality reduction techniques and reduce the dataset to a lower number of features.
dataset = pd.read_csv('Wine_Quality.csv')  #Those are all the chemicals in the wine and then by applying clustering technique we get to know which cluster they belong to
#The extracted features are called principal components.
X = dataset.iloc[:, 0:13].values # 0-12 indexes so 13 columns
y = dataset.iloc[:, 13].values # Index of last column-dependent variable

# Splitting the dataset into the Training set and Test set
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 0)

# Feature Scaling-there are 12 features so they can obviously be in different scales so its better to apply feature scaling in PCA
from sklearn.preprocessing import StandardScaler
sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)

# Just after the feature scaling and before fitting the logistic resgression model we need to apply PCA for the datatset.
# Applying PCA
from sklearn.decomposition import PCA  #import PCA class and then create an object/instance of it
pca = PCA(n_components = 2)  # no of principal components(no of extracted features-no of dimensions)
X_train = pca.fit_transform(X_train)   # So as usual fit and transform the PCA object to the training set
# So after applying pca.fit_transform first it will get the information from the X_train and then apply transformation for it to extract the features/components
X_test = pca.transform(X_test)   # We want to avoid information leakage on the test set that's why we only give transform on the test set ,if we give fit on the test set then we are trying to get some hints or information from test set which is not supposed to happen(information leakage)
explained_variance = pca.explained_variance_ratio_ # We generally take 2 features and visulize it, but if the visulizations are poor then we try with more number of features
# We can see the explained_variance column then it says that if we take first 2 components then it explains 37% of the variance,and similarly 37+19=56% of the variance(with 3 components)
# So the PCA class extracts the class that explains top 2 variance
# Now if we restart kernel and add components to be 2 then X_train will contain only 2 columns which will have the top2 PCs(that are scaled) that explain the most variants
# So now we have only independent variables and we fit the logistic regression model

# Fitting Logistic Regression to the Training set
from sklearn.linear_model import LogisticRegression #import LogisticRegression class
classifier = LogisticRegression(random_state = 0)  #create classififer object
classifier.fit(X_train, y_train)

# Predicting the Test set results
y_pred = classifier.predict(X_test) 

# Making the Confusion Matrix
from sklearn.metrics import confusion_matrix,accuracy_score
cm = confusion_matrix(y_test, y_pred) # here confusion matrix will be 3X3 and not 2X2,so 14 predictions correct in segment1,15 in segment 2,6 in 3 so 35 correct predictions out of 36 so thats a very good acuuracy(3 customer segments so thats why 3 classes in confusion matrix)
# only 1 incorrect prediction where real output is seg2 but we got the prediction as seg1
accuracy_score(y_test,y_pred) # So the accuracy is 97.22% which is very good

# Visualising the Training set results-finally the 12 features get reduced down to 2 features and we visualize those 2 features in 2 dimensions.
# Here we have an almost perfect seperation of all the 3 classes(there is only one incorrect prediction)
from matplotlib.colors import ListedColormap
X_set, y_set = X_train, y_train
X1, X2 = np.meshgrid(np.arange(start = X_set[:, 0].min() - 1, stop = X_set[:, 0].max() + 1, step = 0.01),
                     np.arange(start = X_set[:, 1].min() - 1, stop = X_set[:, 1].max() + 1, step = 0.01))
plt.contourf(X1, X2, classifier.predict(np.array([X1.ravel(), X2.ravel()]).T).reshape(X1.shape),
             alpha = 0.75, cmap = ListedColormap(('red', 'green', 'blue')))
plt.xlim(X1.min(), X1.max())
plt.ylim(X2.min(), X2.max())
for i, j in enumerate(np.unique(y_set)):
    plt.scatter(X_set[y_set == j, 0], X_set[y_set == j, 1],
                c = ListedColormap(('red', 'green', 'blue'))(i), label = j)
plt.title('Logistic Regression (Training set)')
plt.xlabel('PC1')
plt.ylabel('PC2')
plt.legend()
plt.show()

# Visualising the Test set results
# So our logistic regression model combined with PCA has worked well and was able to seperate these 3 classes properly-there is only 1 incorrect prediction which is excellent for a data scientist.
from matplotlib.colors import ListedColormap
X_set, y_set = X_test, y_test
X1, X2 = np.meshgrid(np.arange(start = X_set[:, 0].min() - 1, stop = X_set[:, 0].max() + 1, step = 0.01),
                     np.arange(start = X_set[:, 1].min() - 1, stop = X_set[:, 1].max() + 1, step = 0.01))
plt.contourf(X1, X2, classifier.predict(np.array([X1.ravel(), X2.ravel()]).T).reshape(X1.shape),
             alpha = 0.75, cmap = ListedColormap(('red', 'green', 'blue')))
plt.xlim(X1.min(), X1.max())
plt.ylim(X2.min(), X2.max())
for i, j in enumerate(np.unique(y_set)):
    plt.scatter(X_set[y_set == j, 0], X_set[y_set == j, 1],
                c = ListedColormap(('red', 'green', 'blue'))(i), label = j) # 3 prediction regions here so 3 colours
plt.title('Logistic Regression (Test set)')
plt.xlabel('PC1')
plt.ylabel('PC2')
plt.legend()
plt.show()
