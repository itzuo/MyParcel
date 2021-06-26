//
// Created by 左杰 on 2021/6/19.
//

#include <cstdlib>
#include "Parcel.h"

Parcel::Parcel() {
    this->mData = static_cast<char *>(malloc(1024));
}

Parcel::~Parcel() {
    LOGE("Parcel的析构函数调用了")
    if(this->mData){
        free(this->mData);
        this->mData = NULL;
    }
}

void Parcel::writeInt(int value) {
    * reinterpret_cast<int *>(this->mData + this->mDataPos) = value;
    mDataPos += sizeof(int);
}

int Parcel::readInt() {
    int result = *reinterpret_cast<int *>(this->mData + this->mDataPos);
    mDataPos += sizeof(int);
    return result;
}

void Parcel::setDataPosition(int position) {
    this->mDataPos = position;
}

void Parcel::writeChar(char value) {
    LOGE("Parcel-> value= %d",value);
    *(this->mData + this->mDataPos) = value;
    mDataPos += sizeof(char);
}

char Parcel::readChar() {
    char result = *(this->mData + this->mDataPos);
    mDataPos += sizeof(char);
    return result;
}

int Parcel::writeString16(const char16_t *str, int len) {
    if (str == NULL) return -1;

    writeInt32(len);

    len *= sizeof(char16_t);

    LOGE("[len *= sizeof(char16_t)] = %d",len)

    uint8_t * data = writeInplace(len +sizeof(char16_t));

    LOGE("mDataPos = %d,len=%d,str=%s",mDataPos,len,str)
    if (data) {
        memcpy(data, str, len);
        LOGE("data=%s",data);
        * reinterpret_cast<char16_t*>(data + len) = 0;//可以不要
        return 0;
    }
    return -1;
}

const char16_t* Parcel::readString16Inplace() {
    int32_t size = readInt32();
    LOGE("readString16Inplace=>size=%d , [(size+1)*sizeof(char16_t )]=%d",size,(size+1)*sizeof(char16_t ))
    const char16_t* str = (const char16_t*)readInplace((size+1)*sizeof(char16_t ));
    return str;
}

int Parcel::writeInt32(int32_t len) {
    //存字符串的长度值
    * reinterpret_cast<int32_t *>(mData + mDataPos) = len;
    LOGE("writeInt32=>mDataPos=%d, 把字符串的长度len=%d存储首位",mDataPos,* reinterpret_cast<int *>(mData + mDataPos));
    return finisWrite(sizeof(len));
}

int Parcel::finisWrite(size_t len) {
    mDataPos +=len;
    LOGE("finisWrite=>sizeof(len)=%d,mDataPos=%d",len,mDataPos);
    return 0;
}

uint8_t *Parcel::writeInplace(size_t len) {
    uint8_t* data = reinterpret_cast<uint8_t *>(mData + mDataPos);
    LOGE("writeInplace=>mDataPos=%d 获取[len*sizeof(char16_t) +sizeof(char16_t)]=%d的值%d",mDataPos,len ,*data);
    finisWrite(len);
    return data;
}

int32_t Parcel::readInt32() {
    //取出字符串的长度值
    const  void* data = mData + mDataPos;
    LOGE("start readInt32=>mDataPos=%d",mDataPos)
//    mDataPos +=sizeof(int32_t);
    finisWrite(sizeof(int32_t));
    LOGE("end readInt32=>mDataPos=%d,data=%d",mDataPos,data)
    int32_t pArg = *reinterpret_cast<const int32_t*>(data);
    return pArg;
}

const void* Parcel::readInplace(size_t len) {
    const void* data = mData + mDataPos;
//    mDataPos += len;
    finisWrite(len);
    return data;
}

