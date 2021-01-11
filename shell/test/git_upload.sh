#!/bin/bash

now_date=`date -d "Dec 5, 2009 12:00:37 AM" +"%Y-%m-%d %H:%M.%S"`

cd /home/geek/code/

git_status=`git status -s`

if [ -n "$git_status" ]
then
    git add .
    git commit -m "$now_date"
fi
