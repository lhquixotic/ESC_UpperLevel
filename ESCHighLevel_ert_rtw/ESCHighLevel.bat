
set MATLAB=C:\Software\Matlab2021b

cd .

if "%1"=="" ("C:\Software\MATLAB~1\bin\win64\gmake"  -f ESCHighLevel.mk all) else ("C:\Software\MATLAB~1\bin\win64\gmake"  -f ESCHighLevel.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1