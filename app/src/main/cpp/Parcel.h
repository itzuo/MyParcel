//
// Created by 左杰 on 2021/6/19.
//

#include <malloc.h>
#include <memory.h>

#ifndef MYPARCEL_PARCEL_H

#define MYPARCEL_PARCEL_H

#include <android/log.h>

#define TAG "zuojie"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG,  __VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG,  __VA_ARGS__);
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG,  __VA_ARGS__);

class Parcel {
private:
    char* mData;// char 1 共享内存的首地址
    int mDataPos = 0; // Parcel对象共享内存的首地址(内存地址)的指针地址挪动位置
public:
    Parcel();
    ~Parcel();
    void writeInt(int value);
    int readInt();
    void writeChar(char value);
    char readChar();
    void setDataPosition(int position);
    int writeString16(const char16_t * str,int len);
    const char16_t * readString16Inplace();

    int writeInt32(int len);

    int finisWrite(size_t len);

    uint8_t* writeInplace(size_t len);

    int32_t readInt32();

    const void* readInplace(size_t len);
};


#endif //MYPARCEL_PARCEL_H
