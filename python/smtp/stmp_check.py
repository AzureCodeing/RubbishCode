#!/usr/bin/env python
#coding=utf-8

import sys
import time
import smtplib
from smtplib import SMTP_SSL
from email.header import Header
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.application import MIMEApplication


def mail_delivery(str):
    ticks = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()) 
    host_server = 'smtp.qq.com' #smtp
    sender_qq = '987244712@qq.com'
    pwd = 'billbdbbcnaqbbgj'

    sender_sina_mail = "987244712@qq.com"
    receiver = '851045076@qq.com'
    mail_title = '【阿里云服务器】'
    mail_content = ticks+str

    msg = MIMEMultipart()
    msg["Subject"] = Header(mail_title, 'utf-8')
    msg["From"] = sender_sina_mail
    msg["To"] = Header("测试邮箱", 'utf-8')

    msg.attach(MIMEText(mail_content,'plain', 'utf-8'))

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

if __name__ == "__main__":
    if sys.argv[1] == '0':
        print "服务器重启"
        mail_delivery(" 服务器发生重启，请确认是否为本人操作。\n 宝塔网址:http://123.56.246.106:8888/rainbow \n vscode网址:http://123.56.246.106:8848")

    if sys.argv[1] == '1':
        print "vscode发生错误"
        mail_delivery(" 发生错误，正在尝试重新启动vscode服务,请在接收次信息10秒钟后刷新网页. \n 宝塔网址:http://123.56.246.106:8888/rainbow \n vscode网址:http://123.56.246.106:8848")