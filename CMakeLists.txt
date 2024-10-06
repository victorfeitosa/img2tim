cmake_minimum_required(VERSION 3.21)

project(
	img2tim
	LANGUAGES    CXX
	VERSION      1.0.0
	DESCRIPTION  "Converts images to PSX TIM image format"
	HOMEPAGE_URL "https://github.com/victorfeitosa/Ikuzo-Toolset"
)
find_package(PkgConfig REQUIRED)

file(GLOB img2tim_src "*.cpp" )
add_executable(img2tim ${img2tim_src})

target_include_directories(img2tim PUBLIC "./")
target_include_directories(img2tim PUBLIC "./vendor/freeimage")

find_library(FREEIMAGE freeimage "./vendor/freeimage")
target_link_libraries(img2tim PUBLIC m)
target_link_libraries(img2tim PUBLIC ${FREEIMAGE})

install(TARGETS img2tim)

