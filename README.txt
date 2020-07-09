# DuplicateFileDetector

#Description
This Programmer finds duplicate files by identifying similar files by comparing file names or content in the file system.

#Example-
We have tree projects, A,B and C. We have three files, fileX,fileY,fileZ. 
Files X and Y exist in projects A and B. File Z exist in all projects.
The output will be as follows:
/PathA
/PathB
	 fileX
	 fileY
--------------
/PathA
/PathB
/PathC
	fileZ
---------------

#How to Use: This Program take two command line agrument(both are optional) as follows -

/path: Specify path of the file directory on which you want to perform the operation. default path is current directory

/developerMode: Specify in which mode do you want to run the operation
1. basic:    unique files are identified by file name alone. 
2. extended: The contents of the file will also be matched.
   default mode is Basic Developer mode 

example: DuplicateFileDetector.exe /path:D:\Code\main\source\scimitar /developerMode:basic

#Important Points to Note-
1. Supported file types:  *.c, *.h, *.cpp, and *.rc.
2. To view the output, Please check output.txt file in the same directory after program finishes
3. Please ignore Extended mode : Extended Mode is implemented partially, So It will give the same output as basic mode,
   However I have written the algorithm in the comments.
4. Profiler class calculates the time required to execute the code in the given scope.
5. CommandLineOption class sets the program options, if a user enters the wrong path then programm will get terminated. 
6. c++17 standard filesystem is used to iterate through the file system, No external libs is used for this program.
7. File content can be compared parallel by using multithreading.
