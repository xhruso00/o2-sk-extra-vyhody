//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSDictionary, NSString, UIApplication;

@interface ANSApplication : NSObject
{
    NSDictionary *_infoPlistDict;
}

+ (id)hostApplication;
@property(readonly, nonatomic) NSDictionary *infoPlistDict; // @synthesize infoPlistDict=_infoPlistDict;
- (void).cxx_destruct;
@property(readonly, nonatomic) UIApplication *appSharedInstance;
@property(readonly, nonatomic) BOOL isExtension;
@property(readonly, nonatomic) NSString *extensionPointIdentifier;
@property(readonly, nonatomic) NSDictionary *extensionDefinitionDictionary;
@property(readonly, nonatomic) NSString *shortVersionString;
@property(readonly, nonatomic) NSString *bundleVersion;
@property(readonly, nonatomic) NSString *bundleIdentifier;
- (id)initWithInfoPlistDictionary:(id)arg1;

@end

