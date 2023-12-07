#!/bin/bash

all_md5s=(MD5_*)

for ((i = 0; i < ${#all_md5s[@]}; i++)); do
    # include ssl and crypto
    gcc ${all_md5s[$i]} -o ${all_md5s[$i]%??} -lssl -lcrypto -w 
done


