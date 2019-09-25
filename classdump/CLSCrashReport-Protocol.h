//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSDate, NSDictionary, NSString;

@protocol CLSCrashReport <NSObject>
@property(readonly, copy, nonatomic) NSString *OSBuildVersion;
@property(readonly, copy, nonatomic) NSString *OSVersion;
@property(readonly, nonatomic) NSDate *crashedOnDate;
@property(readonly, copy, nonatomic) NSString *bundleShortVersionString;
@property(readonly, copy, nonatomic) NSString *bundleVersion;
@property(readonly, copy, nonatomic) NSDictionary *customKeys;
@property(readonly, copy, nonatomic) NSString *identifier;
@end

