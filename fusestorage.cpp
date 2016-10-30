 #include <fuse.h>
#include <stdio.h>

#include<iostream>
struct fuse_operations examplefs_oper;
 
 int main()
 {
     std::cout<<"Hello word!"<<std::endl;
     return 0;
 }
