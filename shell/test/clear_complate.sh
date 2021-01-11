#!/bin/bash

such_path="/home/geek/code/cpp/test/ "
# such_path+="/home/geek/code/c/ "

clear_complate(){

    for path in $*
    do
        find $path -name "*.out" -type f -print -exec rm -rf  {} \;
        find $path -name "tempCodeRunnerFile.cpp" -type f -print -exec rm -rf  {} \;
        # echo $path
        # clear_file_name=`find  $path -name "*.out"`
        # for file in $clear_file_name
        # do
        #     echo "clear $file"
        #     rm -rf $file
        # done
    done
}

clear_complate ${such_path}

