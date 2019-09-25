//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "GPBMessage.h"

@class GtalkErrorInfo, GtalkExtension, NSString;

@interface GtalkIqStanza : GPBMessage
{
}

+ (id)descriptor;

// Remaining properties
@property(nonatomic) long long accountId; // @dynamic accountId;
@property(retain, nonatomic) GtalkErrorInfo *error; // @dynamic error;
@property(retain, nonatomic) GtalkExtension *extension; // @dynamic extension;
@property(copy, nonatomic) NSString *from; // @dynamic from;
@property(nonatomic) BOOL hasAccountId; // @dynamic hasAccountId;
@property(nonatomic) BOOL hasError; // @dynamic hasError;
@property(nonatomic) BOOL hasExtension; // @dynamic hasExtension;
@property(nonatomic) BOOL hasFrom; // @dynamic hasFrom;
@property(nonatomic) BOOL hasId_p; // @dynamic hasId_p;
@property(nonatomic) BOOL hasLastStreamIdReceived; // @dynamic hasLastStreamIdReceived;
@property(nonatomic) BOOL hasPersistentId; // @dynamic hasPersistentId;
@property(nonatomic) BOOL hasRmqId; // @dynamic hasRmqId;
@property(nonatomic) BOOL hasStatus; // @dynamic hasStatus;
@property(nonatomic) BOOL hasStreamId; // @dynamic hasStreamId;
@property(nonatomic) BOOL hasTo; // @dynamic hasTo;
@property(nonatomic) BOOL hasType; // @dynamic hasType;
@property(copy, nonatomic) NSString *id_p; // @dynamic id_p;
@property(nonatomic) int lastStreamIdReceived; // @dynamic lastStreamIdReceived;
@property(copy, nonatomic) NSString *persistentId; // @dynamic persistentId;
@property(nonatomic) long long rmqId; // @dynamic rmqId;
@property(nonatomic) long long status; // @dynamic status;
@property(nonatomic) int streamId; // @dynamic streamId;
@property(copy, nonatomic) NSString *to; // @dynamic to;
@property(nonatomic) int type; // @dynamic type;

@end

