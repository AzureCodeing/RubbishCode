#!/usr/bin/env bash

#检查系统类型
check_sys(){
    if [[ -f /etc/redhat-release ]]; then 
        release="centos"
    elif cat /etc/issue | grep -q -E -i "debian"; then 
        release="debian"
    elif cat /etc/issue | grep -q -E -i "ubuntu"; then 
        release="ubuntu"
    elif cat /etc/issue | grep -q -E -i "centos|red hat|redhat"; then 
        release="centos"
    elif cat /proc/version | grep -q -E -i "debian"; then 
        release="debian"
    elif cat /proc/version | grep -q -E -i "ubuntu"; then 
        release="ubuntu"
    elif cat /proc/version | grep -q -E -i "centos|red hat|redhat"; then 
        release="centos"
    fi   
    bit=`uname -m`
}

check_sys
echo ${release} ${bit}