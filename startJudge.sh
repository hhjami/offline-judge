dataDirectory="data"
declare -a problemNames=
declare -a fileNameList=
numberOfProblems=
problemToBeSubmitted="#####"
fileNameToBeSubmitted=
numberOfFiles=
rollNo=
name=
fnameInSubmissionFolder=
configFileName="config"

#waits until an enter is pressed
#parameters: none
#returns: none
#entry point: doesn't matter
press_enter()
{
    echo -en "\nPress Enter to continue"
    read
    clear
}

#welcome screen
#parameters: configFileName
#returns: rollNo, name
#entry point: localoj
welcome()
{
    clear
    echo "Welcome to the offline judge 2.3"
    echo "To start please enter your details below"
    echo "You can also read the README.md to know more about this judge"
    echo -e "\n\n"
    if [ -f $configFileName ]; then
        rollNo=$(sed -n 1p "$configFileName")
        name=$(sed -n 2p "$configFileName")
        echo "You are already logged in as Roll: "$rollNo" and Name: "$name
    else
        rollNo=
        while [ -z "$rollNo" ]; do
            echo -n "Enter your Roll No: "
            read rollNo
        done
        name=
        while [ -z "$name" ]; do
            echo -n "Enter your Name: "
            read name
        done
        touch $configFileName
        echo $rollNo >> $configFileName
        echo $name >> $configFileName
    fi
    chmod +x vimcat
    press_enter
}

