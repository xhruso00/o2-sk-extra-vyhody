//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "GPBMessage.h"

@class NSString;

@interface GtalkCellTower : GPBMessage
{
}

+ (id)descriptor;

// Remaining properties
@property(nonatomic) BOOL hasId_p; // @dynamic hasId_p;
@property(nonatomic) BOOL hasKnownCongestionStatus; // @dynamic hasKnownCongestionStatus;
@property(copy, nonatomic) NSString *id_p; // @dynamic id_p;
@property(nonatomic) int knownCongestionStatus; // @dynamic knownCongestionStatus;

@end

