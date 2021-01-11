#!/usr/bin/env bash

#变量前面加''可以将其转换为字符
server_name=''$1

#检查任务进程
check_pid(){
    PID=`ps -ef |grep -v grep | grep ${server_name} |awk '{print $2}'`                                                                                     
}

check_pid 
echo ${PID}