SEARCH_DIRECTORY=$1

for entry in $SEARCH_DIRECTORY*
do
  ./script/compile-execute.sh $entry run
done


