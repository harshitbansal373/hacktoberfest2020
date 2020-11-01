import tweepy
import time

auth = tweepy.OAuthHandler(consumer_key, consumer_secret)  # auth keys can be obtained by making twitter developer account and then access API
auth.set_access_token(access_token, access_token_secret)

api = tweepy.API(auth)
user = api.me()
 
def lim_handle(cursor):
	try:
		while True:
			yield cursor.next()
	except tweepy.RateLimitError:
		time.sleep(350) # when we hit error the cursor stops clicking and rest for 350 sec
	for follower in tweepy.Cursor(api.followers).items():  #instead of going on everyone profile, we can use curson in tweepy 
		follower.follow()   # it'll follow them all
 
# we can use if follower.name == 'name' to follow a specific user
# we can also do follower.follower_count > 100:   and then follower.follow()
