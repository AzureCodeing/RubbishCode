#!/usr/bin/env python
#coding=utf-8
import sys
import smtplib
from smtplib import SMTP_SSL
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.header import Header
from email.mime.application import MIMEApplication


host_server = 'smtp.qq.com' #smtp
sender_qq = '987244712@qq.com'
pwd = 'billbdbbcnaqbbgj'

sender_sina_mail = "987244712@qq.com"
receiver = '851045076@qq.com'
mail_title = '【阿里云服务器】'
mail_content = "附件邮件测试"

msg = MIMEMultipart()
msg["Subject"] = Header(mail_title, 'utf-8')
msg["From"] = sender_sina_mail
msg["To"] = Header("测试邮箱", 'utf-8')

msg.attach(MIMEText(mail_content,'html', 'utf-8'))

attachment = MIMEApplication(open("/home/geek/code/python/smtp/README.md",'rb').read())
attachment.add_header('Content-Disposition', 'attachment', filename='smtp.md')
msg.attach(attachment)

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