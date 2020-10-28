
import urllib.request
import numpy as np
import cv2
import os


# Simple Program Made for Scraping Images and Converting them to Black and White for CV2 Learning.

def fetch():
    neg_images_link = '' #url
    neg_image_urls = urllib.request.urlopen(neg_images_link).read().decode()
    pic_num = 1

    if not os.path.exists('neg'):
        os.makedirs('neg')

    for i in neg_image_urls.split('\n'):
        try:
            print(i)
            urllib.request.urlretrieve(i, "neg/"+str(pic_num)+".jpg")
            img = cv2.imread("neg/"+str(pic_num)+".jpg", cv2.IMREAD_GRAYSCALE)
            # should be larger than samples / pos pic (so we can place our image on it)
            resized_image = cv2.resize(img, (100, 100))
            cv2.imwrite("neg/"+str(pic_num)+".jpg", resized_image)
            pic_num += 1

        except Exception as e:
            print(str(e))


fetch()
