#!/bin/bash
scritp_version="1.0"

Green_font_prefix="\033[32m" && Red_font_prefix="\033[31m" && Green_background_prefix="\033[42;37m" && Red_background_prefix="\033[41;37m" && Font_color_suffix="\033[0m"

Info="${Green_font_prefix}[信息]${Font_color_suffix}"
Error="${Red_font_prefix}[错误]${Font_color_suffix}"
Tip="${Green_font_prefix}[注意]${Font_color_suffix}"

filepath=$(cd "$(dirname "$0")"; pwd)
state_file="$filepath/state.log"
zr_log(){
  clear
  i=0
  array[0]='NAN'
  if [ ! -f $state_file ]; then 
    echo -e "$Error 文件不存在:$state_file"; return
  fi
    cat $state_file | while read line
  do
    ((i++))
    echo -e "${Green_font_prefix} $i. ${Font_color_suffix}${line}"
  done
  echo && read -e -p "请输入数字 [1-15]：" num
  node_name=`sed -n "${num}p" ${state_file}`
}

#查询节点状态
zr_status(){
  clear
  if [ ! -f $state_file ]; then 
    echo -e "$Error 文件不存在:$state_file"; return
  fi
  cat $state_file | while read line
  do
    tomcat_id=`ps -ef | grep $line | grep -v "grep" | awk '{print $2}'`
    if [ ! "$tomcat_id" ]
    then
        echo -e ${Red_font_prefix} "[Error]  " ${Font_color_suffix} "PID:NAN\t" ${Font_color_suffix} $line
    else
        echo -e ${Green_font_prefix} "[Succe]  " ${Font_color_suffix} "PID:$tomcat_id\t" ${Font_color_suffix} $line 
    fi
  done
  echo -e "
  ${Green_font_prefix}1.${Font_color_suffix}  杀死节点[需呀root用户权限]
  ${Green_font_prefix}2.${Font_color_suffix}  返回上一层
  "
  echo && read -e -p "请输入数字 [1-15]：" num
  case "$num" in
      1)
      check_root
      echo && read -e -p "请输要杀死节点的PID [1-15]：" pid
      # sudo kill -9 $pid
      ;;
      2)
      echo "2"
      ;;
      *)
      echo -e "${Error} 请输入正确的数字 [1-15]"
      ;;
      esac
}

check_root(){
    [[ $EUID != 0 ]] && echo -e "${Error} 当前账号非ROOT(或没有ROOT权限)，无法继续操作，请使用${Green_background_prefix} sudo su ${Font_color_suffix}>来获取临时ROOT权限（执行后会提示输入当前账号的密码）。" && exit 1
}

clear
echo -e "ZhenRobotics一键脚本管理 ${Green_font_prefix}[${scritp_version}]${Font_color_suffix}
${Green_font_prefix}1.${Font_color_suffix}　查看机器人节点状态
${Green_font_prefix}2.${Font_color_suffix}  查看机器人日志文件
"

echo && read -e -p "请输入数字 [1-15]：" num
case "$num" in
  1)
  zr_status
  ;;
  2)
  zr_log
  ;;
  3)
  echo "3"
  ;;
  4)
  echo "4"
  ;;
  5)
  echo "5"
  ;;
  *)
  echo -e "${Error} 请输入正确的数字 [1-15]"
  ;;
esac