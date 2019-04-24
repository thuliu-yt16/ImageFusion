from PIL import Image
import numpy as np

img = Image.open("test1_mask.jpg")

a = np.array(img)

h, w , n = a.shape

for r in range(h):
    for c in range(w):
        for k in range(3):
            if a[r][c][k] > 128:
                a[r][c][k] = 255
            else:
                a[r][c][k] = 0
        if a[r][c][0] == 255 and a[r][c][1] == 255 and a[r][c][2] == 255:
            print(r, c)
        
# print(a)
# new_img = Image.fromarray(a.astype('uint8'))
# new_img.show()
# new_img.save("test1_mask1.png")
