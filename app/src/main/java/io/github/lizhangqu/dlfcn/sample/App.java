package io.github.lizhangqu.dlfcn.sample;

import android.app.Application;
import android.content.Context;

import com.tencent.bugly.crashreport.CrashReport;


public class App extends Application {

    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);

    }

    @Override
    public void onCreate() {
        super.onCreate();

//        CrashReport.UserStrategy strategy = new CrashReport.UserStrategy(getApplicationContext());
//        strategy.setEnableANRCrashMonitor(true);
//        strategy.setEnableNativeCrashMonitor(true);
//        strategy.setBuglyLogUpload(true);
//        CrashReport.initCrashReport(getApplicationContext(), "865e103a10", false, strategy);

    }
}
