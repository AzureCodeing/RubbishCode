#!/bin/bash

kill_name='code-server'

while true
do
    tomcat_id=`ps -ef | grep $kill_name | grep -v "grep" | awk '{print $2}'`

    if [ ! "$tomcat_id" ]
    then
        echo "进程不存在,启动进程"
        export PASSWORD=ma190529
        sleep 2
        nohup /root/code-server2.1698-vsc1.41.1-linux-x86_64/code-server --port 8848  2>&1 &
        sleep 10 
    else
        echo "进程正常运行当中..."
    fi
    sleep 10
done