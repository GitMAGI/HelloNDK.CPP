LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := hello-ndk
LOCAL_SRC_DIR := src
LOCAL_SRC_FILES := $(wildcard $(LOCAL_SRC_DIR)/*.cpp) $(wildcard $(LOCAL_SRC_DIR)/custom/*.cpp)
LOCAL_C_INCLUDES := $(LOCAL_SRC_DIR) $(LOCAL_SRC_DIR)/custom
LOCAL_LDLIBS :=

include $(BUILD_EXECUTABLE)