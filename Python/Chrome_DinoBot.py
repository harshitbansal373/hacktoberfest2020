# importing above defined libraries to 
# implement the functionalities 
from PIL import ImageGrab, ImageOps 
import pyautogui 
import time 
import numpy as np 
	
class cordinates(): 

	# coordinates of replay button to start the game 
	replaybutton =(360, 214) 
	# this coordinates represent the top-right coordinates 
	# that will be used to define the front box 
	dinasaur = (149, 239 ) 
	
def restartGame(): 

	# using pyautogui library, we are clicking on the 
	# replay button without any user interaction 
	pyautogui.click(cordinates.replaybutton) 

	# we will keep our Bot always down that 
	# will prevent him to get hit by bird 
	pyautogui.keyDown('down') 

def press_space(): 

	# releasing the Down Key 
	pyautogui.keyUp('down') 

	# pressing Space to overcome Bush 
	pyautogui.keyDown('space') 

	# so that Space Key will be recognized easily 
	time.sleep(0.05) 

	# printing the "Jump" statement on the 
	# terminal to see the current output 
	print("jump") 
	time.sleep(0.10) 

	# releasing the Space Key 
	pyautogui.keyUp('space') 

	# again pressing the Down Key to keep my Bot always down 
	pyautogui.keyDown('down') 

def imageGrab(): 
	# defining the coordinates of box in front of dinosaur 
	box = (cordinates.dinasaur[0]+30, cordinates.dinasaur[1], 
		cordinates.dinasaur[0]+120, cordinates.dinasaur[1]+2) 

	# grabbing all the pixels values in form of RGB tupples 
	image = ImageGrab.grab(box) 

	# converting RGB to Grayscale to 
	# make processing easy and result faster 
	grayImage = ImageOps.grayscale(image) 

	# using numpy to get sum of all grayscale pixels 
	a = np.array(grayImage.getcolors()) 

	# returning the sum 
	print(a.sum()) 
	return a.sum() 
	
	

# function to restart the game 
restartGame() 
while True: 
	# 435 is the sum of white pixels values of box. 
	# You may get different value is you are taking bigger 
	# or smaller box than the box taken in this article. 
	# if value returned by "imageGrab" function is not equal to 435, 
	# it means either bird or bush is coming towards dinosaur 
	if(imageGrab()!= 435): 
		press_space() 
		# time to recognize the operation performed by above function 
		time.sleep(0.1) 
