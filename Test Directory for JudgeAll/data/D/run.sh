g++ solution.cpp
for i in *.in
do
    j=$(basename "$i" .in)".ans"
    ./a.out < $i > $j
done
rm a.out
