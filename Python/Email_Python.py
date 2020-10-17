import smtplib
smtp_object = smtplib.SMTP('smtp.gmail.com',587)
smtp_object.ehlo()
smtp_object.starttls()
import getpass# For hidden passwords
#Note for Gmail Users, you need to generate an app password instead of your normal email password.
#This also requires enabling 2-step authentication.
#Follow the instructions here to set-up 2-Step Factor Authentication as well as 
#App Password Generation:https://support.google.com/accounts/answer/185833?hl=en/.
#Set-up 2 Factor Authentication, then create the App Password,
#choose Mail as the App and give it any name you want. This will output a 16 letter password for you. 
#Pass in this password as your login password for the smtp.

email = getpass.getpass("Enter your email: ") #justforupload15pr@gmail.com
password = getpass.getpass("Enter your password: ") #wnxllfxuagzwjxlg
smtp_object.login(email,password)
from_address = email
to_address = getpass.getpass("Enter the email of the recipient: ")
subject = input("Enter the subject line: ")
message = input("Type out the message you want to send: ")
msg = "Subject: " + subject + '\n' + message
smtp_object.sendmail(from_address,to_address,msg)
smtp_object.quit()
