ls -l | cat -e | awk '{if(NR%2!=0)print}'