#populates problem set information
#parameters: dataDirectory
#returns: numberOfProblems, problemNames
#entry point: localoj
get_problemset_info()
{
    local idx=0
    cd $dataDirectory
    for i in *
    do
        problemNames[$idx]="$i"
        idx=$((idx+1))
    done
    cd ..
    numberOfProblems=${#problemNames[@]}
}

#chooses a particular problem for submission
#parameters: numberOfProblems, problemNames
#returns: problemToBeSubmitted
#entry point: localoj
problem_submission_menu()
{
    clear
    local selection=
    echo -e "CHOOSE THE PROBLEM YOU WANT TO SUBMIT\n\n"
    for (( i=1; i<= $numberOfProblems; i++ ))
    do
        echo $i" - "${problemNames[$i-1]} 
    done
    echo -e "\n0 - BACK\n\n"


    selection=
    while [ -z "$selection" ]; do
		echo -n "Enter your choice: "
		read selection
	done
    problemToBeSubmitted=
    if [ "$selection" > "0" ]; then
        if (( selection <= numberOfProblems )); then
            problemToBeSubmitted=${problemNames[$((selection-1))]}
        fi
    fi
    echo "Probem Chosen: "$problemToBeSubmitted
    press_enter
}

#chooses a particular file for submission
#parameters: none
#returns: fileNameToBeSubmitted
#entry point: localoj
file_chooser_menu()
{
    clear
    local idx=0
    local selection=
    echo -e "CHOOSE A FILE FROM BELOW TO SUBMIT\n\n"
    for i in *
    do
        fileNameList[$idx]="$i"
        idx=$((idx+1))
        echo $idx" - "${fileNameList[$idx-1]}
    done
    echo -e "\n0 - BACK\n\n"
    selection=
    while [ -z "$selection" ]; do
		echo -n "Enter your choice: "
		read selection
	done
    fileNameToBeSubmitted=
    numberOfFiles=${#fileNameList[@]}
    if [ "$selection" > "0" ]; then
        if (( selection <= numberOfFiles )); then
            fileNameToBeSubmitted=${fileNameList[$((selection-1))]}
        fi
    fi
    echo "File Chosen: "$fileNameToBeSubmitted
    press_enter
}

#runs special judge
#parameters: none
#returns: none
#entry point: localoj
run_special()
{
    local probDir=$dataDirectory
    probDir+="/"
    probDir+="$problemToBeSubmitted"
    if [ -d "$probDir" ]; then
        cd $dataDirectory/"$problemToBeSubmitted"/
        local i=
        local j=
        local k=
        local l=
        if [ $(find . -name "special.cpp") ]; then
            g++ special.cpp
            for i in *.in
            do
                j=`basename $i ".in"`".ans"
                k=`basename $i ".in"`".out"
                l=`basename $i ".in"`".status"
                cp $i input.txt
                cp $j output.txt
                ./a.out < $k > tmp
                cat tmp >> $l
            done
            rm tmp
            rm input.txt
            rm output.txt
        fi
        echo "finish"
        cd ../..
    fi
}

#runs a source file against the input files for a particular problem and creates user output files
#parameters: fileNameToBeSubmitted, problemToBeSubmitted
#returns: none
#entry point: localoj
run_code()
{
    local i=
    local j=
    local k=
    local probDir=$dataDirectory
    probDir+="/"
    probDir+="$problemToBeSubmitted"
    if [ -d "$probDir" ]; then
        g++ -O2 -w "$fileNameToBeSubmitted"
        echo "//"$rollNo > temp
        cat $fileNameToBeSubmitted >> temp
        cp temp $fileNameToBeSubmitted
        rm temp
        cd $dataDirectory/"$problemToBeSubmitted"/
        for i in *.in
        do
            echo "Running case "$i
            j=`basename $i ".in"`".out"
            k=`basename $i ".in"`".status"
            (timeout 3s ../../a.out < $i > $j || echo "TLE") &> $k
        done
        cd ../..
        rm a.out
    fi
}

#runs the checker file which matches the hash valuse for each cases.
#parameters: problemToBeSubmitted
#returns: none
#entry point: localoj
run_checker()
{
    local probDir=$dataDirectory
    probDir+="/"
    probDir+="$problemToBeSubmitted"
    if [ -d "$probDir" ]; then
        run_special
        cd $dataDirectory/"$problemToBeSubmitted"/
        g++ -O2 -w checker.cpp
        ./a.out
        rm a.out
        cd ../..
    fi
}

#takes the parameters and produces a formatted name for file to save in submissions foloder. Current format: roll_problemname.cpp
#parameters: rollNo, problemToBeSubmitted
#returns: fnameInSubmissionFolder
#entry point: doesn't matter
get_file_name_in_submission_folder()
{
    fnameInSubmissionFolder="submissions/"
    fnameInSubmissionFolder+=$rollNo
    fnameInSubmissionFolder+="_"
    fnameInSubmissionFolder+="$problemToBeSubmitted"
    fnameInSubmissionFolder+=".cpp"
}

#saves the current submitted file in the submission folder maintaing proper format
#parameters: rollNo, problemToBeSubmitted, fileNameToBeSubmitted
#returns: none
#entry point: localoj
save_file_in_submissions_folder()
{
    mkdir -p submissions
    get_file_name_in_submission_folder
    cp "$fileNameToBeSubmitted" "$fnameInSubmissionFolder"
}

#submits a single problem which was the latest submission
#problem is selected via problemToBeSubmitted
#file is chosen via fileNameToBeSubmitted
#parameters: none
#returns: none
#entry point: localoj
quick_submit()
{
    clear
    local probDir=$dataDirectory
    probDir+="/"
    probDir+="$problemToBeSubmitted"
    if [ -d "$probDir" ]; then
        echo "Submitting "$fileNameToBeSubmitted" for Problem "$problemToBeSubmitted
        run_code
        run_checker
        save_file_in_submissions_folder
        press_enter
    fi
}

#submits a single problem
#problem is selected via problem_submission_menu
#file is chosen via file_chooser_menu
#parameters: rollNo
#returns: none
#entry point: localoj
submit_func()
{
    problem_submission_menu
    file_chooser_menu
    clear
    ./vimcat $fileNameToBeSubmitted
    press_enter
    clear
    echo "Submitting "$fileNameToBeSubmitted" for Problem "$problemToBeSubmitted" for Roll No: "$rollNo
    run_code
    run_checker
    save_file_in_submissions_folder
    press_enter
}

#submits all the source codes in submission folder and shows verdict for each problem.
#parameters: rollNo, numberOfProblems, problemNames
#returns: none
#entry point: localoj
submit_all_func()
{
    local i=0
    clear
    for (( i=0; i< $numberOfProblems; i++ ))
    do
        problemToBeSubmitted=${problemNames[$i]} 
        get_file_name_in_submission_folder
        fileNameToBeSubmitted=$fnameInSubmissionFolder
        if [ -f $fileNameToBeSubmitted ]; then
            clear
            echo "Submitting "$fileNameToBeSubmitted" for Problem "$problemToBeSubmitted
            run_code
            run_checker
            press_enter
            ./vimcat $fileNameToBeSubmitted
            press_enter
        fi
    done
    problemToBeSubmitted="####"
}

#shows main menu
#parameters: none
#returns: none
#entry point: localoj
main_menu()
{
    local selection=
    until [ "$selection" = "0" ]; do
        clear
        echo "MENU"
        echo "1 - SUBMIT PROBLEM"
        echo "2 - QUICK SUBMIT"
        echo "3 - SUBMIT ALL"
        echo "4 - SHOW SCORE"
        echo -e "\n0 - EXIT"

        selection=
		while [ -z "$selection" ]; do
			echo -n "Enter your choice: "
			read selection
		done
        case $selection in
            1 ) submit_func;; 
            2 ) quick_submit;;
            3 ) submit_all_func;;
            4 ) clear ; echo "Score not implemented yet" ; press_enter ;;
            0 ) clear ; exit ;;
            * ) clear ; echo "Please press 0, 1, or 2" ; press_enter ;;
        esac
    done
}
welcome
get_problemset_info
main_menu
