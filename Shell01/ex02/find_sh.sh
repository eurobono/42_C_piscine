find . -name "*.sh" -print0 | xargs -0 -n 1 basename -s .sh
