SEARCH_DIRECTORY=$1

for entry in $SEARCH_DIRECTORY*
do
    if ! grep -q "GraphBrain" $entry
        then
            ./script/compile-execute.sh $entry run
        if ! [ $? -eq 0 ]; then
            clear
            echo "Error command: ./script/compile-execute.sh $entry run"
            echo
            ./script/compile-execute.sh $entry run
            break
        fi
    else
        ./script/compile-execute.sh $entry run < cases/1.in
        if ! [ $? -eq 0 ]; then
            clear
            echo "Error command: ./script/compile-execute.sh $entry run < cases/1.in"
            echo
            ./script/compile-execute.sh $entry run < cases/1.in
            break
        fi
    fi    
done
