@echo off

cd Tests
if not exist TestBuildRes mkdir TestBuildRes
(
del /q "TestBuildRes\*"
FOR /D %%p IN ("TestBuildRes\*.*") DO rmdir "%%p" /s /q
)
cd TestBuildRes
cmake -G "Visual Studio 14 2015" ..
if not defined DevEnvDir (
  call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat"
)
msbuild SlidingPuzzleTest.sln /p:Configuration=Debug
Debug\RunAllTests.exe
cd ..
cd ..
