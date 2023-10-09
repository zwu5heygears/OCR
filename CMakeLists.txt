project(ppocr CXX C)
cmake_minimum_required(VERSION 3.14)
SET(PADDLE_LIB "/home/heygears/Desktop/ppocr/paddle_inference/") # 绝对路径
set(DEMO_NAME "ppocr")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

include_directories("${PADDLE_LIB}/paddle/include")
link_directories("${PADDLE_LIB}/paddle/lib")
include_directories("${CMAKE_SOURCE_DIR}/")

include_directories("${PADDLE_LIB}/third_party/install/protobuf/include")
include_directories("${PADDLE_LIB}/third_party/install/glog/include")
include_directories("${PADDLE_LIB}/third_party/install/gflags/include")
include_directories("${PADDLE_LIB}/third_party/install/xxhash/include")
include_directories("${PADDLE_LIB}/third_party/install/zlib/include")
include_directories("${PADDLE_LIB}/third_party/install/onnxruntime/include")
include_directories("${PADDLE_LIB}/third_party/install/paddle2onnx/include")
include_directories("${PADDLE_LIB}/third_party/boost")
include_directories("${PADDLE_LIB}/third_party/eigen3")

link_directories("${PADDLE_LIB}/third_party/install/zlib/lib")
link_directories("${PADDLE_LIB}/third_party/install/protobuf/lib")
link_directories("${PADDLE_LIB}/third_party/install/glog/lib")
link_directories("${PADDLE_LIB}/third_party/install/gflags/lib")
link_directories("${PADDLE_LIB}/third_party/install/xxhash/lib")
link_directories("${PADDLE_LIB}/third_party/install/onnxruntime/lib")
link_directories("${PADDLE_LIB}/third_party/install/paddle2onnx/lib")
link_directories("${PADDLE_LIB}/paddle/lib")

set(MATH_LIB ${PADDLE_LIB}/third_party/install/openblas/lib/libopenblas${CMAKE_STATIC_LIBRARY_SUFFIX})

# Note: libpaddle_inference_api.so/a must put before libpaddle_inference.so/a
set(DEPS ${PADDLE_LIB}/paddle/lib/libpaddle_inference${CMAKE_SHARED_LIBRARY_SUFFIX})

set(DEPS ${DEPS}
        ${MATH_LIB} ${MKLDNN_LIB}
        glog gflags protobuf z xxhash
        )

if(EXISTS "${PADDLE_LIB}/third_party/install/snappystream/lib")
    set(DEPS ${DEPS} snappystream)
endif()

if (EXISTS "${PADDLE_LIB}/third_party/install/snappy/lib")
    set(DEPS ${DEPS} snappy)
endif()

set(EXTERNAL_LIB "-ldl -lrt -lgomp -lz -lm -lpthread")
set(DEPS ${DEPS} ${EXTERNAL_LIB})
set(DEPS ${DEPS} ${OpenCV_LIBS})

AUX_SOURCE_DIRECTORY(./src SRCS)
add_executable(${DEMO_NAME} ${SRCS})
target_link_libraries(${DEMO_NAME} ${DEPS})
