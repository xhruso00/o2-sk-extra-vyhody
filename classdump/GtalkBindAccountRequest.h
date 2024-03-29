//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "GPBMessage.h"

@class NSString;

@interface GtalkBindAccountRequest : GPBMessage
{
}

+ (id)descriptor;

// Remaining properties
@property(nonatomic) long long accountId; // @dynamic accountId;
@property(copy, nonatomic) NSString *authToken; // @dynamic authToken;
@property(copy, nonatomic) NSString *domain; // @dynamic domain;
@property(nonatomic) BOOL hasAccountId; // @dynamic hasAccountId;
@property(nonatomic) BOOL hasAuthToken; // @dynamic hasAuthToken;
@property(nonatomic) BOOL hasDomain; // @dynamic hasDomain;
@property(nonatomic) BOOL hasId_p; // @dynamic hasId_p;
@property(nonatomic) BOOL hasLastStreamIdReceived; // @dynamic hasLastStreamIdReceived;
@property(nonatomic) BOOL hasPersistentId; // @dynamic hasPersistentId;
@property(nonatomic) BOOL hasResource; // @dynamic hasResource;
@property(nonatomic) BOOL hasStreamId; // @dynamic hasStreamId;
@property(nonatomic) BOOL hasUser; // @dynamic hasUser;
@property(copy, nonatomic) NSString *id_p; // @dynamic id_p;
@property(nonatomic) int lastStreamIdReceived; // @dynamic lastStreamIdReceived;
@property(copy, nonatomic) NSString *persistentId; // @dynamic persistentId;
@property(copy, nonatomic) NSString *resource; // @dynamic resource;
@property(nonatomic) int streamId; // @dynamic streamId;
@property(copy, nonatomic) NSString *user; // @dynamic user;

@end

