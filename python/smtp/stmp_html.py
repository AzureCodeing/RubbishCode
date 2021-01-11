#!/usr/bin/env python
#coding=utf-8
import sys
import smtplib
from smtplib import SMTP_SSL
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.header import Header

host_server = 'smtp.qq.com' #smtp
sender_qq = '987244712@qq.com'
pwd = 'billbdbbcnaqbbgj'

sender_sina_mail = "987244712@qq.com"
receiver = '851045076@qq.com'
mail_title = '【阿里云服务器】'
mail_content = "你好,<p>这里是使用python登录qq邮箱发送HTML格式邮件的测试程序: </p><p><ahref='https://github.com/RainBowAurora'>github</a></p>"

msg = MIMEMultipart()
msg["Subject"] = Header(mail_title, 'utf-8')
msg["From"] = sender_sina_mail
msg["To"] = Header("测试邮箱", 'utf-8')

msg.attach(MIMEText(mail_content,'html', 'utf-8'))

try:
    smtp = SMTP_SSL(host_server)
    smtp.set_debuglevel(0)
    smtp.ehlo(host_server)
    smtp.login(sender_qq, pwd)
    smtp.sendmail(sender_sina_mail, receiver, msg.as_string())
    smtp.quit()
    print("邮件发送成功")
except smtplib.SMTPException:
    print("无法发送邮件")