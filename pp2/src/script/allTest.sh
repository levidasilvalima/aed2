SEARCH_DIRECTORY=$1

for entry in $SEARCH_DIRECTORY*
do
    if ! grep -q "GraphBrain" $entry
        then
            ./script/compile-execute.sh $entry run
    else
        ./script/compile-execute.sh $entry run < cases/1.in
    fi
done
