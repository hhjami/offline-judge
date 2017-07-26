currentDir=
numberOfCases=
inputDirName="Practice Lab 1"
get_number_of_cases()
{
	j=0;
	for i in *.in
	do
		let "j++"
	done
	numberOfCases=$j
}
convert_dos_2_unix()
{
	for i in *.ans
	do
		tr -d '\r' < $i > tmp
		cp tmp $i
		rm tmp
	done
}
echo -n "Enter the name of the directory(put the name inside double quote): "
read inputDirName

outputDirName="localoj"
outputDirName+=`date +%Y_%m_%d`

mkdir $outputDirName
cp -r "$inputDirName" $outputDirName/data
mv $outputDirName/data/"Problem Descriptions.docx" $outputDirName/"Problem Descriptions.docx"
cd $outputDirName/data/
for i in *
do
	cd "$i"
	cp ../../../genChecker.cpp ./genChecker.cpp
	get_number_of_cases
	convert_dos_2_unix
	echo $numberOfCases
	g++ genChecker.cpp
	./a.out $numberOfCases
	rm a.out
	rm genChecker.cpp
	cd ..
done
cd ../../
cp startJudge.sh $outputDirName/
find $outputDirName -name "solution.cpp" -type f -delete
find $outputDirName -name "*.ans" -type f -delete
