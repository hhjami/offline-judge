# README #

This is a offline judge for automatic judging. Its based on shell scripting. Runs on linux. It's tested on ubuntu. But
should run fine on any linux distro.

### What is this repository for? ###

* This judge is a shell script designed to run in bash terminal. This is supposed to do automated judging where test files are supplied with each problem.
* Version 2.5

### Features ###

* Submitting a file and getting verdict for each case file
* Submit all the problems in the `submissions` folder at once
* Timeout after 3s for slow solutions
* Supports only C++ now.
* You can choose the problem and file using a text based menu
* It supports special judge. The format of the special judge is, `stdin: user output file`, `input.txt: judge input
  file`, `output.txt: judge answer file`. Special Judge file name should be `special.cpp`. It should output only `+Accepted`
  if the solution is correct. Anything else will lead the verdict to be `Failed`.
* Submitting all the files using `judgeAll.sh` script.

### How do I get set up? ###

* Copy your directory containing the problem description and I/O inside `Offline Judge` directory
* The file containing all the descriptions must be named `Problem Descriptions.docx` and this should kept in your directory (not inside any subdirectory)
* Each problem's I/O should be kept inside a subdirectory which should reside in your directory
* Inside each subdirectory of a problem, there should be judge input files, judge answer files. You may keep the judge solution as `solution.cpp`.
* The judge input files must be named 1.in, 2.in etc. There should not be any gap in the sequence. It must start from 1.in.
* The judge answer files must be named 1.ans, 2.ans etc. There should not be any gap in the sequence. It must start from 1.ans.
* 1.ans corresponds the judge answer for input in 1.in.
* If the problem requires a special judge, that should be kept inside the problem subdirectory named `special.cpp`.
* Run `makeoj.sh` using the command in terminal `./makeoj.sh [directoryName]`. In case, you can't run the script due to permission issue, please run `chmod +x makeoj.sh` to give the script execution permission.
* If you haven't given the directory name as argument, then input your folder name, when asked.
* Your localoj will be ready within the offline judge folder.
* The name of your localoj will be of the format `localoj_CURRENT_DATE`
* There is a directory named `testDirectory` which contains an example of problem set in required format. To test, run
  `./makeoj.sh`. When prompted `Enter the name of the directory:`, give `testDirectory` (Or run `./makeoj.sh
  testDirectory`. This should produce a new folder called `localoj_CURRENT_DATE`. See `How to use?` section of this readme, to use that. 
* This judge can test a solution on multiple test files. Maximum 99 test files can be given. If you want increase this, change the MXCS macro in genChecker.cpp.
* If your vim has a older version, you have to update vim. Otherwise vimcat (used for syntax highlighting) may give
  error.

### How to use? ###

* From the terminal change your current directory to the offline judge directory (usually named localoj) using `cd` command
* In terminal, run `./startJudge.sh`
* In case, you can't run that script for permission issue, please run `chmod +x startJudge.sh` to give the script
  execution permission.
* To use JudgeAll script, create a folder. Inside that copy the data folder of a particular localoj. Keep all the submitted codes in a folder named `submissions` and copy it inside the first created folder. Then run `judgeAll.sh`.

### Who do I talk to? ###

* Created by Hasnain Heickal, Assistant Professor, CSE, University of Dhaka, Bangladesh
* For any help, mail to hhjami@gmail.com
