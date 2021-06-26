package com.zxj.parcel;

import android.os.Parcel;
import android.os.Parcelable;

/**
 * @Author zuojie
 * @Date 2021/6/19
 */
public class Student implements Parcelable {
    public String name;
    public int age;

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeString(this.name);
        dest.writeInt(this.age);
    }

    public void readFromParcel(Parcel source) {
        this.name = source.readString();
        this.age = source.readInt();
    }

    public Student() {
    }

    protected Student(Parcel in) {
        this.name = in.readString();
        this.age = in.readInt();
    }

    public static final Creator<Student> CREATOR = new Creator<Student>() {
        @Override
        public Student createFromParcel(Parcel source) {
            return new Student(source);
        }

        @Override
        public Student[] newArray(int size) {
            return new Student[size];
        }
    };
}
