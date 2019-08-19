CC = g++

BUILD_DIR = bin
SRC_DIR = jni/src

TARGET = hello-ndk.exe

MKDIR_P_BUILD = if not exist "$(BUILD_DIR)" mkdir $(BUILD_DIR)

CINCLUDE = -I.\$(SRC_DIR)\ -I.\$(SRC_DIR)\custom -I\msys64\mingw64\include
CLIBS = -L\msys64\mingw64\lib 

SOURCES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/custom/*.cpp)

$(TARGET): $(SOURCES)
	$(shell $(MKDIR_P_BUILD))
	$(CC) -o $(BUILD_DIR)/$@ $(CINCLUDE) $^ $(CLIBS)	