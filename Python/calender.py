# Program to display calendar of the given month and year

# importing calendar module
import calendar

dd=12
yy = 2014  # year
mm = 11    # month

# To take month and year input from the user
# yy = int(input("Enter year: "))
# mm = int(input("Enter month: "))

# display the calendar
print(calendar.month(yy, mm, dd))
