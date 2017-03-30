LIBPATH="/Users/wescande/Documents/libft"
MYPATH=$(pwd)
CUR_MAKEFILE=$MYPATH/Makefile
if [ -e $LIBPATH ]
then
	echo "working from 42"
else
	LIBPATH="/home/william/Documents/libft"
	echo "working from house"
fi
if [ -e $CUR_MAKEFILE ]
then
	echo "regenerate Makefile"
	sed "`grep -n 'SRC_BASE	=' $CUR_MAKEFILE | sed 's/:.*//'`, \$d" $CUR_MAKEFILE > NEWMAKEFILE
	grep 'SRC_BASE	=' $CUR_MAKEFILE >> NEWMAKEFILE
	expr "$(find ./srcs | grep "\.c$" | sed -e 's/srcs\///' -e 's/\.\///' -e 's/$/\\/')" : "\(.*\).$" >> NEWMAKEFILE
	echo "" >> NEWMAKEFILE
	grep 'SRCS		=' $CUR_MAKEFILE >> NEWMAKEFILE
	sed "1, `grep -n 'SRCS		=' $CUR_MAKEFILE | sed 's/:.*//'`d" $CUR_MAKEFILE >> NEWMAKEFILE
	mv $CUR_MAKEFILE ~/Documents/.OLDMakefile
	mv NEWMAKEFILE $CUR_MAKEFILE
	echo "Makefile done (copy still alive in ~/Documents/.OLDMakefile)"
	if [ $# -eq 1 ]
	then
		if [ $1 = "-l" ]
		then
			if [ $MYPATH != $LIBPATH ]
			then
				echo "Refreshing from $LIBPATH"
				rm -rf $MYPATH/libft
				cp -r $LIBPATH $MYPATH/
				rm -rf $MYPATH/libft/.TEST
				rm -rf $MYPATH/libft/.git
				rm -rf $MYPATH/libft/update_makefile_dir.sh
				rm -rf $MYPATH/libft/scriptheader.sh
				echo "Refresh done"
			else
				echo "Libft dir detected. No refresh."
			fi
		else
			echo "Wrong arg, if you want to refresh libft use \"-l\"."
		fi
	fi
else
	echo "Makefile not found."
fi
