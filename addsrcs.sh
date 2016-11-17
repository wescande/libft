expr "$(ls srcs/*/* | sed -e "s/srcs\///" -e 's/$/\\/')" : "\(.*\).$"
