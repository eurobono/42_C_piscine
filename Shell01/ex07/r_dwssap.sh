cat /etc/passwd | grep -v '#' | awk 'NR%2==0' | awk -F ':' '{print $1}' | rev | sort -r | awk '$0 >= $FT_LINE1 && $0 <= $FT_LINE2' | tr '\n' ',' | sed 's/,$//' | sed 's/,$//' | sed 's/.$/./'
