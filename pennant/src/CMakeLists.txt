################################
# PENNANT
################################

set (pennant_sources
  ExportGold.cc  
  HydroBC.cc  
  InputFile.cc  
  Mesh.cc      
  PolyGas.cc   
  WriteXY.cc
  CudaAPI.cc  
  TTS.cc
  Driver.cc   
  GenMesh.cc     
  Hydro.cc    
  main.cc       
  Parallel.cc  
  QCS.cc)

set (pennant_depends
  RAJA)

if (ENABLE_OPENMP)
  set (pennant_depends
    ${pennant_depends}
    openmp)
endif ()

if (ENABLE_CUDA)
  set (pennant_depends
    ${pennant_depends}
    cuda)
endif ()

#blt_add_executable(
#  NAME pennant-RAJA-seq.exe
#  SOURCES ${pennant_sources}
#  DEPENDS_ON ${pennant_depends})
#
#target_compile_options(
#  pennant-RAJA-seq.exe
#  PRIVATE
#  -Wno-unknown-pragmas)

if (ENABLE_OPENMP)

  blt_add_executable(
    NAME pennant-RAJA-omp.exe
    SOURCES ${pennant_sources}
    DEPENDS_ON ${pennant_depends})

  target_compile_definitions(
    pennant-RAJA-omp.exe
    PRIVATE
    -DPENNANT_OPENMP=1
    )

endif ()

if (ENABLE_CUDA)

  configure_file(ExportGold.cc  
    ${CMAKE_CURRENT_BINARY_DIR}/ExportGold-cuda.cc COPYONLY)
  configure_file(HydroBC.cc  
    ${CMAKE_CURRENT_BINARY_DIR}/HydroBC-cuda.cc COPYONLY)
  configure_file(InputFile.cc  
    ${CMAKE_CURRENT_BINARY_DIR}/InputFile-cuda.cc COPYONLY)
  configure_file(Mesh.cc      
    ${CMAKE_CURRENT_BINARY_DIR}/Mesh-cuda.cc COPYONLY)
  configure_file(PolyGas.cc   
    ${CMAKE_CURRENT_BINARY_DIR}/PolyGas-cuda.cc COPYONLY)
  configure_file(WriteXY.cc
    ${CMAKE_CURRENT_BINARY_DIR}/WriteXY-cuda.cc COPYONLY)
  configure_file(CudaAPI.cc  
    ${CMAKE_CURRENT_BINARY_DIR}/CudaAPI-cuda.cc COPYONLY)
  configure_file(TTS.cc
    ${CMAKE_CURRENT_BINARY_DIR}/TTS-cuda.cc COPYONLY)
  configure_file(Driver.cc   
    ${CMAKE_CURRENT_BINARY_DIR}/Driver-cuda.cc COPYONLY)
  configure_file(GenMesh.cc     
    ${CMAKE_CURRENT_BINARY_DIR}/GenMesh-cuda.cc COPYONLY)
  configure_file(Hydro.cc    
    ${CMAKE_CURRENT_BINARY_DIR}/Hydro-cuda.cc COPYONLY)
  configure_file(main.cc       
    ${CMAKE_CURRENT_BINARY_DIR}/main-cuda.cc COPYONLY)
  configure_file(Parallel.cc  
    ${CMAKE_CURRENT_BINARY_DIR}/Parallel-cuda.cc COPYONLY)
  configure_file(QCS.cc
    ${CMAKE_CURRENT_BINARY_DIR}/QCS-cuda.cc COPYONLY)

  blt_add_executable(
    NAME pennant-RAJA-cuda.exe
    SOURCES 
    ${CMAKE_CURRENT_BINARY_DIR}/ExportGold-cuda.cc
    ${CMAKE_CURRENT_BINARY_DIR}/HydroBC-cuda.cc 
    ${CMAKE_CURRENT_BINARY_DIR}/InputFile-cuda.cc
    ${CMAKE_CURRENT_BINARY_DIR}/Mesh-cuda.cc 
    ${CMAKE_CURRENT_BINARY_DIR}/PolyGas-cuda.cc 
    ${CMAKE_CURRENT_BINARY_DIR}/WriteXY-cuda.cc 
    ${CMAKE_CURRENT_BINARY_DIR}/CudaAPI-cuda.cc 
    ${CMAKE_CURRENT_BINARY_DIR}/TTS-cuda.cc 
    ${CMAKE_CURRENT_BINARY_DIR}/Driver-cuda.cc 
    ${CMAKE_CURRENT_BINARY_DIR}/GenMesh-cuda.cc 
    ${CMAKE_CURRENT_BINARY_DIR}/Hydro-cuda.cc 
    ${CMAKE_CURRENT_BINARY_DIR}/main-cuda.cc 
    ${CMAKE_CURRENT_BINARY_DIR}/Parallel-cuda.cc 
    ${CMAKE_CURRENT_BINARY_DIR}/QCS-cuda.cc 

    DEPENDS_ON ${pennant_depends})

  target_compile_definitions(
    pennant-RAJA-cuda.exe
    PRIVATE
    -DPENNANT_CUDA=1
    )

  target_include_directories(
    pennant-RAJA-cuda.exe
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR})

endif ()
