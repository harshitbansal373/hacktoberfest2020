# Decision Tree Regression

# All the previous regression models were continuous-linear,multiple,polynomial(can be non-linear)
# This Decision Tree Regression is a non-linear and non-continuous regression-this regression is not much useful in 1D but its very powerful in higher dimensions

# Importing the libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Importing the dataset
dataset = pd.read_csv('Position_Salaries.csv')
X = dataset.iloc[:, 1:2].values
y = dataset.iloc[:, 2].values

# Splitting the dataset into the Training set and Test set
"""from sklearn.cross_validation import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 0)"""

# Feature Scaling
"""from sklearn.preprocessing import StandardScaler
sc_X = StandardScaler()
X_train = sc_X.fit_transform(X_train)
X_test = sc_X.transform(X_test)
sc_y = StandardScaler()
y_train = sc_y.fit_transform(y_train)"""

# Fitting Decision Tree Regression to the dataset
from sklearn.tree import DecisionTreeRegressor  #import that class and then create object of that class(regressor object)
regressor = DecisionTreeRegressor(random_state = 0)
regressor.fit(X, y)  #Now fit that regressor object to our dataset(matrix of features and the dependent vector)

# Predicting a new result
y_pred = regressor.predict([[6.5]])  #The regression model predicted 150K which is less than the actual salary which was 160K
y_pred # Here also we have got a similar output(same as the other 2 models)

# Visualising the Decision Tree Regression results  (higher resolution)
X_grid = np.arange(min(X), max(X), 0.01)
X_grid = X_grid.reshape((len(X_grid), 1))
plt.scatter(X, y, color = 'red')
plt.plot(X_grid, regressor.predict(X_grid), color = 'blue')
plt.title('Truth or Bluff (Decision Tree Regression)')
plt.xlabel('Position level')
plt.ylabel('Salary')
plt.show()
# In every interval we take the average of all the data points present in that interval,so for eg.from 2-4 it shud have a constant value(which will be the average)
# And similarly for other intervals also it shud have a constant value so it'll be in the form of steps and not in the form of curve(average of the dependent variables)
