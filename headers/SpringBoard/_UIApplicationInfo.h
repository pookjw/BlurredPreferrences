#import <FrontBoardServices/FBSApplicationInfo.h>

@interface _UIApplicationInfo : FBSApplicationInfo
@property (readonly, nonatomic) int ignoredOverrides;  // (@synthesize ignoredOverrides = _ignoredOverrides;)
@property (readonly, nonatomic) unsigned long viewControllerBasedStatusBarAppearance;  // (@synthesize viewControllerBasedStatusBarAppearance = _viewControllerBasedStatusBarAppearance;)
@property (readonly, nonatomic) BOOL systemWindowsSecure;  // (@synthesize systemWindowsSecure = _systemWindowsSecure;)
@property (readonly, nonatomic) BOOL optOutOfRTL;  // (@synthesize optOutOfRTL = _optOutOfRTL;)
@property (readonly, nonatomic) long whitePointAdaptivityStyle;  // (@synthesize whitePointAdaptivityStyle = _whitePointAdaptivityStyle;)
@property (readonly, nonatomic) BOOL requiresHighResolution;  // (@synthesize requiresHighResolution = _requiresHighResolution;)
@property (readonly, nonatomic) BOOL fakingRequiresHighResolution;  // (@synthesize fakingRequiresHighResolution = _fakingRequiresHighResolution;)
@property (readonly, nonatomic) long requestedStatusBarStyle;  // (@synthesize requestedStatusBarStyle = _requestedStatusBarStyle;)
@property (readonly, nonatomic) BOOL canChangeBackgroundStyle;  // (@synthesize canChangeBackgroundStyle = _canChangeBackgroundStyle;)
@property (readonly, nonatomic) long backgroundStyle;  // (@synthesize backgroundStyle = _backgroundStyle;)
@property (readonly, nonatomic) BOOL statusBarHidden;  // (@synthesize statusBarHidden = _statusBarHidden;)
@property (readonly, nonatomic) BOOL statusBarHiddenWhenVerticallyCompact;  // (@synthesize statusBarHiddenWhenVerticallyCompact = _statusBarHiddenWhenVerticallyCompact;)
@property (readonly, copy, nonatomic) NSString* launchImageFile;  // (@synthesize launchImageFile = _launchImageFile;)
@property (readonly, copy, nonatomic) NSString* keyColorAssetName;  // (@synthesize keyColorAssetName = _keyColorAssetName;)
@property (readonly, nonatomic) long supportedUserInterfaceStyle;  // (@synthesize supportedUserInterfaceStyle = _supportedUserInterfaceStyle;)
@property (readonly, nonatomic) NSArray* folderNames;
@property (readonly, nonatomic) NSString* fallbackFolderName;
+ (id)_genreNameForID:(long)arg1;
+ (id)_localizedFolderNameForName:(id)arg1
- (long)xb_userInterfaceStyleForRequestedUserInterfaceStyle:(long)arg1;
- (BOOL)xb_supportsUserInterfaceStyle:(long)arg1;
- (void)_loadFromProxy:(id)arg1;
- (BOOL)statusBarForcedHiddenForInterfaceOrientation:(long)arg1 onDisplay:(id)arg2 withUserInterfaceIdiom:(long)arg3;
- (BOOL)statusBarHiddenForInterfaceOrientation:(long)arg1 onDisplay:(id)arg2 withUserInterfaceIdiom:(long)arg3;
- (void)_lock_loadFolderNamesIfNecessary;
- (BOOL)statusBarHiddenForInterfaceOrientation:(long)arg1 onDisplay:(id)arg2;
- (BOOL)statusBarForcedHiddenForInterfaceOrientation:(long)arg1 onDisplay:(id)arg2;
- (long)_launchingInterfaceOrientation;
@end
