g++ -O2 solve.cpp

for /l %%x in (0, 1, 5) do (
	a.exe < %%x.in > %%x.ans
)
pause