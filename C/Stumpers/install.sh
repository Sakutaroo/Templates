#!/bin/sh

isFile() {
  if  [ ! -f "$1" ]
    then
      echo "Error: File '$1' missing."
      exit 1
  fi
}

checkFile() {
  if expr "$PATH" : "$PWD" > /dev/null
    then
      echo "Nothing to do: '$1' already in PATH."
      exit 0
  fi
}

if [ -z "$HOME" ] || [ -z "$SHELL" ] || [ -z "$PWD" ]
  then
    echo "Error: Environment HOME, SHELL or PWD variables not set."
    exit 1
fi
isFile "$HOME/.${SHELL##\/*\/}rc"
checkFile "$@"
echo "export PATH=$PWD:\$PATH" >> "$HOME/.${SHELL##\/*\/}rc"
echo "PATH variable updated. Please restart your shell."
