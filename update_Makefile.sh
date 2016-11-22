sed "`grep -n 'SRC_BASE =' Makefile | sed 's/:.*//'`, \$d" Makefile > NEWMAKEFILE
grep 'SRC_BASE =' Makefile >> NEWMAKEFILE
expr "$(find ./srcs | grep "\.c" | sed -e 's/srcs\///' -e 's/\.\///' -e 's/$/\\/')" : "\(.*\).$" >> NEWMAKEFILE
echo "" >> NEWMAKEFILE
grep 'SRCS =' Makefile >> NEWMAKEFILE
sed "1, `grep -n 'SRCS =' Makefile | sed 's/:.*//'`d" Makefile >> NEWMAKEFILE
mv NEWMAKEFILE Makefile
