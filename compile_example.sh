g++ example.cpp src/cpp/vector.cpp src/cpp/serial_func.cpp -o example_serial.out

nvcc example.cpp src/cuda/vector.cu src/cuda/parallel_func.cu -o example_parallel.out