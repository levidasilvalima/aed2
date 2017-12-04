# Description:
#   This script compile C++ program, with g++ version 11
#   in restricted mode
#
# USAGE:
# $> ./compile.sh PROGRAM_NAME COMPILED_NAME_OUTPUT

PROGRAM_NAME=$1 # Program to compile
COMPILED_NAME_OUTPUT=$2 # Output file with compile of PROGRAM_NAME

# Restricted mode line command
g++ -std=c++11 -Wunused-but-set-variable -Wunused-variable -Wall -Wextra -Wshadow -Wstrict-aliasing -pedantic -fmax-errors=5 -Werror -Wunreachable-code -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option $PROGRAM_NAME -o script/$COMPILED_NAME_OUTPUT
