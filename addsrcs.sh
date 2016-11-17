#ls srcs/*/* | sed -e "s/srcs\///" -e 's/$/\\/'
expr "$(ls srcs/*/* | sed -e "s/srcs\///" -e 's/$/\\/')" : "\(.*\).$"
#expr "$((ls srcs/*/* | sed -e "s/srcs\///" | awk 'length($1)>15{print}' | sed 's/$/\\/' | tr "\\" "\t" | sed 's/$/\\/' && ls srcs/*/* | sed -e "s/srcs\///" | awk 'length($1)<16{print}' | sed 's/$/\\/' | tr "\\" "\t" | sed 's/$/\\/' | tr "\\" "\t" | sed 's/$/\\/') | sort -fd)" : "\(.*\)..$"
