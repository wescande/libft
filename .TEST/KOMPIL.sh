make -j -C ~/Documents/libft/
gcc -I ../includes -L ../ -lft -o ./output test.c
echo "test : "
./output
rm ./output
