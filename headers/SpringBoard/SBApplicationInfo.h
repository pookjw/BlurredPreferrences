#import <SpringBoard/_UIApplicationInfo.h>

@interface SBApplicationInfo : _UIApplicationInfo
@property (readonly, nonatomic) BOOL supportsDirectToAirplayOrIsAllowListed;
@property (readonly, nonatomic, getter=isSystemApplication) BOOL systemApplication;
@property (readonly, nonatomic, getter=isInternalApplication) BOOL internalApplication;
@property (readonly, nonatomic, getter=isAppleApplication) BOOL appleApplication;
@property (readonly, nonatomic, getter=isArcadeApplication) BOOL arcadeApplication;  // (@synthesize arcadeApplication = _arcadeApplication;)
@property (readonly, nonatomic, getter=isAppClip) BOOL appClip;  // (@synthesize appClip = _appClip;)
@property (readonly, copy, nonatomic) NSString* displayName;  // (@synthesize displayName = _displayName;)
@property (readonly, nonatomic, getter=isMonarchLinked) BOOL monarchLinked;  // (@synthesize monarchLinked = _isMonarchLinked;)
@property (readonly, nonatomic, getter=isTigrisLinked) BOOL tigrisLinked;  // (@synthesize tigrisLinked = _isTigrisLinked;)
@property (readonly, nonatomic, getter=isPeaceLinked) BOOL peaceLinked;  // (@synthesize peaceLinked = _isPeaceLinked;)
@property (readonly, nonatomic, getter=isPeaceBLinked) BOOL peaceBLinked;  // (@synthesize peaceBLinked = _isPeaceBLinked;)
@property (readonly, nonatomic, getter=isYukonLinked) BOOL yukonLinked;  // (@synthesize yukonLinked = _isYukonLinked;)
@property (readonly, nonatomic, getter=isYukonELinked) BOOL yukonELinked;  // (@synthesize yukonELinked = _isYukonELinked;)
@property (readonly, nonatomic, getter=isAzulLinked) BOOL azulLinked;  // (@synthesize azulLinked = _isAzulLinked;)
@property (readonly, nonatomic, getter=isAzulHWLinked) BOOL azulHWLinked;  // (@synthesize azulHWLinked = _isAzulHWLinked;)
@property (readonly, nonatomic, getter=isAzulBLinked) BOOL azulBLinked;  // (@synthesize azulBLinked = _isAzulBLinked;)
@property (readonly, nonatomic) unsigned long supportedTypes;  // (@synthesize supportedTypes = _supportedTypes;)
@property (readonly, nonatomic) NSSet* urlSchemes;  // (@synthesize urlSchemes = _urlSchemes;)
@property (readonly, nonatomic) NSURL* restorationArchiveContainerURL;  // (@synthesize restorationArchiveContainerURL = _restorationArchiveContainerURL;)
@property (readonly, nonatomic) NSString* installInstanceID;  // (@synthesize installInstanceID = _installInstanceID;)
@property (readonly, nonatomic) BOOL representsWebApplication;  // (@synthesize representsWebApplication = _representsWebApplication;)
@property (readonly, nonatomic) BOOL supports64Bit;  // (@synthesize supports64Bit = _supports64Bit;)
@property (readonly, nonatomic) BOOL supportsMultiwindow;  // (@synthesize supportsMultiwindow = _supportsMultiwindow;)
@property (readonly, nonatomic, getter=isNewsstand) BOOL newsstand;  // (@synthesize newsstand = _isNewsstand;)
@property (readonly, nonatomic) unsigned long applicationSizeInBytes;  // (@synthesize applicationSizeInBytes = _applicationSizeInBytes;)
@property (readonly, copy, nonatomic) NSArray* iTunesCategoriesOrderedByRelevancy;  // (@synthesize iTunesCategoriesOrderedByRelevancy = _iTunesCategoriesOrderedByRelevancy;)
@property (readonly, nonatomic) unsigned long visibilityOverride;  // (@synthesize visibilityOverride = _visibilityOverride;)
@property (readonly, nonatomic) BOOL hasHiddenTag;  // (@synthesize hasHiddenTag = _hasHiddenTag;)
@property (readonly, nonatomic) BOOL usesRLNDataProvider;  // (@synthesize usesRLNDataProvider = _usesRLNDataProvider;)
@property (readonly, nonatomic) BOOL systemAppSupportsLocalNotifications;  // (@synthesize systemAppSupportsLocalNotifications = _systemAppSupportsLocalNotifications;)
@property (readonly, nonatomic) BOOL suppressUserNotificationPermissionAlert;
@property (readonly, nonatomic) unsigned long allowedNKNotificationsPerDay;  // (@synthesize allowedNKNotificationsPerDay = _allowedNKNotificationsPerDay;)
@property (readonly, nonatomic, getter=isStatusBarLegacy) BOOL statusBarIsLegacy;  // (@synthesize statusBarIsLegacy = _statusBarIsLegacy;)
@property (readonly, nonatomic) long defaultStatusBarStyle;  // (@synthesize defaultStatusBarStyle = _defaultStatusBarStyle;)
@property (readonly, nonatomic) int ignoredStatusBarStyleOverrides;  // (@synthesize ignoredStatusBarStyleOverrides = _ignoredStatusBarStyleOverrides;)
@property (readonly, nonatomic) BOOL shouldLaunchSuspendedAlways;  // (@synthesize shouldLaunchSuspendedAlways = _alwaysLaunchesSuspended;)
@property (readonly, nonatomic) NSArray* domainsToPreheat;  // (@synthesize domainsToPreheat = _domainsToPreheat;)
@property (readonly, nonatomic, getter=isLaunchableDuringSetup) BOOL launchableDuringSetup;  // (@synthesize launchableDuringSetup = _isLaunchableDuringSetup;)
@property (readonly, nonatomic) BOOL shouldLaunchWithLiveContentASAP;  // (@synthesize shouldLaunchWithLiveContentASAP = _shouldLaunchWithLiveContentASAP;)
@property (readonly, nonatomic) XBSnapshotContainerIdentity* manifestContainerIdentity;  // (@synthesize manifestContainerIdentity = _manifestContainerIdentity;)
@property (readonly, nonatomic) BOOL usesSplashBoard;  // (@synthesize usesSplashBoard = _usesSplashBoard;)
@property (readonly, nonatomic) BOOL wantsLaunchWithoutPNG;  // (@synthesize wantsLaunchWithoutPNG = _wantsLaunchWithoutPNG;)
@property (readonly, nonatomic) BOOL wantsFullScreen;  // (@synthesize wantsFullScreen = _wantsFullScreen;)
@property (readonly, nonatomic) BOOL prefersSavedSnapshots;  // (@synthesize prefersSavedSnapshots = _prefersSavedSnapshots;)
@property (readonly, nonatomic) BOOL preventsLaunchInterfaceSplitting;  // (@synthesize preventsLaunchInterfaceSplitting = _preventsLaunchInterfaceSplitting;)
@property (readonly, nonatomic) BOOL disablesClassicMode;  // (@synthesize disablesClassicMode = _disablesClassicMode;)
@property (readonly, nonatomic) NSString* launchInterfaceFileName;  // (@synthesize launchInterfaceFileName = _launchInterfaceFileName;)
@property (readonly, nonatomic) NSArray* launchImageInfo;  // (@synthesize launchImageInfo = _launchImageInfo;)
@property (readonly, nonatomic) long whitePointAdaptivityStyle;  // (@synthesize whitePointAdaptivityStyle = _whitePointAdaptivityStyle;)
@property (readonly, nonatomic) BOOL requiresHiDPI;  // (@synthesize requiresHiDPI = _requiresHiDPI;)
@property (readonly, nonatomic) BOOL disallowsNotificationCenter;  // (@synthesize disallowsNotificationCenter = _disallowsNotificationCenter;)
@property (readonly, nonatomic) BOOL disallowsControlCenter;  // (@synthesize disallowsControlCenter = _disallowsControlCenter;)
@property (readonly, nonatomic) Class iconClass;  // (@synthesize iconClass = _iconClass;)
@property (readonly, copy, nonatomic) NSString* applicationShortcutWidgetBundleIdentifier;  // (@synthesize applicationShortcutWidgetBundleIdentifier = _applicationShortcutWidgetBundleIdentifier;)
@property (readonly, nonatomic) NSArray* staticApplicationShortcutItems;
@property (readonly, nonatomic) unsigned long dynamicApplicationShortcutItemsVersion;  // (@synthesize dynamicApplicationShortcutItemsVersion = _dynamicApplicationShortcutItemsVersion;)
@property (readonly, nonatomic) unsigned long uninstallCapability;  // (@synthesize uninstallCapability = _uninstallCapability;)
@property (readonly, nonatomic) int networkUsageTypes;  // (@synthesize networkUsageTypes = _networkUsageTypes;)
@property (readonly, nonatomic) unsigned long voipClass;  // (@synthesize voipClass = _voipClass;)
@property (readonly, nonatomic) BOOL supportsLegacyVOIPBackgroundMode;
@property (readonly, nonatomic) BOOL supportsAudioBackgroundMode;
@property (readonly, nonatomic) BOOL supportsFetchBackgroundMode;
@property (readonly, nonatomic) BOOL supportsRemoteNotificationBackgroundMode;
@property (readonly, nonatomic) BOOL supportsNewsstandContentBackgroundMode;
@property (readonly, nonatomic) CRCarPlayAppDeclaration* carPlayDeclaration;  // (@synthesize carPlayDeclaration = _carPlayDeclaration;)
@property (readonly, nonatomic, getter=isGameCenterEnabled) BOOL gameCenterEnabled;  // (@synthesize gameCenterEnabled = _isGameCenterEnabled;)
@property (readonly, nonatomic) BOOL wasGameCenterEverEnabled;  // (@synthesize wasGameCenterEverEnabled = _wasGameCenterEverEnabled;)
@property (readonly, nonatomic, getter=isCloudDemoted) BOOL cloudDemoted;  // (@synthesize cloudDemoted = _cloudDemoted;)
@property (readonly, nonatomic) BOOL wantsExclusiveForeground;  // (@synthesize wantsExclusiveForeground = _wantsExclusiveForeground;)
@property (readonly, nonatomic) BOOL shouldSkipCrossfadeToLive;  // (@synthesize shouldSkipCrossfadeToLive = _shouldSkipCrossfadeToLive;)
@property (readonly, nonatomic) NSURL* documentInboxURL;  // (@synthesize documentInboxURL = _documentInboxURL;)
@property (readonly, nonatomic) NSUserDefaults* userDefaults;
@property (readonly, nonatomic) BOOL supportsDirectToAirplay;  // (@synthesize supportsDirectToAirplay = _supportsDirectToAirplay;)
@property (readonly, nonatomic) BOOL alwaysReceivesOpenURLSource;  // (@synthesize alwaysReceivesOpenURLSource = _alwaysReceivesOpenURLSource;)
@property (readonly, nonatomic) BOOL alwaysDeliversOpenURLActionsUsingWorkspace;  // (@synthesize alwaysDeliversOpenURLActionsUsingWorkspace = _alwaysDeliversOpenURLActionsUsingWorkspace;)
@property (readonly, copy, nonatomic) NSString* vendorName;  // (@synthesize vendorName = _vendorName;)
@property (readonly, nonatomic, getter=isLicensedToDevice) BOOL licensedToDevice;  // (@synthesize licensedToDevice = _isLicensedToDevice;)  
+ (id)_directToAirPlayBundleIDs;
- (void)_loadFromProxy:(id)arg1;
- (id)dataContainerURL;
- (long)backgroundStyleForRequestedBackgroundStyle:(long)arg1;
- (long)backgroundStyle;
- (BOOL)alwaysDeliversOpenURLActionsUsingWorkspace;
- (BOOL)canChangeBackgroundStyle;
- (BOOL)statusBarHiddenWhenVerticallyCompact;
- (BOOL)isSignatureVersionValid;
@end
