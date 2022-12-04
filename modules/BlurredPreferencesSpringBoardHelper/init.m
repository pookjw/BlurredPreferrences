#import <UIKit/UIKit.h>
#import <substrate.h>

@interface FBSSceneSettings : NSObject
@end

@interface UIApplicationSceneSettings : NSObject
@property (readonly, nonatomic) long userInterfaceStyle;
@end

@interface FBScene : NSObject
@property (readonly, nonatomic) FBSSceneSettings* settings; // (@synthesize settings = _settings;)
@end

@interface SBApplication : NSObject
@property (readonly, copy, nonatomic) NSString* bundleIdentifier; // (@synthesize bundleIdentifier = _bundleIdentifier;)
@end

@interface SBSceneHandle : NSObject
@property (readonly, nonatomic) FBScene* sceneIfExists; // (@synthesize sceneIfExists = _scene;)
- (void)_didUpdateSettingsWithDiff:(id)arg1 previousSettings:(id)arg2;
@end

@interface SBApplicationSceneHandle : SBSceneHandle
@property (readonly, nonatomic) SBApplication* application; // (@synthesize application = _application;)
@end

@interface SBDeviceApplicationSceneHandle : SBApplicationSceneHandle
@property (readonly, nonatomic, getter=isTranslucent) BOOL translucent;
@property (readonly, nonatomic) long backgroundStyle;
@property (readonly, nonatomic) long wallpaperStyle;
@end

@interface SBApplicationSceneBackgroundView : UIView
@property (nonatomic) long wallpaperStyle; // (@synthesize wallpaperStyle = _wallpaperStyle;)
@end

@interface SBSceneView : UIView
@end

@interface SBApplicationSceneView : SBSceneView
@property (readonly, nonatomic) SBApplicationSceneHandle* sceneHandle; // (@dynamic sceneHandle;)
@property (readonly, nonatomic) SBApplication* application;
@end

@interface SBDeviceApplicationSceneView : SBApplicationSceneView
@property (retain, nonatomic) SBApplicationSceneBackgroundView* backgroundView; // (@dynamic backgroundView;)
- (void)_sceneHandleDidUpdateClientSettingsWithDiff:(id)arg1 previousSettings:(id)arg2;
@end

//

static NSString * const kPreferencesBundleIdentifier = @"com.apple.Preferences";

long (*original_SBDeviceApplicationSceneHandle_backgroundStyle)(SBDeviceApplicationSceneHandle *self, SEL selector);
long custom_SBDeviceApplicationSceneHandle_backgroundStyle(SBDeviceApplicationSceneHandle *self, SEL selector) {
    if ([self.application.bundleIdentifier isEqualToString:kPreferencesBundleIdentifier]) {
        id settings = self.sceneIfExists.settings;
        if (![settings isKindOfClass:NSClassFromString(@"UIApplicationSceneSettings")]) {
            return original_SBDeviceApplicationSceneHandle_backgroundStyle(self, selector); 
        }

        long userInterfaceStyle = ((UIApplicationSceneSettings *)settings).userInterfaceStyle;

        // UIBackgroundStyleDarkBlur, UIBackgroundStyleUltraLightBlur, UIBackgroundStyleDefault
        if (userInterfaceStyle == 1) {
            return 2; // UIBackgroundStyleUltraLightBlur
        } else if (userInterfaceStyle == 2) {
            return 4; // UIBackgroundStyleDarkBlur
        } else {
            return original_SBDeviceApplicationSceneHandle_backgroundStyle(self, selector); 
        }
    } else {
        return original_SBDeviceApplicationSceneHandle_backgroundStyle(self, selector);
    } 
}

BOOL (*original_SBDeviceApplicationSceneHandle_isTranslucent)(SBDeviceApplicationSceneHandle *self, SEL selector);
BOOL custom_SBDeviceApplicationSceneHandle_isTranslucent(SBDeviceApplicationSceneHandle *self, SEL selector) {
    if ([self.application.bundleIdentifier isEqualToString:kPreferencesBundleIdentifier]) {
        return YES;
    } else {
        return original_SBDeviceApplicationSceneHandle_isTranslucent(self, selector);
    } 
}

void (*original_SBDeviceApplicationSceneView_sceneHandleDidUpdateSettingsWithDiff_previousSettings)(SBDeviceApplicationSceneView *self, SEL selector, id diff, id previous);
void custom_SBDeviceApplicationSceneView_sceneHandleDidUpdateSettingsWithDiff_previousSettings(SBDeviceApplicationSceneView *self, SEL selector, id diff, id previous) {
    original_SBDeviceApplicationSceneView_sceneHandleDidUpdateSettingsWithDiff_previousSettings(self, selector, diff, previous);
    if ([self.application.bundleIdentifier isEqualToString:kPreferencesBundleIdentifier]) {
        id sceneHandle = self.sceneHandle;
        if (![sceneHandle isKindOfClass:NSClassFromString(@"SBDeviceApplicationSceneHandle")]) return;
        self.backgroundView.wallpaperStyle = ((SBDeviceApplicationSceneHandle *)sceneHandle).wallpaperStyle;
    }
}

__attribute__((constructor)) static void init() {
    @autoreleasepool {
        MSHookMessageEx(NSClassFromString(@"SBDeviceApplicationSceneHandle"), @selector(backgroundStyle), (IMP)&custom_SBDeviceApplicationSceneHandle_backgroundStyle, (IMP *)&original_SBDeviceApplicationSceneHandle_backgroundStyle);
        MSHookMessageEx(NSClassFromString(@"SBDeviceApplicationSceneHandle"), @selector(isTranslucent), (IMP)&custom_SBDeviceApplicationSceneHandle_isTranslucent, (IMP *)&original_SBDeviceApplicationSceneHandle_isTranslucent);
        MSHookMessageEx(NSClassFromString(@"SBDeviceApplicationSceneView"), @selector(_sceneHandleDidUpdateSettingsWithDiff:previousSettings:), (IMP)custom_SBDeviceApplicationSceneView_sceneHandleDidUpdateSettingsWithDiff_previousSettings, (IMP *)&original_SBDeviceApplicationSceneView_sceneHandleDidUpdateSettingsWithDiff_previousSettings);
    }
}
