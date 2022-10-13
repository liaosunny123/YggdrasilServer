# YggdrasilServer
This project is designed for WHU-Minecraft User Verify System.  
This project is based on [Authlib-injector](https://github.com/yushijinhun/authlib-injector) Standard.  
This project is a cpp version implement.  
# How to run this server  
## Prepare your Drogon Environment  
### First---Prepare your environment  
This project is developed on Ubuntu 22.04.  
Please verify your libs:g++,gcc,cmake,libjsoncpp-dev,uuid-dev,openssl,libssl-dev,zlib1g-dev  
This project supports Sqlite3,Redis,Mysql
### Seconde---Build your drogon
```bash
git clone https://github.com/drogonframework/drogon
cd drogon
git submodule update --init
mkdir build
cd build
cmake ..
make && sudo make install
```
If you want to make a release version , please use:
```bash
cmake -DCMAKE_BUILD_TYPE=Release ..
```
### Third---Build server
Please use cmake to make the program and run it.You can edit config in config.json  
Tips:This json supports "//" format.
### Other System
You can see drogon's install instruction.  
## Prepare Boost Libs
This project uses Boost Libs.  
You can install this lib using the code below:  
```bash
sudo apt-get install libboost-all-dev
```
Also , if you are not using Ubuntu System please try to learn how to install Boost on your system.  
# Project Structure
controllers: Controller for website  
mcmodel: JsonModel for user's post  
models: WebModels  
public: Website's running dir  
user: System basic model  
utility: Common tools for this project  

