#!/bin/sh

kill_name='code-server'

tomcat_id=`ps -ef | grep $kill_name | grep -v "grep" | awk '{print $2}'`

echo $tomcat_id

for id in $tomcat_id
do
	kill -9 $id
	echo "killed $id"  
done


sleep 2

nohup ./code-server --port 8848 > temp.data 2>&1 &

sleep 2

if [ -e temp.data ]
then
   	passwd=`cat temp.data | grep Password`
	echo $passwd
	echo ${passwd:22}
    echo '文件存在,正在删除文件...'
    rm -rf temp.data
fi


