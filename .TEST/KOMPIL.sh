make -j -C ../
gcc test.c -I ../includes -L ../ -lft -o ./output 
echo "test : "
./output
rm ./output
