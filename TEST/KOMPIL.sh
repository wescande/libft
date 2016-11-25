make -j
gcc -I includes -L ./ -lftprintf -o output test.c
echo "test : "
./output
