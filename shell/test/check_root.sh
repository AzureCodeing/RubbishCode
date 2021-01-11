#!/usr/bin/env bash

#检查当前用户是否是root
check_root(){                                                                                                                                         
    [[ $EUID != 0 ]] && echo -e "当前账号非ROOT(或没有ROOT权限)，无法继续操作，请使用sudo su 来获取临时ROOT权限（执行后会提示输入当前账号的密码）。" && exit 1
}


check_root