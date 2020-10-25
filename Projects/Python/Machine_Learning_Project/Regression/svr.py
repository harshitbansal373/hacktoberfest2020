# SVR(Support Vector Regression)

# Importing the libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Importing the dataset
dataset = pd.read_csv('Position_Salaries.csv')
X = dataset.iloc[:, 1:2].values
y = dataset.iloc[:, 2].values

# The StandardScaler class expects the input in a certain format-the inputs(which are X,Y have to be represented in the form of a 2D array(so its necessary to give the inputs in the form of 2D arrays)

#print(X) Here X is in the form of a 2D array
#print(y) Y is in the form of series and not in a 2D array

# We need to reshape Y here(have to convert it into a 2D array)
y=y.reshape(len(y),1) # reshape take the arguments as the no of rows and columns
#print(y)

# Splitting the dataset into the Training set and Test set
"""from sklearn.cross_validation import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 0)"""

# Feature Scaling
# In the preprocessing pat we have applied feature scaling only for the independent variables but not the dependent variable.
# In that case we had a binary outcome of 0,1 so that's why we did not apply feature scaling but in this case the range of salaries are spread out from 45K to 1 million dollars
# So we need to get them down to a proper scale so that's why we have to apply feature scaling so that they can be compared.
# Here we are not splitting the dataset so that's why we have to apply feature scaling on the whole dataset(and not on X_train and Y_train)
# After getting the results we get the scaled answer so to visualize the results we need to convert it back to the original scale(so then only we'll be able to get the predicted salary)-Inverse Feature Scaling


from sklearn.preprocessing import StandardScaler
# StandardScaler is nothing but standardization
# For every value we calculate (X-mean)/standard deviation
sc_X = StandardScaler()
sc_y = StandardScaler() 
y = sc_y.fit_transform(y) #We create objects of the StandardScaler class and then try to fit it to the model,basically fit and then the transform scales our features-X,y
X = sc_X.fit_transform(X)

print(X)
print(y) # So here we get the scaled values of X and y-now we can compare the values

# Fitting SVR to the dataset
from sklearn.svm import SVR
regressor = SVR(kernel = 'rbf')  # Most common kernels are linear,gaussian,polynomial kernels but here we take the RBF kernel,as this is a non-linear curve so here we choose a non-linear kernel
regressor.fit(X, y) # Training the dataset

# Predicting a new result
#y_pred = regressor.predict(6.5) # here this method is wrong since X,y are on different scales so we wont get an accurate result here
y_pred=regressor.predict(sc_X.transform([[6.5]]))# this is the correct method since apply predictions on the scale of X
 # After applying the prediction we get a scaled value and we need to convert that value again into the scale of Y
sc_y.inverse_transform(regressor.predict(sc_X.transform([[6.5]]))) # So thats's why we use the inverse_transform method(to convert the scaled value to the original scale-in terms of 1000dollars)
# The polynomial regression model predicted the salary to be 158K and this model showed us 170K-both the models are close and have given a decent prediction(level of 6.5)

# Visualising the SVR results
plt.scatter(sc_X.inverse_transform(X),sc_X.inverse_transform(y), color = 'red') # Scatter plot for the observation-gives us all the data points
# Now the X,y are in a different scale(scaled values) but we want the scatter plot of the original values so that's why again we apply the inverse_transform method
plt.plot(sc_X.inverse_transform(X),sc_y.inverse_transform(regressor.predict(X))) # here again we plot the X values and the predicted values
# For predicting the values they have to be in the scale of y(so thats why we give sc_y.inverse_transform)-so predict the values of X and then convert back into y's scale
# X,y so X is nothing but the original values so thats why inverse_transform so X also
plt.title('Truth or Bluff (SVR)')
plt.xlabel('Position level')
plt.ylabel('Salary')
plt.show() #Generally when we use other classes like LinearRegression etc.it automatically does the feature scaling so thats why we dont apply it explicitly,
#But here SVR is a low/small class and SVR is not a very common model,so it seems that it has not applied feature scaling here so thats why our graph is not at all proper so we need to aply the feature scaling here

# Visualising the SVR results (for higher resolution and smoother curve)
X_grid = np.arange(min(sc_X.inverse_transform(X)), max(sc_X.inverse_transform(X)), 0.01) # choice of 0.01 instead of 0.1 step because the data is feature scaled
X_grid = X_grid.reshape((len(X_grid), 1))
plt.scatter(sc_X.inverse_transform(X),sc_X.inverse_transform(y), color = 'red')
plt.plot(X_grid,sc_y.inverse_transform(X),sc_y.inverse_transform(regressor.predict(sc_X.transform(X_grid))),color='blue')
plt.title('Truth or Bluff (SVR)')
plt.xlabel('Position level')
plt.ylabel('Salary')
plt.show()