import mysql.connector

#connecting
mydb = mysql.connector.connect(
  host="host_name",
  user="username",
  password="password_to_user",
  database="database_name",
)

mycursor = mydb.cursor()

code = input("Enter SQL code here: ")
sql = code
mycursor.execute(sql)

mydb.commit()
