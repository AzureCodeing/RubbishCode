# !/usr/bin/python3
# -*- coding: UTF-8 -*-

import urllib
import urllib.request
import time
import base64

#API产品路径
host = 'https://maskface.market.alicloudapi.com'
path = '/ai_image_detect/ai_maskface/v1'
#阿里云APPCODE
appcode = '320d8c2b75bd4db99cf4ea0aa30bafb8' 
bodys = {}
url = host + path

#内容数据类型，如：0，则表示BASE64编码；1，则表示图像文件URL链接

#启用BASE64编码方式进行识别
#内容数据类型是BASE64编码
f = open(r'/home/rainbow/test/python/fice/1.jpg', 'rb')
contents = base64.b64encode(f.read())
f.close()
bodys['IMAGE'] = contents

post_data = urllib.parse.urlencode(bodys).encode('utf-8')
request = urllib.request.Request(url, post_data)
request.add_header('Authorization', 'APPCODE ' + appcode)
request.add_header('Content-Type', 'application/x-www-form-urlencoded; charset=UTF-8')
response = urllib.request.urlopen(request)
content = response.read()
if (content):
    print(content.decode('utf-8'))