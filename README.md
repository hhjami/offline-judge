# README #

This is a offline judge for automatic judging. Its based on shell scripting. Runs on linux. It's tested on ubuntu. But
should run fine on any linux distro.

### What is this repository for? ###

* This judge is basically a shell script designed to run in bash terminal. This is supposed to do automated judging where test files are supplied with each problem.
* Version 2.1

### Features ###

* Submitting a file and getting verdict for each case
* Submit all the problems in the submissions folder at once
* Timeout after 3s for slow solutions
* Supports only C++ now.
* You can choose the problem and file using a text based menu
* It supports special judge. The format of the special judge is, `stdin: user output file`, `input.txt: judge input
  file`, `output.txt: judge answer file`.

### How do I get set up? ###

* Copy your directory containing the problem description and I/O inside `Offline Judge` directory
* The file containing all the descriptions must be named `Problem Descriptions.docx` and this should kept in your directory (not inside any subdirectory)
* Each problem's I/O should be kept inside a subdirectory which should reside in your directory
* Inside each subdirectory of a problem, there should be judge input files, judge answer files. You may keep the judge solution as `solution.cpp`.
* The judge input files must be named 1.in, 2.in etc. There should not be any gap in the sequence. It must start from 1.in.
* The judge answer files must be named 1.ans, 2.ans etc. There should not be any gap in the sequence. It must start from 1.ans.
* 1.ans corresponds the judge answer for input in 1.in.
* If the problem requires a special judge, that should be kept inside the problem subdirectory named `special.cpp`.
* Run `makeoj.sh` using the command in terminal `./makeoj.sh`.
* Input your folder name, when asked
* Your localoj will be ready within the offline judge folder.
* The name of your localoj will be of the format `localoj_CURRENT_DATE`
* To start the judge go to your localoj directory and run `./startJudge.sh`
* There is a directory named `testDirectory` which contains an example of problem set in required format.
* In case, you can't run a particular script due to permission issue, please run `chmod +x SCRIPT` to give that script
  execution permission.
* This judge can test a solution on multiple test files. Maximum 99 test files can be given. If you want increase this, change the MXCS macro in genChecker.cpp.

### How to use? ###

* From the terminal change your current directory to the offline judge directory using `cd` command
* In terminal, run `./startJudge.sh`
* In case, you can't run that script for permission issue, please run `chmod +x startJudge.sh` to give the script
  execution permission.

### Who do I talk to? ###

* Created by Hasnain Heickal, Lecturer, CSE, University of Dhaka, Bangladesh
* For any help mail to hhjami@gmail.com
