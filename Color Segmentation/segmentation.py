import cv2
import numpy as np

class CRect(object):
    def __init__(self, tL, bR):
        self.tL = tL
        self.tR = (bR[0], tL[1])
        self.bL = (tL[0], bR[1])
        self.bR = bR
        self.top = tL[1]
        self.bottom = bR[1]
        self.left = tL[0]
        self.right = bR[0]
        self.width = bR[0]- tL[0]
        self.height = bR[1] - tL[1]


class ColorDetector(object):
    def __init__(self):
        self.teach_flag = False
        self.h_max = 0
        self.h_min = 0
        self.s_max = 0
        self.s_min = 0
        self.v_max = 0
        self.v_min = 0

    def __get_crop_img(self, src, x, y, h, w, offset=0):
        output = src[max(0, y - offset):min(y + h + (2 * offset), src.shape[0] - 1),
                 max(0, x - offset):min(x + w + (2 * offset), src.shape[1] - 1)]
        return output

    def __get_patch_hsv_range(self, img, rect_roi):
        hsv_img = img.copy()
        hsv_img = cv2.medianBlur(hsv_img, 5)
        hsv_img = self.__get_crop_img(hsv_img, rect_roi.tL[0], rect_roi.tL[1], rect_roi.height, rect_roi.width)
        h_chan, s_chan, v_chan = cv2.split(hsv_img)
        min_max_list = []
        hsv_channel = [h_chan, s_chan, v_chan]
        for n, chan in enumerate(hsv_channel):
            min_max_list.append(np.max(chan))
            min_max_list.append(np.min(chan))
        return min_max_list

    def select_color(self, insp_img):
        str = "Image"
        canvas_img = insp_img.copy()
        hsv_img = cv2.cvtColor(insp_img, cv2.COLOR_BGR2HSV)
        cv2.putText(canvas_img, "Draw a rectangle inside target object", (5, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0,255,0), 2, cv2.LINE_AA)
        cv2.putText(canvas_img, "Press 'Enter' once done", (5, 60), cv2.FONT_HERSHEY_SIMPLEX, 1, (0,255,0), 2, cv2.LINE_AA)
        cv2.namedWindow(str, cv2.WINDOW_NORMAL)
        x, y, w, h = cv2.selectROI(str, canvas_img, False)
        self.teach_flag = True

        if w is not 0 and h is not 0:
            roi_tl = (x, y)
            roi_br = (x + w, y + h)
            rect_roi = CRect(roi_tl, roi_br)
            self.h_max, self.h_min, \
            self.s_max, self.s_min, \
            self.v_max, self.v_min = self.__get_patch_hsv_range(hsv_img, rect_roi)
        else:
            self.h_max, self.h_min, \
            self.s_max, self.s_min, \
            self.v_max, self.v_min = 0,0,0,0,0,0

    def detect_color(self, insp_img):
        hsv_img = cv2.cvtColor(insp_img, cv2.COLOR_BGR2HSV)
        lower_color = np.array([self.h_min, self.s_min, self.v_min])
        upper_color = np.array([self.h_max, self.s_max, self.v_max])
        mask = cv2.inRange(hsv_img, lower_color, upper_color)
        output = insp_img.copy()
        output[np.where(mask == 0)] = 0
        return output


if __name__ == '__main__':
    org_img = cv2.imread("candy.png")
    detector = ColorDetector()

    while True:
        k = cv2.waitKey(20)

        display_img = org_img.copy()
        insp_img = org_img.copy()

        if k == 13:  # press enter teach mode
            detector.select_color(insp_img)

        if detector.teach_flag is True:
            output_img = detector.detect_color(insp_img)
            cv2.imshow("Output", output_img)

        cv2.imshow("Image", insp_img)

