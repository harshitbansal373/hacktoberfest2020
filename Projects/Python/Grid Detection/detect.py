import cv2
import numpy as np

img = cv2.imread('Sudoku.png')
#current_image = cv2.resize(img, (32, 32))
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
edges = cv2.Canny(gray, 50, 150, apertureSize=3)
cv2.imshow('edges', edges)
#lines = cv2.HoughLines(edges, 1, np.pi / 180, 200)
lines = cv2.HoughLinesP(edges,1,np.pi/180,100,minLineLength=100,maxLineGap=10)

for line in lines:
    x1,y1,x2,y2 = line[0]
    cv2.line(img,(x1,y1),(x2,y2),(0,255,0),2)
    
#for line in lines:
#    rho,theta = line[0]
#    a = np.cos(theta)
#    b = np.sin(theta)
#    x0 = a * rho
#    y0 = b * rho
#    # x1 stores the rounded off value of (r * cos(theta) - 1000 * sin(theta))
#    x1 = int(x0 + 1000 * (-b))
#    # y1 stores the rounded off value of (r * sin(theta)+ 1000 * cos(theta))
#    y1 = int(y0 + 1000 * (a))
#    # x2 stores the rounded off value of (r * cos(theta)+ 1000 * sin(theta))
#    x2 = int(x0 - 1000 * (-b))
#    # y2 stores the rounded off value of (r * sin(theta)- 1000 * cos(theta))
#    y2 = int(y0 - 1000 * (a))
#    cv2.line(img, (x1, y1), (x2, y2), (0, 0, 255), 2)


cv2.imshow('image', img)
k = cv2.waitKey(0)
cv2.destroyAllWindows()
