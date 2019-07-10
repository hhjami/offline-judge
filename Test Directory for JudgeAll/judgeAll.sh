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
        ./a.out >> "../../allSubmissionVerdicts.txt"
        rm a.out
        cd ../..
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
    #./vimcat $fileNameToBeSubmitted
    echo "Submitting Problem "$problemToBeSubmitted" for Roll No: "$rollNo >> "allSubmissionVerdicts.txt"
    run_code
    run_checker
    echo "End of Submission" >> "allSubmissionVerdicts.txt"
}
#shows main menu
#parameters: none
#returns: none
#entry point: localoj
main_menu()
{
    > "allSubmissionVerdicts.txt"
    for sub in submissions/*
    do
        cp "$sub" currentSub.cpp
        fileNameToBeSubmitted="currentSub.cpp"
        g++ fileNameToRollAndProblemNameExtractor.cpp
        ./a.out "$sub" > currentSubmissionInfo.txt
        rollNo=$(sed -n 1p "currentSubmissionInfo.txt")
        problemToBeSubmitted=$(sed -n 2p "currentSubmissionInfo.txt")
        echo $rollNo
        echo $problemToBeSubmitted
        echo "$sub"
        submit_func
    done
    g++ generateEvaluation.cpp
    ./a.out
}
main_menu
