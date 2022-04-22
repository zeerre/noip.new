#!/bin/bash
#########################################################################
# File Name: cpfile.sh
# Author:GeelBear
# mail:zeerre98988@gmail.com
# Created And Modified Time: ====2022-03-22  21-33-13====
#########################################################################
cd /home/noi/geek/gitproject/github/noip.new.ssh/Geek_society_activity/Task_submit

for dir in $(dir)

do

[ -d $(dir) ] 

echo $(dir)/ | xargs -n 1 cp -v /home/noi/geek/gitproject/github/noip.new.ssh/Temp/shell_scripts_sources/20220422.md

done
