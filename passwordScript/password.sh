#!/bin/bash

echo -n "Enter a password"

IFS= read -r password

LEN=${#password}

[[ $(echo -n "$password" | wc -c) >= 8 ]] || echo "Password too short"

echo "$password" | grep -iq '[a-z]' || echo "Must contain a letter"

echo "$password" | grep -q '[0-9]' || echo "Must contain a number"

echo "$password" | grep -iq '[^a-z0-9]' || echo "Must contain special character"


