#import <FrontBoardServices/FBSBundleInfo.h>

@class _FBSCDHashCacheInfo;

@interface FBSApplicationInfo : FBSBundleInfo
@property (readonly, nonatomic) long signatureState;
@property (readonly, nonatomic, getter=hasFreeDeveloperProvisioningProfile) BOOL freeDeveloperProvisioningProfile;
@property (readonly, nonatomic, getter=hasUniversalProvisioningProfile) BOOL universalProvisioningProfile;
@property (readonly, nonatomic) unsigned int signatureVersion;
@property (readonly, nonatomic) BOOL isSignatureVersionSupportEndingSoon;
@property (retain) _FBSCDHashCacheInfo* cachedCDHashInfo;
@property (readonly, copy, nonatomic) NSURL* advertisingAttributionReportEndpoint;  // (@synthesize advertisingAttributionReportEndpoint = _advertisingAttributionReportEndpoint;)
@property (readonly, copy, nonatomic, getter=_appIDEntitlement) NSString* appIDEntitlement;  // (@synthesize appIDEntitlement = _appIDEntitlement;)
@property (nonatomic, getter=_isInstalling, setter=_setInstalling:) BOOL installing;  // (@synthesize installing = _installing;)
@property (nonatomic, getter=_isUninstalling, setter=_setUninstalling:) BOOL uninstalling;  // (@synthesize uninstalling = _uninstalling;)
@property (nonatomic, getter=_isPendingUninstall, setter=_setPendingUninstall:) BOOL pendingUninstall;  // (@synthesize pendingUninstall = _pendingUninstall;)
@property (nonatomic) long interfaceOrientation;  // (@synthesize interfaceOrientation = _interfaceOrientation;)
@property (nonatomic) unsigned long supportedInterfaceOrientations;  // (@synthesize supportedInterfaceOrientations = _supportedInterfaceOrientations;)
@property (readonly, nonatomic, getter=isEnabled) BOOL enabled;  // (@synthesize enabled = _enabled;)
@property (readonly, nonatomic) NSURL* executableURL;  // (@synthesize executableURL = _executableURL;)
@property (readonly, nonatomic) NSURL* bundleContainerURL;  // (@synthesize bundleContainerURL = _bundleContainerURL;)
@property (readonly, nonatomic) NSURL* dataContainerURL;  // (@synthesize dataContainerURL = _dataContainerURL;)
@property (readonly, nonatomic) NSURL* sandboxURL;  // (@synthesize sandboxURL = _sandboxURL;)
@property (readonly, nonatomic) double lastModifiedDate;  // (@synthesize lastModifiedDate = _lastModifiedDate;)
@property (readonly, copy, nonatomic) NSString* preferenceDomain;  // (@synthesize preferenceDomain = _preferenceDomain;)
@property (readonly, nonatomic) NSString* teamIdentifier;  // (@synthesize teamIdentifier = _teamIdentifier;)
@property (readonly, copy, nonatomic) NSString* signerIdentity;  // (@synthesize signerIdentity = _signerIdentity;)
@property (readonly, nonatomic) NSDictionary* environmentVariables;  // (@synthesize environmentVariables = _environmentVariables;)
@property (readonly, nonatomic) NSDictionary* entitlements;
@property (readonly, nonatomic) BOOL hasViewServicesEntitlement;  // (@synthesize hasViewServicesEntitlement = _hasViewServicesEntitlement;)
@property (readonly, nonatomic) NSArray* tags;  // (@synthesize tags = _tags;)
@property (readonly, nonatomic) NSArray* customMachServices;  // (@synthesize customMachServices = _customMachServices;)
@property (readonly, nonatomic) BOOL supportsMultiwindow;  // (@synthesize supportsMultiwindow = _supportsMultiwindow;)
@property (readonly, nonatomic, getter=isProvisioningProfileValidated) BOOL provisioningProfileValidated;  // (@synthesize provisioningProfileValidated = _provisioningProfileValidated;)
@property (readonly, nonatomic, getter=isUPPProvisioningProfileValidated) BOOL UPPProvisioningProfileValidated;  // (@synthesize UPPProvisioningProfileValidated = _uppProvisioningProfileValidated;)
@property (readonly, nonatomic, getter=isFreeDeveloperProvisioningProfileValidated) BOOL freeDeveloperProvisioningProfileValidated;  // (@synthesize freeDeveloperProvisioningProfileValidated = _freeDeveloperProvisioningProfileValidated;)
@property (readonly, nonatomic) unsigned long type;  // (@synthesize type = _type;)
@property (readonly, nonatomic, getter=isRestricted) BOOL restricted;  // (@synthesize restricted = _restricted;)
@property (readonly, nonatomic, getter=isBlocked) BOOL blocked;  // (@synthesize blocked = _blocked;)
@property (readonly, nonatomic) NSArray* requiredCapabilities;  // (@synthesize requiredCapabilities = _requiredCapabilities;)
@property (readonly, nonatomic) NSArray* deviceFamilies;  // (@synthesize deviceFamilies = _deviceFamilies;)
@property (readonly, copy, nonatomic) NSString* sdkVersion;  // (@synthesize sdkVersion = _sdkVersion;)
@property (readonly, nonatomic, getter=isBeta) BOOL beta;  // (@synthesize beta = _beta;)
@property (readonly, copy, nonatomic) NSString* shortVersionString;  // (@synthesize shortVersionString = _shortVersionString;)
@property (readonly, nonatomic, getter=isExitsOnSuspend) BOOL exitsOnSuspend;
@property (readonly, nonatomic) BOOL requiresPersistentWiFi;  // (@synthesize requiresPersistentWiFi = _requiresPersistentWiFi;)
@property (readonly, nonatomic) float minimumBrightnessLevel;  // (@synthesize minimumBrightnessLevel = _minimumBrightnessLevel;)
@property (readonly, nonatomic) NSArray* externalAccessoryProtocols;  // (@synthesize externalAccessoryProtocols = _externalAccessoryProtocols;)
@property (readonly, nonatomic) long screenTimePolicy;  // (@synthesize screenTimePolicy = _screenTimePolicy;)
@property (readonly, nonatomic, getter=isBlockedForScreenTimeExpiration) BOOL blockedForScreenTimeExpiration;
@property (readonly, nonatomic) long ratingRank;  // (@synthesize ratingRank = _ratingRank;)
@property (readonly, nonatomic) NSNumber* itemID;  // (@synthesize itemID = _itemID;)
@property (readonly, nonatomic) NSNumber* purchaserDSID;  // (@synthesize purchaserDSID = _purchaserDSID;)
@property (readonly, nonatomic) NSNumber* downloaderDSID;  // (@synthesize downloaderDSID = _downloaderDSID;)
@property (readonly, nonatomic) NSArray* folderNames;  // (@synthesize folderNames = _folderNames;)
@property (readonly, nonatomic) NSString* fallbackFolderName;  // (@synthesize fallbackFolderName = _fallbackFolderName;)
+ (unsigned long)_applicationTypeForProxy:(id)arg1;
+ (id)_configureEnvironment:(id)arg1 withInfo:(id)arg2 isPreApex:(BOOL)arg3;
- (id)_signatureValidationService;
- (long)_mapSignatureStateFromTrustState:(unsigned long)arg1;
- (id)_initForProfileManagerTesting;
- (void)_loadFromProxy:(id)arg1;
- (id)initWithApplicationProxy:(id)arg1;
- (id)succinctDescriptionBuilder;
- (void)_synchronize:(id)arg1; // block
- (id)_initWithApplicationProxy:(id)arg1;
- (id)_initWithApplicationProxy:(id)arg1 overrideURL:(id)arg2;
- (id)_initWithBundleProxy:(id)arg1 overrideURL:(id)arg2;
- (BOOL)builtOnOrAfterSDKVersion:(id)arg1;
- (id)_initWithBundleIdentifier:(id)arg1 url:(id)arg2;
- (BOOL)supportsBackgroundMode:(id)arg1;
- (BOOL)supportsInterfaceOrientation:(long)arg1;
- (void)_overrideTags:(id)arg1;
- (BOOL)supportsAllInterfaceOrientations;
- (void)_setInstalling:(BOOL)arg1;
- (BOOL)_isUninstalling;
- (void)_setUninstalling:(BOOL)arg1;
- (BOOL)_isPendingUninstall;
- (void)_setPendingUninstall:(BOOL)arg1;
- (unsigned long)unauthoritativeTrustState;
- (id)descriptionBuilderWithMultilinePrefix:(id)arg1;
@end
