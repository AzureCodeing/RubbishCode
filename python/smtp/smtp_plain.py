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
mail_content = "这是邮件的正文内容"

msg = MIMEMultipart()
msg["Subject"] = Header(mail_title, 'utf-8')
msg["From"] = sender_sina_mail
msg["To"] = Header("测试邮箱", 'utf-8')

msg.attach(MIMEText(mail_content,'plain', 'utf-8'))

smtp = SMTP_SSL(host_server)
smtp.login(sender_qq, pwd)
smtp.sendmail(sender_sina_mail, receiver, msg.as_string())

smtp.quit()