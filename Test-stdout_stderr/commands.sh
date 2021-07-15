#!/bin/bash

# run without segfault 
g++ Test-stdout_stderr.cpp -o test.run -DERR=false

# print cout (this is stdout) stream in the file out. 
# print cerr (this is stderr) stream in the file err, 
# print the return value in the file return.
./test.run 1>out 2>err ; echo $?>return 

# the pipe catches only stdout (stderr is still printed, but as you can see, grep counts 0 matches)
echo `./test.run 1>/dev/null | grep -c -E ".*"`


# you can send stderr to stdout using 2>&1 (grep counts 2 matches)
echo `./test.run 2>&1 | grep -c -E ".*"`

#if the return value is 0, it is equivalent to true
./test.run 1>/dev/null 2>/dev/null && echo "no error" || echo "oops! error"

# ---- compile and run with segfault  ---- #
g++ Test-stdout_stderr.cpp -o test.run -DERR=true


#if the return value is not 0, it is equivalent to false
./test.run 1>/dev/null 2>/dev/null && echo "no error" || echo "oops! error"

