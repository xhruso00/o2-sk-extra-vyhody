//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "GPBMessage.h"

@class NSString;

@interface GtalkStreamErrorStanza : GPBMessage
{
}

+ (id)descriptor;

// Remaining properties
@property(nonatomic) BOOL hasText; // @dynamic hasText;
@property(nonatomic) BOOL hasType; // @dynamic hasType;
@property(copy, nonatomic) NSString *text; // @dynamic text;
@property(copy, nonatomic) NSString *type; // @dynamic type;

@end
