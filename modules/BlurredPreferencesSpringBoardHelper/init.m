#import <UIKit/UIKit.h>
#import <substrate.h>
#import <SpringBoard/SBApplicationInfo.h>

@interface SBApplication : NSObject
@property (readonly, copy, nonatomic) NSString* bundleIdentifier; // (@synthesize bundleIdentifier = _bundleIdentifier;)
- (id)bundleIdentifier;
@end

@interface SBApplicationSceneHandle : NSObject
@property (readonly, nonatomic) SBApplication* application; // (@synthesize application = _application;)
@end

@interface SBDeviceApplicationSceneHandle : SBApplicationSceneHandle
@property (readonly, nonatomic, getter=isTranslucent) BOOL translucent;
@property (readonly, nonatomic) long backgroundStyle;
- (BOOL)isTranslucent;
- (long)backgroundStyle;
@end

//

static NSString * const preferencesBundleIdentifier = @"com.apple.Preferences";

BOOL (*original_SBDeviceApplicationSceneHandle_isTranslucent)(SBDeviceApplicationSceneHandle *self, SEL selector);
BOOL custom_SBDeviceApplicationSceneHandle_isTranslucent(SBDeviceApplicationSceneHandle *self, SEL selector) {
    if ([self.application.bundleIdentifier isEqualToString:preferencesBundleIdentifier]) {
        return YES;
    } else {
        return original_SBDeviceApplicationSceneHandle_isTranslucent(self, selector);
    } 
}

long (*original_SBDeviceApplicationSceneHandle_backgroundStyle)(SBDeviceApplicationSceneHandle *self, SEL selector);
long custom_SBDeviceApplicationSceneHandle_backgroundStyle(SBDeviceApplicationSceneHandle *self, SEL selector) {
    if ([self.application.bundleIdentifier isEqualToString:preferencesBundleIdentifier]) {
        return 2; // or 4
        // TODO: backgroundStyle references FBScene at cbz instruction.
    } else {
        return original_SBDeviceApplicationSceneHandle_backgroundStyle(self, selector);
    } 
}

__attribute__((constructor)) static void init() {
    @autoreleasepool {
        MSHookMessageEx(NSClassFromString(@"SBDeviceApplicationSceneHandle"), @selector(isTranslucent), (IMP)&custom_SBDeviceApplicationSceneHandle_isTranslucent, (IMP *)&original_SBDeviceApplicationSceneHandle_isTranslucent);
         MSHookMessageEx(NSClassFromString(@"SBDeviceApplicationSceneHandle"), @selector(backgroundStyle), (IMP)&custom_SBDeviceApplicationSceneHandle_backgroundStyle, (IMP *)&original_SBDeviceApplicationSceneHandle_backgroundStyle);
    }
}
