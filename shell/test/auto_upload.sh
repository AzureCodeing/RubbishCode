#!/bin/bash   
  
#版本部署路径  
mainpath="/home/code"

#备份版本包  
deploy_backup()  
{  
cd ${mainpath}/webapps/;  
tar -zcvf epc_`date +%y%m%d%H%M%S`.tar.gz epc;  
sleep 3  
ls;  
mv *.tar.gz ${mainpath}/backup/;  
}  
  
#解压版本包  
deploy_unzip()  
{  
cd ${mainpath};  
ls;  
sleep 3;
git clone https://github.com/ZROS/
#unzip -l *.zip;  
unzip -o -d ./tomcat8/webapps/epc pc.zip;  
sleep 3；  
}  
    
deploy_restart()  
{  
cd ${mainpath}/tomcat8/;  
pid1=`ps -ef|grep auto_upload |awk '{print $2}'`  
echo $pid1  
if [ -z $pid1 ]; then  
        echo "not exist"  
        ./start.sh;
        exit 1  
else  
        echo "restarting"  
        kill -9 $pid1  
        sleep 5  
        ./startup.sh;  
fi  
}  
  
#版本回滚  
deploy_Rollback()  
{  
#进入备份文件夹  
    cd ${mainpath}/backup/  
    #获取最新备份文件  
    file_name_new=''  
    for i in `ls -tr`;  
    do  
        echo $i;  
        file_name_new=$i;  
    done;  
    #将备份文件复制到webapps  
    cp  ${mainpath}/backup/${file_name_new} ${mainpath}/tomcat8/webapps  
    if [ $? -eq 0 ]  
    then  
        echo "复制${file_name_new}成功"
    else  
        echo "复制失败，退出"  
    exit 1  
    fi  
    #进入webapps/目录  
    cd  ${mainpath}/tomcat8/webapps  
    #解压文件  
    echo "正在解压，请稍后..."
    tar -zxvf ${file_name_new}  
    #重启tomcat  
    deploy_restart  
}  
  
  
echo --------欢迎使用shell自动部署脚本--------  
echo -e "请输入对应的操作编号：\n0.版本包回滚;\n其他键.一件部署;"  
#获取用户操作  
read wm2  
case $wm2 in  
0)  
    deploy_Rollback  
    ;;  
*)  
    deploy_backup  
    deploy_unzip  
    deploy_restart  
    ;;  
esac  