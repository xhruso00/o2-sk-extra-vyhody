//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "GPBMessage.h"

@class GtalkCellTower;

@interface GtalkHeartbeatAck : GPBMessage
{
}

+ (id)descriptor;

// Remaining properties
@property(retain, nonatomic) GtalkCellTower *cellTower; // @dynamic cellTower;
@property(nonatomic) BOOL hasCellTower; // @dynamic hasCellTower;
@property(nonatomic) BOOL hasIntervalMs; // @dynamic hasIntervalMs;
@property(nonatomic) BOOL hasLastStreamIdReceived; // @dynamic hasLastStreamIdReceived;
@property(nonatomic) BOOL hasStatus; // @dynamic hasStatus;
@property(nonatomic) BOOL hasStreamId; // @dynamic hasStreamId;
@property(nonatomic) int intervalMs; // @dynamic intervalMs;
@property(nonatomic) int lastStreamIdReceived; // @dynamic lastStreamIdReceived;
@property(nonatomic) long long status; // @dynamic status;
@property(nonatomic) int streamId; // @dynamic streamId;

@end
