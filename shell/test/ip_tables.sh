#!/usr/bin/env bash

#设置防火墙

#获取本机IP地址
ip=`wget -qO- -t1 -T2 ipinfo.io/ip`