#import <Foundation/Foundation.h>
#import <libhooker/libhooker.h>
#import <SpringBoard/SBApplicationInfo.h>

static NSString * const preferencesBundleIdentifier = @"com.apple.Preferences";

static NSUInteger (*original_SBApplicationInfo_backgroundStyle)(SBApplicationInfo *self, SEL selector);
static NSUInteger custom_SBApplicationInfo_backgroundStyle(SBApplicationInfo *self, SEL selector) {
    if ([self.bundleIdentifier isEqualToString:preferencesBundleIdentifier]) {
        return 4; // like com.apple.mobilesafari
    } else {
        return original_SBApplicationInfo_backgroundStyle(self, selector);
    }
}

static BOOL (*original_SBApplicationInfo_canChangeBackgroundStyle)(SBApplicationInfo *self, SEL selector);
static BOOL custom_SBApplicationInfo_canChangeBackgroundStyle(SBApplicationInfo *self, SEL selector) {
    if ([self.bundleIdentifier isEqualToString:preferencesBundleIdentifier]) {
        return YES; // like com.apple.mobilesafari
    } else {
        return original_SBApplicationInfo_canChangeBackgroundStyle(self, selector);
    }
}

static long (*original_SBApplicationInfo_supportedUserInterfaceStyle)(SBApplicationInfo *self, SEL selector);
static long custom_SBApplicationInfo_supportedUserInterfaceStyle(SBApplicationInfo *self, SEL selector) {
    if ([self.bundleIdentifier isEqualToString:preferencesBundleIdentifier]) {
        return 2;
    } else {
        return original_SBApplicationInfo_supportedUserInterfaceStyle(self, selector);
    }
}

__attribute__((constructor)) static void init() {
    LBHookMessage(NSClassFromString(@"SBApplicationInfo"), @selector(backgroundStyle), &custom_SBApplicationInfo_backgroundStyle, &original_SBApplicationInfo_backgroundStyle);
    LBHookMessage(NSClassFromString(@"SBApplicationInfo"), @selector(canChangeBackgroundStyle), &custom_SBApplicationInfo_canChangeBackgroundStyle, &original_SBApplicationInfo_canChangeBackgroundStyle);
    LBHookMessage(NSClassFromString(@"SBApplicationInfo"), @selector(supportedUserInterfaceStyle), &custom_SBApplicationInfo_supportedUserInterfaceStyle, &original_SBApplicationInfo_supportedUserInterfaceStyle);
}
