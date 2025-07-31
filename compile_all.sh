find . -name "*.c" -print0 | xargs -0 -n 1 norminette
find . -name "*.c" -print0 | xargs -0 -n 1 cc -c -Wall -Wextra -Werror
