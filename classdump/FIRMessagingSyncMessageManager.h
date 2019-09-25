//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class FIRMessagingRmqManager;

@interface FIRMessagingSyncMessageManager : NSObject
{
    FIRMessagingRmqManager *_rmqManager;
}

+ (long long)expirationTimeForSyncMessage:(id)arg1;
@property(retain, nonatomic) FIRMessagingRmqManager *rmqManager; // @synthesize rmqManager=_rmqManager;
- (void).cxx_destruct;
- (BOOL)didReceiveSyncMessage:(id)arg1 viaAPNS:(BOOL)arg2 viaMCS:(BOOL)arg3;
- (BOOL)didReceiveMCSSyncMessage:(id)arg1;
- (BOOL)didReceiveAPNSSyncMessage:(id)arg1;
- (void)removeExpiredSyncMessages;
- (id)initWithRmqManager:(id)arg1;
- (id)init;

@end

