#!/bin/bash


if [ $(id -u) -eq 0 ]; then
    read -p "Enter username:" username
    read -p "Enter key:" key
    egrep "^$username" /etc/passwd > /dev/null
    if [ $? -eq 0 ]; then
        echo "$username exists!"
        exit 1
    else
        useradd -m $username
        cd /home/$username
        mkdir .ssh
        chmod 755 .ssh
        chown ${username}:${username} .ssh
        echo $key > .ssh/authorized_keys
        chown ${username}:${username} .ssh/authorized_keys
        chmod 600 .ssh/authorized_keys
        if [ $? -eq 0 ]; then
            echo "user has been add to sytem"
        else
            echo "user add fail"
        fi
        exit 0
    fi
else
    echo "Only root may add a user to system"
    exit 2
fi


