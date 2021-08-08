# Bloom
A Bloom project for CSPB2270 final projects

For some computer science problems we need precision, for others, we simply need speed. Bloom filters are a wonderful option and save disk spac. 
Bloom filters will outperform alternatives, such as dicts, as there is no need to traverse disk. Bloom filters do not store data but instead make use of a bit vector. Adding an element to the Bloom filter requires hashing an object’s value and using these hash-values to set certain bits in the bit vector . For subsequent adds, if the specified index of the bit vector is flipped to 1, the object may already be present. If a song is deemed not to be present it can then be added to a playlist.  
 
Project has the following folder tree

.
├── CMakeLists.txt
├── CMakeLists.txt.in
├── README.md
├── app
│   └── main.cpp
├── build
├── code
│   ├── Bloom.cpp
│   └── Bloom.h
└── tests
└── test_Bloom.cpp

CMakeLists.txt : Ignore this file
CMakeLists.txt.in : Ignore this file
README.md : Readme file
app\ : Application folder
main.cpp : Application main file .
build\ : Build folder to build the project. 
code\ : all code in here 
Bloom.cpp : Bloom class source file
Bloom.h : Bloom class heather file
tests\ : Tests folder
test_Bloom.cpp : Tests

If you want to use linux terminal for comilation
Make sure you have the dependecies installed (ckeck dependencies in this document) go into your project folder, then build folder

jovyan@jupyter-yourcuid:~$ cd Bloomfilter
jovyan@jupyter-yourcuid:~$ cd build
run cmake to create make file for your project

jovyan@jupyter-yourcuid:~$ cmake ..
run make to compile your code

jovyan@jupyter-yourcuid:~$ make
once done, you can run tests by

jovyan@jupyter-yourcuid:~$ ./run_tests
app executable is also in this folder, you can run it by

jovyan@jupyter-yourcuid:~$ ./run_app
you can debug in terminal using gdb

Dependencies
you need gcc and cmake installed to be able to compile this code.
