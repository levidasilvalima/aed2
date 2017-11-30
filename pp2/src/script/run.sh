# Description:
#   This script just execute program, if has to execute file
#   as input, add a parameter from command line and add
#   a variable to execute program, e.g.:
#       PROGRAM_COMPILED=$1
#       FILENAME=$2
#       ./$PROGRAM_COMPILED < $FILENAME
#
# USAGE:
# $> ./run.sh PROGRAM_COMPILED

# Recieve first parameter from command
PROGRAM_COMPILED=$1 # IT DOES NOT HAVE SPACE, BEFORE OR AFTER '=' !!!!!

# Execute program
./$PROGRAM_COMPILED # To get variable use $ before it
