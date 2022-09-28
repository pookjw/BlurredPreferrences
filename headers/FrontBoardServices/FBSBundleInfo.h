#import <Foundation/Foundation.h>

@interface FBSBundleInfo : NSObject
@property (readonly, copy, nonatomic) NSString* bundleIdentifier;  // (@synthesize bundleIdentifier = _bundleIdentifier;)
@property (readonly, nonatomic) NSURL* bundleURL;  // (@synthesize bundleURL = _bundleURL;)
@property (readonly, copy, nonatomic) NSString* displayName;  // (@synthesize displayName = _displayName;)
@property (readonly, copy, nonatomic) NSString* bundleVersion;  // (@synthesize bundleVersion = _bundleVersion;)
@property (readonly, copy, nonatomic) NSString* bundleType;  // (@synthesize bundleType = _bundleType;)
@property (readonly, nonatomic) unsigned long sequenceNumber;  // (@synthesize sequenceNumber = _sequenceNumber;)
@property (readonly, copy, nonatomic) NSUUID* cacheGUID;  // (@synthesize cacheGUID = _cacheGUID;)
- (id)_initWithBundleProxy:(id)arg1 overrideURL:(id)arg2;
- (id)_initWithBundleIdentifier:(id)arg1 url:(id)arg2;
- (id)descriptionWithMultilinePrefix:(id)arg1;
- (id)descriptionBuilderWithMultilinePrefix:(id)arg1;
- (id)_initWithBundleProxy:(id)arg1 bundleIdentifier:(id)arg2 url:(id)arg3;
@end
