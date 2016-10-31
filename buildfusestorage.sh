#! /bin/sh
if [ ! -d "azure-storage-cpp" ]; then
    git clone https://github.com/Azure/azure-storage-cpp.git
else
    cd azure-storage-cpp
    git pull
    cd ..
fi

apt-get install libboost-log-dev
apt-get install libboost-locale-dev
