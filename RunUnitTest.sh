cd Tests

if [ -d "TestBuildRes" ]; then
    rm -rf TestBuildRes
fi
mkdir TestBuildRes
cd TestBuildRes
cmake ..
make
./RunAllTests
cd ..
cd ..
