from twilio.rest import Client 
 
account_sid = 'AC6c590908ec4cdf0f527e0e0b5aa5de48' 
auth_token = '43f2e3d30ef7552090ceac6bc146ed64' 
client = Client(account_sid, auth_token) 
 
message = client.messages.create( 
                              from_='+16177649537',  
                              body='hello boy ////',      
                              to='+918434383921' 
                          ) 
 
print(message.sid)
