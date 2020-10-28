import json
import base64
data = {}

#save image as string in json
with open('encoded_image.png', mode='rb') as file:
    img = file.read()
data['image'] = base64.b64encode(img).decode('utf-8')
a = json.dumps(data)

#read image from json string
decoded = json.loads(a)
imgdata = base64.b64decode(decoded['image'])
with open('decoded_image.png', 'wb') as f:
    f.write(imgdata)
