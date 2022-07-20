#!/bin/bash

echo "char *wordlist[`expr $(cat $1 | wc -l) + 1`] = {"
while IFS= read -r line; do
    echo -e "\t\"$line\","
done < $1
echo "};"
