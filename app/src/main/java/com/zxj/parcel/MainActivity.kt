package com.zxj.parcel

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.TextView
import com.zxj.parcel.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        Log.e("zuojie", "==onCreate==")
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        var parcel = MyParcel()
        parcel.writeInt(23)
        parcel.writeInt(100)
        parcel.writeChar('Z')
//        parcel.writeString("zuoxijie")
        parcel.writeString("zhangSan")
//        parcel.writeInt(34)
        Log.e("zuojie", "==write data over==" )

        parcel.setDataPosition(0)

        Log.e("zuojie", "==readInt111==" + parcel.readInt())
        Log.e("zuojie", "==readInt222==" + parcel.readInt())

        Log.e("zuojie", "==readChar==" + parcel.readChar())
        Log.e("zuojie", "==readString==" + parcel.readString())
//        Log.e("zuojie", "==readString==" + parcel.readString())
//        Log.e("zuojie", "==readInt333==" + parcel.readInt())


    }


    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            Log.e("zuojie", "==companion object init==")
            System.loadLibrary("native-lib")
        }
    }

    init {
        Log.e("zuojie", "==init==")
    }
}