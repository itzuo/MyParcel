package com.zxj.parcel

/**
 *
 * @Author zuojie
 * @Date 2021/6/19
 */
class MyParcel {
    private var mNativePtr: Long = 0

    init {
        System.loadLibrary("native-lib")
        mNativePtr = nativeCreate();
    }


    fun writeInt(value: Int) {
        nativeWriteInt(mNativePtr,value)
    }

    fun readInt() = nativeReadInt(mNativePtr)

    fun setDataPosition(position : Int) = nativeSetDataPosition(mNativePtr,position)
    /*fun setDataPosition(position : Int){
        nativeSetDataPosition(mNativePtr,position)
    }*/

    fun writeChar(value:Char){
        nativeWriteChar(mNativePtr,value)
    }

    fun readChar():Char{
        return nativeReadChar(mNativePtr)
    }

    fun writeString(str:String){
        nativeWriteString(mNativePtr,str)
    }

    fun readString():String{
        return nativeReadString(mNativePtr);
    }

    private external fun nativeCreate(): Long

    private external fun nativeWriteInt(mNativePtr: Long, value: Int)

    private external fun nativeReadInt(mNativePtr: Long):Int

    private external fun nativeWriteChar(mNativePtr: Long,value :Char)

    private external fun nativeReadChar(mNativePtr:Long):Char

    private external fun nativeSetDataPosition(mNativePtr: Long, position: Int)
    private external fun nativeWriteString(mNativePtr: Long, str: String)
    private external fun nativeReadString(mNativePtr: Long):String
}
