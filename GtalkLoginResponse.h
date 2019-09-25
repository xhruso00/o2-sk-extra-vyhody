//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "GPBMessage.h"

@class GtalkErrorInfo, GtalkHeartbeatConfig, NSMutableArray, NSString;

@interface GtalkLoginResponse : GPBMessage
{
}

+ (id)descriptor;

// Remaining properties
@property(retain, nonatomic) GtalkErrorInfo *error; // @dynamic error;
@property(nonatomic) BOOL hasError; // @dynamic hasError;
@property(nonatomic) BOOL hasHeartbeatConfig; // @dynamic hasHeartbeatConfig;
@property(nonatomic) BOOL hasId_p; // @dynamic hasId_p;
@property(nonatomic) BOOL hasJid; // @dynamic hasJid;
@property(nonatomic) BOOL hasLastStreamIdReceived; // @dynamic hasLastStreamIdReceived;
@property(nonatomic) BOOL hasServerTimestamp; // @dynamic hasServerTimestamp;
@property(nonatomic) BOOL hasStreamId; // @dynamic hasStreamId;
@property(retain, nonatomic) GtalkHeartbeatConfig *heartbeatConfig; // @dynamic heartbeatConfig;
@property(copy, nonatomic) NSString *id_p; // @dynamic id_p;
@property(copy, nonatomic) NSString *jid; // @dynamic jid;
@property(nonatomic) int lastStreamIdReceived; // @dynamic lastStreamIdReceived;
@property(nonatomic) long long serverTimestamp; // @dynamic serverTimestamp;
@property(retain, nonatomic) NSMutableArray *settingArray; // @dynamic settingArray;
@property(readonly, nonatomic) unsigned int settingArray_Count; // @dynamic settingArray_Count;
@property(nonatomic) int streamId; // @dynamic streamId;

@end

