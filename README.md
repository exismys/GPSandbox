## Setup glfw

sudo apt install libglfw3-dev libgl1-mesa-dev

## Build

```bash
mkdir build && cd build
cmake ..
make
cd ..
./build/bin/sim
```

## Third-Party Libraries

This project uses the following libraries:

- **GLM**
- **GLAD** 
- **stb_image**
- **Khronos headers**