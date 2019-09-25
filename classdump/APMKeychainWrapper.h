//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface APMKeychainWrapper : NSObject
{
}

+ (id)keychainDataWithIdentifier:(id)arg1 appID:(id)arg2;
+ (id)searchDirectoryForIdentifier:(id)arg1 withAppID:(id)arg2;
+ (void)deleteKeychainValueWithIdentifier:(id)arg1 appID:(id)arg2;
+ (id)keychainValueWithIdentifier:(id)arg1 appID:(id)arg2;
+ (BOOL)upsertKeychainValue:(id)arg1 withIdentifier:(id)arg2 appID:(id)arg3;

@end

