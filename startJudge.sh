dataDirectory="data"
declare -a problemNames=
declare -a fileNameList=
numberOfProblems=
problemToBeSubmitted=
fileNameToBeSubmitted=
numberOfFiles=
rollNo=
name=
welcome()
{
	clear
	echo "Welcome to the offline judge 0.0"
	echo "To start please enter your details below"
	echo "You can also read the readme.txt to know more about this judge"
	echo -e "\n\n"
	echo -n "Enter your Roll No: "
	read rollNo
	echo -n "Enter your Name: "
	read name
}
press_enter()
{
    echo -en "\nPress Enter to continue"
    read
    clear
}
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
	press_enter
}
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
	

	echo -n "Enter your choice: "
	read selection
	problemToBeSubmitted=
	if [ "$selection" > "0" ]; then
		if (( selection <= numberOfProblems )); then
			problemToBeSubmitted=${problemNames[$((selection-1))]}
		fi
	fi
	echo "Probem Chosen: "$problemToBeSubmitted
	press_enter
}
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
	echo -n "Enter your choice: "
	read selection
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
run_code()
{
	g++ -O2 "$fileNameToBeSubmitted"
	cd $dataDirectory/"$problemToBeSubmitted"/
	for i in *.in
	do
		echo "Running case "$i
		j=`basename $i ".in"`".out"
		../../a.out < $i > $j
	done
	cd ../..
	rm a.out

}
run_checker()
{
	cd $dataDirectory/"$problemToBeSubmitted"/
	g++ -O2 checker.cpp
	./a.out
	rm a.out
	cd ../..
}
save_file_in_submissions_folder()
{
	mkdir submissions
	fname=$rollNo
	fname+="_"
	fname+="$problemToBeSubmitted"
	fname+=".cpp"
	cp "$fileNameToBeSubmitted" submissions/"$fname"
}
submit_func()
{
	problem_submission_menu
	file_chooser_menu
	clear
	echo "Submitting "$fileNameToBeSubmitted" for Problem "$problemToBeSubmitted
	run_code
	run_checker
	save_file_in_submissions_folder
	press_enter
}
main_menu()
{
	clear
	local selection=
	until [ "$selection" = "0" ]; do
		echo "MENU"
		echo "1 - SUBMIT PROBLEM"
		echo "2 - SHOW SCORE"

		echo -e "\n0 - EXIT"

		echo -n "Enter your choice: "
		read selection
		case $selection in
			1 ) submit_func;; 
			2 ) clear ; echo "Score not implemented yet" ; press_enter ;;
			0 ) clear ; exit ;;
			* ) clear ; echo "Please press 0, 1, or 2" ; press_enter ;;
		esac
	done
}
welcome
get_problemset_info
main_menu
