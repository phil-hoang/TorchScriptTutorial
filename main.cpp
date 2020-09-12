#include <iostream>
#include <memory>
#include <torch/script.h>

int main(int argc, const char* argv[]) {
    if (argc != 2){
        std::cerr << "Error in inputs\n";
        return -1;
    }

    // Import the scriptmodule from pytorch
    // Note: this part is different from that of the tutorial
    torch::jit::script::Module module;
    try {
        module = torch::jit::load(argv[1]);
    }
    catch (const c10::Error& e) {
        std::cerr << "error loading the model\n";
        return -1;
    }

    std::cout << "Import success!\n";
    
    // Create a vector of inputs
    std::vector<torch::jit::IValue> inputs;
    inputs.push_back(torch::ones({1,3,224,224}));

    // Execute model and print out output as a tensor
    at::Tensor output = module.forward(inputs).toTensor();
    std::cout << output.slice(1,0,5) << '\n';
}