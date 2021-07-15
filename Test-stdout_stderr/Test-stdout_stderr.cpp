/*
Example of stdout, stderr, and the return value of main().

compile:  
g++ Test-stdout_stderr.cpp -o test.run

run:
./test.run 1>out 2>err ; echo $?>return

This will create out, err, and return files. These files will contain whatever we print with cout, cerr, and the return value of main, respectively.


Or run commands.sh, in order to see some other things as well.
*/

#include<iostream>
#include<vector>




using namespace std;


int main(){
    cout<<"--stdout--\n"; //this preints to stdout (we can put this in a file using 1>file_name)
    cerr<<"--stderr--\n"; //this preints to stderr (we can put this in a file using 2>file_name)

    #if false //segfault retuns something other than 0 (139 as far as I have seen). You can allow this to run, and see it for yourself.
    vector<int> c{0,1,2};
    for(auto i = 0; i<1000000;++i){c[i]=1;} 
    #endif

    return 0;//retun value can be read by $? after we run the executable
}