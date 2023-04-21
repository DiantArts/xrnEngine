# xrnEngine
Vulkan Game Engine (base code can be found here: https://github.com/DiantArts/VulkanSandbox)

# How to run
Run the following commands to install the dependencies (ubuntu-22.04 example):
```
apt-get install -y python3-pip cppcheck clang-tidy ccache moreutils libxvmc-dev cmake gcovr llvm
```
```
pip install conan ninja
```

Compile and run (but wont do anything because this is a library)
```
./.toolchain/compile
```

Use `-d` to enable debug.
Use `-h` for help.
