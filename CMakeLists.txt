
project(fifo)

cmake_minimum_required(VERSION 2.8)

set(abs_dir /boot/opts/)
#set(src_list ./)
aux_source_directory(./ src_list)
include_directories(../../../lib_acl/include)
link_directories(${abs_dir}/acl/lib_acl/lib)

add_executable(fifo ${src_list})

target_link_libraries(fifo _acl.a  pthread)




