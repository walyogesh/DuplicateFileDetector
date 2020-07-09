# DuplicateFileDetector

#Description
This Programmer finds duplicate files by identifying similar file names/content in the file system.

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
1. basic:    unique files are identified by file name alone. 
2. extended: The contents of the file will also be matched.
   default mode is Basic Developer mode 

#Important Ponits to Note-
1. Supported file types:  *.c, *.h, *.cpp, and *.rc.
2. To view the output, Please check output.txt file in the same directory after programm finishes
3. Please ignore Extended mode : Extendend Mode is implemented partialy, So It will give same ooutput as basic mode,
   However i have written the algorithm in the comments. 
