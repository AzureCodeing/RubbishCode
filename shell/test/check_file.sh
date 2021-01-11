#!/usr/bin/env bash

#检查文件是否存在

#得到当前脚本存放路径
filepath=$(cd "$(dirname "$0")"; pwd)

check_file(){
    if [ ! -f  ${filepath}/README.md ]; then
        echo "不存在文件"
    else
        echo "文件存在"
    fi 
}

check_file