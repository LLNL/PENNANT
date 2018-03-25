FLAGS = -O3 -std=c++11
CUDA_FLAGS = --expt-extended-lambda -arch sm_60 -x cu -DPENNANT_CUDA
OPENMP_FLAGS = -DPENNANT_OPENMP
RAJA_INC = -I../../opt/include
RAJA_LIB = -I../../opt/lib
LD_FLAGS = -lRAJA

all:
	nvcc $(FLAGS) $(CUDA_FLAGS) $(RAJA_INC) $(RAJA_LIB) $(LDFLAGS) src/*.cc -o build/pennant

#SRC = $(wildcard src/*.cc)
#SRC_CLEAN = $(subst src/,,$(SRC))
#OBJS += $(patsubst %.cc, build/%.o, $(SRC_CLEAN))
#
#pennant: $(OBJS)
#	g++ $(FLAGS) $(OPENMP_FLAGS) $(RAJA_INC) $(RAJA_LIB) $(LDFLAGS) $(OBJS) -o pennant
#
#build/%.o: src/%.cc Makefile
#	g++ $(FLAGS) $(OPENMP_FLAGS) $(RAJA_INC) -c $< -o $@

clean:
	rm -rf pennant build/*
