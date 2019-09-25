//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "GPBMessage.h"

@class GtalkCellTower, GtalkHeartbeatStat, NSMutableArray, NSString;

@interface GtalkLoginRequest : GPBMessage
{
}

+ (id)descriptor;

// Remaining properties
@property(nonatomic) long long accountId; // @dynamic accountId;
@property(nonatomic) int authService; // @dynamic authService;
@property(copy, nonatomic) NSString *authToken; // @dynamic authToken;
@property(retain, nonatomic) GtalkCellTower *cellTower; // @dynamic cellTower;
@property(retain, nonatomic) NSMutableArray *clientEventArray; // @dynamic clientEventArray;
@property(readonly, nonatomic) unsigned int clientEventArray_Count; // @dynamic clientEventArray_Count;
@property(copy, nonatomic) NSString *deviceId; // @dynamic deviceId;
@property(copy, nonatomic) NSString *domain; // @dynamic domain;
@property(nonatomic) unsigned long long gcmStartTimeMs; // @dynamic gcmStartTimeMs;
@property(nonatomic) BOOL hasAccountId; // @dynamic hasAccountId;
@property(nonatomic) BOOL hasAuthService; // @dynamic hasAuthService;
@property(nonatomic) BOOL hasAuthToken; // @dynamic hasAuthToken;
@property(nonatomic) BOOL hasCellTower; // @dynamic hasCellTower;
@property(nonatomic) BOOL hasDeviceId; // @dynamic hasDeviceId;
@property(nonatomic) BOOL hasDomain; // @dynamic hasDomain;
@property(nonatomic) BOOL hasGcmStartTimeMs; // @dynamic hasGcmStartTimeMs;
@property(nonatomic) BOOL hasHeartbeatStat; // @dynamic hasHeartbeatStat;
@property(nonatomic) BOOL hasId_p; // @dynamic hasId_p;
@property(nonatomic) BOOL hasIncludeStreamIds; // @dynamic hasIncludeStreamIds;
@property(nonatomic) BOOL hasLastRmqId; // @dynamic hasLastRmqId;
@property(nonatomic) BOOL hasNetworkType; // @dynamic hasNetworkType;
@property(nonatomic) BOOL hasNoPendingUpstream; // @dynamic hasNoPendingUpstream;
@property(nonatomic) BOOL hasOnFallback; // @dynamic hasOnFallback;
@property(nonatomic) BOOL hasReconnectRequestId; // @dynamic hasReconnectRequestId;
@property(nonatomic) BOOL hasResource; // @dynamic hasResource;
@property(nonatomic) BOOL hasStatus; // @dynamic hasStatus;
@property(nonatomic) BOOL hasTokenVersionInfo; // @dynamic hasTokenVersionInfo;
@property(nonatomic) BOOL hasUseRmq2; // @dynamic hasUseRmq2;
@property(nonatomic) BOOL hasUser; // @dynamic hasUser;
@property(retain, nonatomic) GtalkHeartbeatStat *heartbeatStat; // @dynamic heartbeatStat;
@property(copy, nonatomic) NSString *id_p; // @dynamic id_p;
@property(nonatomic) BOOL includeStreamIds; // @dynamic includeStreamIds;
@property(nonatomic) long long lastRmqId; // @dynamic lastRmqId;
@property(nonatomic) int networkType; // @dynamic networkType;
@property(nonatomic) BOOL noPendingUpstream; // @dynamic noPendingUpstream;
@property(nonatomic) BOOL onFallback; // @dynamic onFallback;
@property(retain, nonatomic) NSMutableArray *receivedPersistentIdArray; // @dynamic receivedPersistentIdArray;
@property(readonly, nonatomic) unsigned int receivedPersistentIdArray_Count; // @dynamic receivedPersistentIdArray_Count;
@property(nonatomic) int reconnectRequestId; // @dynamic reconnectRequestId;
@property(copy, nonatomic) NSString *resource; // @dynamic resource;
@property(retain, nonatomic) NSMutableArray *settingArray; // @dynamic settingArray;
@property(readonly, nonatomic) unsigned int settingArray_Count; // @dynamic settingArray_Count;
@property(nonatomic) long long status; // @dynamic status;
@property(copy, nonatomic) NSString *tokenVersionInfo; // @dynamic tokenVersionInfo;
@property(nonatomic) BOOL useRmq2; // @dynamic useRmq2;
@property(copy, nonatomic) NSString *user; // @dynamic user;

@end
