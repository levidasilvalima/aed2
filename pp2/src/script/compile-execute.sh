# Description:
#   This script compile C++ program, with g++ version 11
#   in restricted mode and execute the compiled program
#
# USAGE:
# $> script/compile-execute.sh DIRECTORY/PROGRAM_NAME PROGRAM_COMPILED
# 
# OBS.: This script has to be execute inside src/ , same level folder of
#       lib/ script/ /template/ and test/

PROGRAM_NAME=$1 # IT DOES NOT HAVE SPACE, BEFORE OR AFTER '=' !!!!!
PROGRAM_COMPILED=$2 # IT DOES NOT HAVE SPACE, BEFORE OR AFTER '=' !!!!!

script/compile.sh $PROGRAM_NAME $PROGRAM_COMPILED
script/run.sh script/$PROGRAM_COMPILED

# Delete compiled file
rm script/run
