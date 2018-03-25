#ifndef RajaAPI_HH_
#define RajaAPI_HH_

#include "RAJA/RAJA.hpp"

namespace RajaAPI {

#if defined(PENNANT_OPENMP)

  using chunk_policy = RAJA::seq_exec;
  using inner_exec_host = RAJA::seq_exec;
  using inner_reduce_policy = RAJA::omp_reduce;
  using exec_policy = RAJA::omp_parallel_for_exec;
  using reduce_policy = RAJA::omp_reduce;
  using atomic_policy = RAJA::atomic::auto_atomic;

#define RAJA_HOST_DEVICE

#elif defined(PENNANT_CUDA)

#define CUDA_EXEC_BLOCK_SZ 128
#define CUDA_REDUCE_BLOCK_SZ 128

  using reduce_policy = RAJA::seq_reduce;
  using chunk_policy = RAJA::seq_exec;
  using inner_exec_host = RAJA::seq_exec;
  using inner_reduce_policy = RAJA::cuda_reduce<CUDA_REDUCE_BLOCK_SZ>;
  using exec_policy = RAJA::cuda_exec<CUDA_EXEC_BLOCK_SZ>;
  using atomic_policy = RAJA::atomic::cuda_atomic;

#define RAJA_HOST_DEVICE __host__ __device__

#endif

}


#endif /* RajaAPI_HH_ */
