#!/usr/bin/env python
#coding=utf-8

import os
import random,string    #调用random、string模块
from pipes import quote
from aliyunsdkcore.client import AcsClient
from aliyunsdkcore.request import CommonRequest

def GenPass():
    src_digits = string.digits              #string_数字  '0123456789'
    src_uppercase = string.ascii_uppercase  #string_大写字母 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    src_lowercase = string.ascii_lowercase  #string_小写字母 'abcdefghijklmnopqrstuvwxyz'
    src_special = string.punctuation        #string_特殊字符 '!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~'
 
    #sample从序列中选择n个随机独立的元素，返回列表
    num = random.sample(src_digits,2) #随机取1位数字
    lower = random.sample(src_uppercase,2) #随机取1位小写字母
    upper = random.sample(src_lowercase,2) #随机取1位大写字母
    special = random.sample(src_special,1)  #随机取1位大写字母特殊字符
    other = random.sample(string.ascii_letters+string.digits+string.punctuation,4) #随机取4位
    # 生成字符串
    # print(num, lower, upper, special, other)
    pwd_list = num + lower + upper
    # shuffle将一个序列中的元素随机打乱，打乱字符串
    random.shuffle(pwd_list)
    # 列表转字符串
    password_str = ''.join(pwd_list)
    print(password_str)
    return password_str


#阿里云短信服务发送
def ali_requerst(captcha):
    client = AcsClient('LTAI4FxeyRFbzKaAqG74cFUX', 'cCY63uWPhckMtqBDQWJvJdZFRSAnOg', 'cn-hangzhou')

    request = CommonRequest()
    request.set_accept_format('json')
    request.set_domain('dysmsapi.aliyuncs.com')
    request.set_method('POST')
    request.set_protocol_type('https') # https | http
    request.set_version('2017-05-25')
    request.set_action_name('SendSms')

    request.add_query_param('RegionId', "cn-hangzhou")
    request.add_query_param('PhoneNumbers', "13734816973")
    request.add_query_param('SignName', "个人服务器")
    request.add_query_param('TemplateCode', "SMS_183150377")

    passwd = {'code':captcha}

    #验证码
    request.add_query_param('TemplateParam', str(passwd))


    response = client.do_action(request)
    print(response) 


if __name__=='__main__':
    ali_requerst(GenPass())
