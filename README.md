# TorchScriptTutorial
Trying out TorchScript to import a neural network model from Python to C++. 

This tutorial can be found at https://pytorch.org/tutorials/advanced/cpp_export.html

To run,

1. Run the Export_Model.ipynb file in a jupyter notebook to create the resnet18.pt file

2. Get CMake using brew. This can be done by going into Terminal and installing homebrew

		$ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"

Then installing cmake

		$ brew install cmake

3. Download libtorch C++/Java version at https://pytorch.org/get-started/locally/ and unzipping it.

4. Modify the CMakeLists.txt file and change the file path to direct it to the newly downloaded libtorch folder

5. In the this tutorial folder, make and cd into a "build folder"

		$ mkdir build
  
		$ cd build

6. Build and compile the program

		$ cmake ..
  
		$ make

7. You can now run the program with the command

		$ ./torch-demo ../resnet18.pt



