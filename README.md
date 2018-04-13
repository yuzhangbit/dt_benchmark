# dt_benchmark
The codes have been tested in Ubuntu 16.04.  
## Dependencies
* OpenCV >= 2.4.9 
* Google benchmark >= 1.4.0
* GTest 
 
##  Install & Build & Benchmark
* Install the dependencies.
  ```bash
  git clone https://github.com/yuzhangbit/dt_benchmark.git
  cd dt_benchmark
  bash script/install.bash # install dependencies 
  ```

* Build the codes
  ```bash
  mkdir build && cd build 
  cmake .. 
  make 
  ```
* Benchmark
  ```bash
  ./dt_benchmark --benchmark_out=dt_benchmark.json
  ```



