//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class FABIcon, NSDictionary;

@interface FABAppIconUtility : NSObject
{
    FABIcon *_applicationIcon;
}

+ (id)iconNameSetWithAlternateNamesAddedToIconNameSet:(id)arg1;
+ (void)addIconNameWithModifier:(id)arg1 forIconWithName:(id)arg2 toSetOfIconNames:(id)arg3;
+ (BOOL)isIconImageFileNameExtensionPresentInName:(id)arg1;
+ (struct CGSize)sizeForImage:(id)arg1;
@property(retain, nonatomic) FABIcon *applicationIcon; // @synthesize applicationIcon=_applicationIcon;
- (void).cxx_destruct;
- (id)fetchApplicationIcon;
- (id)iconByFallingBackOnDefaultIconNamingConvention;
- (id)iconFromCFBundleIconFile;
- (id)iconFromCFBundleIconFiles;
- (id)iconFromIOS7StyleCFBundleIconsInFieldWithKey:(id)arg1;
- (id)largestIconInIconNames:(id)arg1 prerendered:(BOOL)arg2;
- (id)iconRootPath;
@property(readonly, nonatomic) NSDictionary *appInfoDictionary;

@end

