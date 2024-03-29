//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "GPBMessage.h"

@class GtalkErrorInfo, NSMutableArray, NSString;

@interface GtalkMessageStanza : GPBMessage
{
}

+ (id)descriptor;

// Remaining properties
@property(nonatomic) long long accountId; // @dynamic accountId;
@property(copy, nonatomic) NSString *body; // @dynamic body;
@property(retain, nonatomic) GtalkErrorInfo *error; // @dynamic error;
@property(retain, nonatomic) NSMutableArray *extensionArray; // @dynamic extensionArray;
@property(readonly, nonatomic) unsigned int extensionArray_Count; // @dynamic extensionArray_Count;
@property(copy, nonatomic) NSString *from; // @dynamic from;
@property(nonatomic) BOOL hasAccountId; // @dynamic hasAccountId;
@property(nonatomic) BOOL hasBody; // @dynamic hasBody;
@property(nonatomic) BOOL hasError; // @dynamic hasError;
@property(nonatomic) BOOL hasFrom; // @dynamic hasFrom;
@property(nonatomic) BOOL hasId_p; // @dynamic hasId_p;
@property(nonatomic) BOOL hasLastStreamIdReceived; // @dynamic hasLastStreamIdReceived;
@property(nonatomic) BOOL hasNosave; // @dynamic hasNosave;
@property(nonatomic) BOOL hasPersistentId; // @dynamic hasPersistentId;
@property(nonatomic) BOOL hasRead; // @dynamic hasRead;
@property(nonatomic) BOOL hasRmqId; // @dynamic hasRmqId;
@property(nonatomic) BOOL hasStreamId; // @dynamic hasStreamId;
@property(nonatomic) BOOL hasSubject; // @dynamic hasSubject;
@property(nonatomic) BOOL hasThread; // @dynamic hasThread;
@property(nonatomic) BOOL hasTimestamp; // @dynamic hasTimestamp;
@property(nonatomic) BOOL hasTo; // @dynamic hasTo;
@property(nonatomic) BOOL hasType; // @dynamic hasType;
@property(copy, nonatomic) NSString *id_p; // @dynamic id_p;
@property(nonatomic) int lastStreamIdReceived; // @dynamic lastStreamIdReceived;
@property(nonatomic) BOOL nosave; // @dynamic nosave;
@property(copy, nonatomic) NSString *persistentId; // @dynamic persistentId;
@property(nonatomic) BOOL read; // @dynamic read;
@property(nonatomic) long long rmqId; // @dynamic rmqId;
@property(nonatomic) int streamId; // @dynamic streamId;
@property(copy, nonatomic) NSString *subject; // @dynamic subject;
@property(copy, nonatomic) NSString *thread; // @dynamic thread;
@property(nonatomic) long long timestamp; // @dynamic timestamp;
@property(copy, nonatomic) NSString *to; // @dynamic to;
@property(nonatomic) int type; // @dynamic type;

@end

