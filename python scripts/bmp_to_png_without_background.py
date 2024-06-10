import cv2
import numpy as np

bgcolor = [255, 255, 0]  # BGR value of background color
arr = ["01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14"]
for i in range(len(arr)):
    img = cv2.imread(f'dirt{arr[i]}.bmp')
    image = cv2.cvtColor(img, cv2.COLOR_BGR2BGRA)
    image[np.all(image == bgcolor + [255], axis=2)] = [0, 0, 0, 0]
    cv2.imwrite(f'0_{i}.png', image)  # File will be saved as output.png in the current directory.
