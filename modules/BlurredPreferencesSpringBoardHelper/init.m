#import <UIKit/UIKit.h>
#import <substrate.h>
#import <SpringBoard/SBApplicationInfo.h>

static NSString * const preferencesBundleIdentifier = @"com.apple.Preferences";

long (*original_SBApplicationInfo_backgroundStyleForRequestedBackgroundStyle)(SBApplicationInfo *self, SEL selector, long arg1);
long custom_SBApplicationInfo_backgroundStyleForRequestedBackgroundStyle(SBApplicationInfo *self, SEL selector, long arg1) {
    if ([self.bundleIdentifier isEqualToString:preferencesBundleIdentifier]) {
        return 2; // like com.apple.mobilesafari
    } else {
        return original_SBApplicationInfo_backgroundStyleForRequestedBackgroundStyle(self, selector, arg1);
    } 
}

__attribute__((constructor)) static void init() {
    @autoreleasepool {
        MSHookMessageEx(NSClassFromString(@"SBApplicationInfo"), @selector(backgroundStyleForRequestedBackgroundStyle:), (IMP)&custom_SBApplicationInfo_backgroundStyleForRequestedBackgroundStyle, (IMP *)&original_SBApplicationInfo_backgroundStyleForRequestedBackgroundStyle);
    }
}
