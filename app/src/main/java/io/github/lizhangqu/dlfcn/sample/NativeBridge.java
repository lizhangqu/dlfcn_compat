package io.github.lizhangqu.dlfcn.sample;

import android.support.annotation.Keep;


@Keep
public class NativeBridge {

    static {
        System.loadLibrary("dlfcn_compat_sample");
    }

    public static native void dlfcnTest();
}
