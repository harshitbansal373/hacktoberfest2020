import pandas
import names
import random

i = 1
name = []
nameid = []
p = []
while (i <= 10):
    p.append(i)

    i = i + 1
    name.append(names.get_full_name(gender='male'))
    b = random.randint(1000, 9999)
    nameid.append(b)

dict = {'sno': p, 'name': name, 'name & id ': name, '': nameid}
df = pandas.DataFrame(dict)
df.to_csv('pames100.csv')
file = 'pames100.csv'
print(df)
t = int(input(" choose a row which you want to us information"))
for j in range(1, 11):
    if (t == j):
        print("name is : ", name[j - 1])
        print("name & id is : ", name[j - 1], nameid[j - 1])
